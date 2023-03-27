#!/bin/bash -eux
set -o pipefail

display=99

wxhxd=${WxHxD:-800x600x24}
bin=${BIN:-./bin/voidstar}
file=${FILE:-"$bin"}
out=video.${OUT:-webm}

case "$file" in
  http://*|https://*)
    curl -fsSLo /file "$file"
    file=/file
;;*) ;;
esac

step=1024
filesize=$(stat --printf=%s "$file")
[[ "$filesize" -ge 9999999999 ]] && ((step*=2))
[[ "$filesize" -ge  999999999 ]] && ((step*=2))
[[ "$filesize" -ge   99999999 ]] && ((step*=2))
[[ "$filesize" -ge    9999999 ]] && ((step*=2))
[[ "$filesize" -ge     999999 ]] && ((step*=2))

rm -rf /tmp/xvfb-run.*

xvfb-run \
  --server-num="$display" \
  --error-file=/dev/stdout \
  -s "-screen 0 $wxhxd" \
  "$bin" \
    --move \
    --exit-at-fin \
    --slide-step "$step" \
    "$file" &
xvfb=$!

touch ~/.Xauthority
attempts=0
until ls /tmp/xvfb*/Xauthority >/dev/null; do
    set +o errexit
    xauth generate :0 . trusted
    failed=$?
    set +o errexit
    xauth list
    ((attempts++))
    [[ $attempts -eq 20 ]] && exit 2
    [[ $failed -ne 0 ]] && sleep .1
done

touch stop
case "$out" in
  *.webm)
    <./stop \
      XAUTHORITY=$(echo /tmp/xvfb*/Xauthority) \
        ffmpeg \
          -r 30 \
          -f x11grab \
          -draw_mouse 0 \
          -s "$(cut -dx -f1-2 <<<"$wxhxd")" \
          -i :"$display" \
          -c:v libvpx \
          -quality realtime \
          -cpu-used 0 \
          -b:v 384k \
          -qmin 10 \
          -qmax 42 \
          -maxrate 384k \
          -bufsize 1000k \
          -an \
          "$out" &
    companion=$!
    ;;
  *.mp4)
      # WRT -pix_fmt yuv420p https://bugzilla.mozilla.org/show_bug.cgi?id=1368063#c7
    <./stop \
      XAUTHORITY=$(echo /tmp/xvfb*/Xauthority) \
        ffmpeg \
          -r 24  \
          -f x11grab \
          -draw_mouse 0 \
          -s "$(cut -dx -f1-2 <<<"$wxhxd")" \
          -i :"$display" \
          -c:v libx264 \
          -b:v 64k \
          -crf 36 \
          -preset veryslow \
          -tune zerolatency \
          -pix_fmt yuv420p \
          -an \
          "$out" &
    companion=$!
    ;;
  *)
    echo "Unhandled video format for $out"
    exit 1
esac

wait $xvfb
echo q >stop # https://stackoverflow.com/a/21032143/1418165
wait $companion

max_seconds=60
# Must be shorter than $max_seconds
duration=$(ffprobe -v error -show_format -show_streams -i "$out" | grep 'duration=' | head -n 1 | sed 's%duration=%%')
if [[ "$(echo "$duration < $max_seconds" | bc)" = 0 ]]; then
    ffmpeg \
        -i "$out" \
        -filter:v "setpts=PTS/$(echo "1 + $duration / $max_seconds" | bc)" \
        /tmp/"$out"
    mv -v /tmp/"$out" "$out"
fi

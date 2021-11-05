#!/bin/bash -eux
set -o pipefail

# _kill_procs() {
#   kill -TERM $companion
#   wait $companion
#   kill -TERM $xvfb
# }
# trap _kill_procs SIGTERM

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

rm -rf /tmp/xvfb-run.*

xvfb-run \
  --server-num="$display" \
  --error-file=/dev/stdout \
  -s "-screen 0 $wxhxd" \
  "$bin" \
    --move \
    --exit-at-fin \
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
    <./stop \
      XAUTHORITY=$(echo /tmp/xvfb*/Xauthority) \
        ffmpeg \
          -r 30  \
          -f x11grab \
          -draw_mouse 0 \
          -s "$(cut -dx -f1-2 <<<"$wxhxd")" \
          -i :"$display" \
          -c:v libx265 \
          -g 1 \
          -preset ultrafast \
          -tune zerolatency \
          -x265-params lossless=1 \
          -vtag hvc1 \
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

case "$out" in
  *.mp4)
    mv "$out" input
    ffmpeg -y -i input -c:v libx265 -b:v 2600k -x265-params pass=1 -an -f null /dev/null
    ffmpeg -i input -c:v libx265 -b:v 2600k -x265-params pass=2 -an "$out"
    ;;
  *)
esac

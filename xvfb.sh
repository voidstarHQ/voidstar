#!/bin/bash -eux
set -o pipefail

_kill_procs() {
  kill -TERM $companion
  wait $companion
  kill -TERM $xvfb
}
trap _kill_procs SIGTERM

display=99

wxhxd=${WxHxD:-800x600x24}
bin=${BIN:-./bin/voidstar}
file=${FILE:-"$bin"}
out=${OUT:-video.webm}

case "$file" in
  http://*|https://*)
    curl -fsSLo /file "$file"
    file=/file
    # ls -lh "$file"; exit 42
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
xauth generate :0 . trusted || true
xauth list

ls /tmp/xvfb*/Xauthority >/dev/null

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
    -an "$out" &
companion=$!

wait $xvfb
kill -TERM $companion
wait $companion || true

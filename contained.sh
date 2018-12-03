#!/bin/bash

# https://stackoverflow.com/a/25168483/1418165

XSOCK=/tmp/.X11-unix
XAUTH=/tmp/.docker.xauth
xauth nlist :0 | sed -e 's/^..../ffff/' | xauth -f $XAUTH nmerge -

docker run --rm -it \
       -v $XSOCK:$XSOCK \
       -v $XAUTH:$XAUTH \
       -v /dev/input \
       -e XAUTHORITY=$XAUTH \
       void \
       /app/build/voidstar \
       /app/build/voidstar

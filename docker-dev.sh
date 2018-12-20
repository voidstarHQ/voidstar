#!/bin/bash

#$ docker build -f Dockerfile.dev -t voiddev .

# https://stackoverflow.com/a/25168483/1418165

XSOCK=/tmp/.X11-unix
XAUTH=/tmp/.docker.xauth
xauth nlist :0 | sed -e 's/^..../ffff/' | xauth -f $XAUTH nmerge -

docker run --rm -it \
       -v $XSOCK:$XSOCK \
       -v $XAUTH:$XAUTH \
       -v /dev/input \
       -v "$PWD":/app \
       -e XAUTHORITY=$XAUTH \
       voiddev

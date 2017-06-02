# VoidStar [![TravisCI build status](https://travis-ci.org/fenollp/voidstar.svg?branch=master)](https://travis-ci.org/fenollp/voidstar/builds)

Browse data using Corti's 2D projector as well as 3D variants.

[![Sorry for potato quality](https://i.vimeocdn.com/video/622736893.webp?mw=480&mh=270)](https://player.vimeo.com/video/207613754?autoplay=1&loop=1)

## More info, references & inspiration

1. [Greg Conti](https://youtu.be/XATakIdyZdk?t=23m23s)
1. [Blackhat 2010 - Voyage of the reverser - Sergey Bratus Greg Conti](https://www.youtube.com/watch?v=T3qqeP4TdPA)
1. [Conti's & Bratus' `binvis`](https://github.com/rebelbot/binvis)
1. [Cortesi's `binvis.io`](https://corte.si/posts/binvis/announce/index.html)
1. [Christopher Domas The future of RE Dynamic Binary Visualization](https://www.youtube.com/watch?v=4bM3Gut1hIk)
1. [Look for the past, present and future inside of π Edit Add topics](https://github.com/fenollp/minepi)
1. [Sloane's Gap. Mathematical and Social Factors Explain the Distribution of Numbers in the OEIS](https://arxiv.org/abs/1101.4470v2)
1. [rule 30 on OEIS.org](https://oeis.org/search?q=%22rule+30%22&sort=&language=&go=Search)
1. [Bailey–Borwein–Plouffe formula](https://en.wikipedia.org/wiki/Bailey%E2%80%93Borwein%E2%80%93Plouffe_formula)


## Usage

```shell
./configure -d RELEASE && cd build && make
./voidstar --move --spin ../data/*
# Press H and L to switch between files
# Use A W S D Z X and your mouse to move in the 3D space
# Press F for full screen
# Use the arrows to slide and enlarge the sliding window
# Press M to slide the window to the end and SPACE to spin the shape
# ESC to quit
```

## Requirements

* A C++ compiler
* `cmake` greater than 2.8

### Windows

https://github.com/fenollp/voidstar/issues/2

### Debian

```shell
sudo apt install libglew-dev libglm-dev libglfw3-dev
```

### OSX

```shell
brew install glew glm pkg-config
brew install glfw3 --without-shared-library
```

### Web

https://github.com/fenollp/voidstar/issues/9

### Android

https://github.com/fenollp/voidstar/issues/7

### iOS

https://github.com/fenollp/voidstar/issues/8

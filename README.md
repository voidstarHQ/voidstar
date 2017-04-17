# VoidStar [![TravisCI build status](https://travis-ci.org/fenollp/voidstar.svg?branch=master)](https://travis-ci.org/fenollp/voidstar/builds)

Browse data using Corti's 2D projector as well as 3D variants.

[![Sorry for potato quality](https://i.vimeocdn.com/video/622736893.webp?mw=480&mh=270)](https://player.vimeo.com/video/207613754?autoplay=1&loop=1)

[More info, references & inspiration](https://github.com/fenollp/minepi)

## Usage

```shell
./configure -d RELEASE && cd build && make
./voidstar ../data/*
# Press H and L to switch between files
# Use AWSDZX and your mouse to move in the 3D space
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
brew install glew glm
brew install glfw3 --without-shared-library
```

### Web

https://github.com/fenollp/voidstar/issues/9

### Android

https://github.com/fenollp/voidstar/issues/7

### iOS

https://github.com/fenollp/voidstar/issues/8

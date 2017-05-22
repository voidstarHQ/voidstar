# VoidStar [![TravisCI build status](https://travis-ci.org/fenollp/voidstar.svg?branch=master)](https://travis-ci.org/fenollp/voidstar/builds)

Browse data using Corti's 2D projector as well as 3D variants.

[![Sorry for potato quality](https://i.vimeocdn.com/video/622736893.webp?mw=480&mh=270)](https://player.vimeo.com/video/207613754?autoplay=1&loop=1)

[More info, references & inspiration](https://github.com/fenollp/minepi)

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
* `conan` (from [https://conan.io](conan.io))

## Building

```shell
git clone https://github.com/fenollp/voidstar.git voidstar.git
mkdir voidstar.git/build
pushd voidstar.git/build
conan install --build -- ..
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build .
```

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
./dockcross --args -v /Users/pete/.conan/conan.conf:/home/pete/.conan/conan.conf bash -c 'mkdir build && cd build && conan install --build -- .. && cmake .. -DCMAKE_BUILD_TYPE=Release && cmake --build .'

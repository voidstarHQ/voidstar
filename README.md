# Miners [![TravisCI build status](https://travis-ci.org/fenollp/miners.svg?branch=master)](https://travis-ci.org/fenollp/miners)

Browse data using Corti's 2D projector as well as 3D variants.

## Usage

```shell
./configure && cd build && make
./miners miners
```

## Requirements

* A C compiler
* `cmake`
* `libglfw-dev` v3. https://github.com/shurcooL-legacy/reusable-commands/blob/ed33ae496f36aaea735a1d183f77e833c92a9f3d/go-gl_glfw3_install.sh#L19-L32
* `libglm-dev`
* `libglu-dev`
* `libglew-dev`

### OSX

* `brew install homebrew/versions/glfw3`

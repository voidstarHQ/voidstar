# Miners [![CircleCI](https://circleci.com/gh/fenollp/miners/tree/master.svg?style=svg)](https://circleci.com/gh/fenollp/miners/tree/master)

Browse data using Corti's 2D projector.

## Usage

```shell
make && cat /dev/urandom | ./miners
# `cat` any file you have ;)
# Spam ENTER to progress through the file
```

## Requirements

* A C compiler
* `cmake`
* `libglfw-dev` v3. https://github.com/shurcooL-legacy/reusable-commands/blob/ed33ae496f36aaea735a1d183f77e833c92a9f3d/go-gl_glfw3_install.sh#L19-L32
* `libglm-dev`
* `libglu-dev`
* `freeglut3`
* `libglew-dev`

### OSX

* `brew install homebrew/versions/glfw3`

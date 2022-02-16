# `(void *)` · [voidstarhq.github.io](https://voidstarhq.github.io)

Browse data using Conti's 2D projector as well as 3D variants.

The actual file being represented below [is data/BigPictureBG.tga](https://github.com/voidstarHQ/voidstar/blob/master/data/BigPictureBG.tga).

https://user-images.githubusercontent.com/278727/140719903-40c56818-0b5c-44ec-bbab-0e9b931c2023.mp4

## More info, references & inspiration

1. [Greg Conti](https://youtu.be/XATakIdyZdk?t=23m23s) (*loud and low quality audio*)

<!-- CONTI-IFRAME -->

2. [Blackhat 2010 - Voyage of the reverser - Sergey Bratus Greg Conti](https://www.youtube.com/watch?v=T3qqeP4TdPA)
1. [Conti's & Bratus' `binvis`](https://github.com/rebelbot/binvis)
1. [Cortesi's `binvis.io`](https://corte.si/posts/binvis/announce/index.html)
1. [REcon 2013 - The Future of RE : Dynamic Binary Visualization (Christopher Domas)](https://www.youtube.com/watch?v=C8--cXwuuFQ)
1. [Christopher Domas The future of RE Dynamic Binary Visualization](https://www.youtube.com/watch?v=4bM3Gut1hIk)
1. [Look for the past, present and future inside of π](https://github.com/fenollp/minepi)
1. [Sloane's Gap. Mathematical and Social Factors Explain the Distribution of Numbers in the OEIS](https://arxiv.org/abs/1101.4470v2)
1. [rule 30 on OEIS.org](https://oeis.org/search?q=%22rule+30%22&sort=&language=&go=Search)
1. [Bailey–Borwein–Plouffe formula](https://en.wikipedia.org/wiki/Bailey%E2%80%93Borwein%E2%80%93Plouffe_formula)
1. [Codisec's open source & maintained Veles](https://codisec.com/veles/)
1. [What do numbers look like?](https://johnhw.github.io/umap_primes/index.md.html)
1. [Some explorations of string repetition statistics](http://www.fantascienza.net/leonardo/ar/string_repetition_statistics/string_repetition_statistics.html)
1. [3D scatterplot of an image](https://alexander.engineering/imagescatter/) ([3D RGB Scatterplots of colours used in famous paintings](https://imgur.com/a/aRBd1), [HN discussion](https://news.ycombinator.com/item?id=15931266), [Reddit](https://www.reddit.com/r/dataisbeautiful/comments/7584no/3d_rgb_scatterplots_of_colours_used_in_famous/))


## Usage

```shell
voidstar --move bazel-bin/voidstar/voidstar data/*
```

```
Usage:
  voidstar  [OPTIONS]  FILE...

    -l, --list         list backends
    -u, --ui           choose ui mode
    -a, --algorithm    algorithm to apply

    -x, --width        window width [default: 800]
    -y, --height       window height [default: 600]
    -f, --fullscreen   start on fullscreen
        --keep-chrome  show title bar & allow resizing
        --exit-at-fin  terminate when show's over

    -w, --sliding      length of sliding window
    -s, --slide-step   amount of points slid
    -m, --move         move sliding window forward
    -n, --no-spin      don't spin shape on itself

    -b, --begin        begin offset for the range
    -e, --end          end offset for the range (0: till end of file)

    -h, --help         this help

  # Press H and L to switch between files
  # Use A W S D Z X and your mouse to move in the 3D space
  # Press F for full screen
  # Use the arrows to slide and enlarge the sliding window
  # Press M to slide the window to the end
  # Use > to slide faster, < to slow down
  # SPACE to toggle spinning the shape
  # Press O to reset the camera position
  # Use B to change background color
  # ESC to quit

```

## Installing

### on MacOS

1. Download one of the `macos` files of [the latest release](https://github.com/fenollp/voidstar/releases/latest)
1. Open `Terminal.app` (you can search for it in Spotlight)
1. Type `chmod u+x ` then drag and drop the file you downloaded then press ENTER (now this file can be executed)
1. Now drag and drop your executable then drag a file you want to look at (e.g. `data/dragon.vox`) then press ENTER
  * your Terminal command should look like `/Users/you/Downloads/voidstar_clang_macos some_file.xyz`
1. A window should appear. Move your mouse and play with your keyboard's arrows. You should see some colored dots in 3D.

### with Docker

```shell
DOCKER_BUILDKIT=1 docker build -o=/usr/local/bin https://github.com/voidstarHQ/voidstar.git
```

### on any Linux distribution

```shell
snap install voidstar
```

This relies on [snaps](https://snapcraft.io/docs/core/install).


## Hacking

```shell
bazel build voidstar
./bazel-bin/voidstar/voidstar --move bazel-bin/voidstar/voidstar data/*
```

* A C++ compiler
* `bazel` that you can use through [bazelisk](https://github.com/bazelbuild/bazelisk)

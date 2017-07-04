#pragma once

#include <string>
#include <vector>
#include <memory>

struct Arguments {
    Arguments()
        : name("void*"),
          algo("conti"),
          manager("glfw"),
          width(800), height(600),
          range_begin(0), range_end(0),
          sliding_window_length(2*1024), sliding_step(1024), move_window(false),
          spin_shape(false),
          fullscreen(false),
          keep_chrome(false)
#ifdef __EMSCRIPTEN__
        ,input({"../data/rgb555.xraw"})
#endif
        {}

    std::string name;
    std::string algo;
    std::string manager;
    size_t width;
    size_t height;
    size_t range_begin;
    size_t range_end;
    size_t sliding_window_length;
    size_t sliding_step;
    bool move_window;
    bool spin_shape;
    bool fullscreen;
    bool keep_chrome;
    std::vector<std::string> input;
};

std::shared_ptr<Arguments> parseArgs(int argc, char *argv[]);

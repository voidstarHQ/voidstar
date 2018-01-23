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
          fullscreen(false),
          keep_chrome(false),
          sliding_window_length(2*1024), sliding_step(1024), move_window(false),
          spin_shape(false)
        {}

    std::vector<std::string> paths;
    std::string name;
    std::string algo;
    std::string manager;
    size_t width;
    size_t height;
    size_t range_begin;
    size_t range_end;
    bool fullscreen;
    bool keep_chrome;
    size_t sliding_window_length;
    size_t sliding_step;
    bool move_window;
    bool spin_shape;
};

std::shared_ptr<Arguments> parseArgs(int argc, char *argv[]);

#pragma once

#include <string>
#include <vector>
#include <memory>

struct Arguments {
    Arguments() {
        name = "void*";
        algo = "conti";
        manager = "glfw";
        width = 800;
        height = 600;
        range_begin = 0;
        range_end = 0;
        fullscreen = false;
        keep_chrome = false;
    }
    std::vector<std::string> input;
    std::string name;
    std::string algo;
    std::string manager;
    size_t width;
    size_t height;
    size_t range_begin;
    size_t range_end;
    bool fullscreen;
    bool keep_chrome;
};

std::shared_ptr<Arguments> parseArgs(int argc, char *argv[]);

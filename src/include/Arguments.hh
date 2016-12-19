#pragma once

#include <string>
#include <vector>

struct Arguments {
    std::string algo;
    std::vector<std::string> input;
    std::string manager;
    size_t width;
    size_t height;
    size_t range_begin;
    size_t range_end;
    bool fullscreen;
};

Arguments *parseArgs(int argc, char **argv);

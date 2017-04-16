#pragma once

#include <string>
#include <vector>
#include <memory>

struct Arguments {
    std::vector<std::string> input;
    std::string name;
    std::string algo;
    std::string manager;
    size_t width;
    size_t height;
    size_t range_begin;
    size_t range_end;
    bool fullscreen;
};

std::shared_ptr<Arguments> parseArgs(int argc, char *argv[]);

#pragma once

#include <string>

struct Arguments {
    std::string input;
    std::string manager;
    size_t width;
    size_t height;
    bool fullscreen;
};

Arguments *parseArgs(int argc, char **argv);

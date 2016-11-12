#include "Arguments.hh"

Arguments *
parseArgs(int argc, char **argv)
{
    auto args = new Arguments();
    args->input = (argc > 1) ? argv[1] : "-";
    args->manager = "glfw";
    args->width = 800;
    args->height = 600;
    args->fullscreen = false;
    return args;
}


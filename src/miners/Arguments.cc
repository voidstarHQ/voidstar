#include <iostream>
#include <getopt.h>

#include <Arguments.hh>
#include <Manager.hh>
#include <Algorithm.hh>

static
void
usage(const char *prgname) {
    std::cout << "usage: " << prgname << " [OPTIONS] file" << std::endl;
    std::cout << std::endl;
    std::cout << " -l --list         list backends" << std::endl;
    std::cout << " -u --ui           choose ui mode" << std::endl;
    std::cout << " -a --algorithm    algorithm to apply" << std::endl;
    std::cout << " -s --scene        type of scene to draw" << std::endl;
    std::cout << std::endl;
    std::cout << " -x --width        window width" << std::endl;
    std::cout << " -y --height       window height" << std::endl;
    std::cout << " -f --fullscreen   window fullscreen" << std::endl;
    std::cout << std::endl;
    std::cout << " -h, --help        this help" << std::endl;
    std::cout << std::endl;
}

static
void
listComponents()
{
    std::cout << "list of UIs:" << std::endl << std::endl;
    for (const auto &pair : managers) {
        std::cout << " - " << pair.first << std::endl;
    }
    std::cout << std::endl;
    std::cout << "list of algorithms:" << std::endl << std::endl;
    for (const auto &pair : algorithms) {
        std::cout << " - " << pair.first << std::endl;
    }
    std::cout << std::endl;
}

Arguments*
parseArgs(int argc, char **argv)
{
    static const char *short_options = ":a:s:fhlu:x:y:";
    static const struct option long_options[] = {
        { "algorithm",  1, 0, 'a' },
        { "scene",      1, 0, 's' },
        { "fullscreen", 0, 0, 'f' },
        { "height",     1, 0, 'y' },
        { "help",       0, 0, 'h' },
        { "list",       0, 0, 'l' },
        { "ui",         1, 0, 'u' },
        { "width",      1, 0, 'x' },
        { 0,            0, 0,  0  }
    };

    bool list = false;
    bool end = false;
    int c;
    int errors = 0;
    int opt_index;

    auto args = new Arguments();
    args->algo = "conti";
    args->scene = "3d";
    args->manager = "glfw";
    args->width = 800;
    args->height = 600;
    args->fullscreen = false;

    while ((c = getopt_long(argc, argv, short_options, long_options, &opt_index)) != -1) {
        switch (c) {
        case 'a':
            args->algo = optarg;
            break;
        case 's':
            args->scene = optarg;
            break;
        case 'f':
            args->fullscreen = true;
            break;
        case 'h':
            end = true;
            break;
        case 'l':
            list = true;
            break;
        case 'u':
            args->manager = optarg;
            break;
        case 'x':
            args->width = std::stoi(optarg);
            break;
        case 'y':
            args->height = std::stoi(optarg);
            break;
        case '?':
            std::cerr << "unknown option " << (char)optopt << std::endl;
            errors++;
            break;
        case ':':
            std::cerr << "missing argument for option " << (char)optopt << std::endl;
            errors++;
            break;
        default:
            std::cerr << "failed to process " << (char)optopt << std::endl;
            errors++;
        }

        if (end)
            break;
    }

    if (list) {
        listComponents();
        return 0;
    }

    if (end || errors) {
        usage(argv[0]);
        if (errors) {
            exit(1);
        }
        delete args;
        return 0;
    }

    for (int i = optind; i < argc; ++i) {
        args->input = argv[i];
        std::cout << "using input " << args->input << std::endl;
    }

    return args;
}

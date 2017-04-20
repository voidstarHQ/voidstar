#include <iostream>
#include <getopt.h>

#include <Arguments.hh>
#include <Manager.hh>
#include <Algorithm.hh>

static void
usage(const char* prgname) {
    std::cout << "usage: " << prgname << " [OPTIONS] file" << std::endl
              << std::endl
              << " -l, --list         list backends" << std::endl
              << " -u, --ui           choose ui mode" << std::endl
              << " -a, --algorithm    algorithm to apply" << std::endl
              << std::endl
              << " -x, --width        window width" << std::endl
              << " -y, --height       window height" << std::endl
              << " -f, --fullscreen   start on fullscreen" << std::endl
              << "     --keep-chrome  show title bar & allow resizing" << std::endl
              << std::endl
              << " -b, --begin        begin offset for the range" << std::endl
              << " -e, --end          end offset for the range" << std::endl
              << std::endl
              << " -h, --help         this help" << std::endl
              << std::endl;
}

static void
listComponents() {
    std::cout << "list of UIs:" << std::endl << std::endl;
    for (const auto &pair : managers) {
        std::cout << " - " << pair.first << std::endl;
    }
    std::cout << std::endl
              << "list of algorithms:" << std::endl << std::endl;
    for (const auto &pair : algorithms) {
        std::cout << " - " << pair.first << std::endl;
    }
    std::cout << std::endl;
}

std::shared_ptr<Arguments>
parseArgs(int argc, char *argv[]) {
    static auto short_options = ":a:b:e:fhlu:x:y:";
    static const struct option long_options[] = {
        {"algorithm",  1, 0, 'a'},
        {"begin",      1, 0, 'b'},
        {"end",        1, 0, 'e'},
        {"fullscreen", 0, 0, 'f'},
        {"keep-chrome",0, 0, '_'},
        {"height",     1, 0, 'y'},
        {"help",       0, 0, 'h'},
        {"list",       0, 0, 'l'},
        {"ui",         1, 0, 'u'},
        {"width",      1, 0, 'x'},
        {0,            0, 0,  0 }
    };

    bool list = false;
    bool end = false;
    int c;
    int errors = 0;
    int opt_index;
    auto args = std::make_shared<Arguments>();

    while ((c = getopt_long(argc, argv, short_options, long_options, &opt_index)) != -1) {
        switch (c) {
        case 'a':
            args->algo = optarg;
            break;
        case 'b':
            args->range_begin = std::stoll(optarg);
            break;
        case 'e':
            args->range_end = std::stoll(optarg);
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
        case '_':
            args->keep_chrome = true;
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
        return NULL;
    }

    if (args->range_end != 0 && args->range_begin >= args->range_end) {
        std::cerr << "range end must be greater than beginning" << std::endl;
        errors += 1;
    }

    if (end || errors) {
        usage(argv[0]);
        if (errors) {
            exit(1);
        }
        return NULL;
    }

    for (int i = optind; i < argc; ++i)
        args->input.push_back(argv[i]);

    if (!args->input.size()) {
        std::cerr << "missing file to process" << std::endl;
        usage(argv[0]);
        return NULL;
    }

    return args;
}

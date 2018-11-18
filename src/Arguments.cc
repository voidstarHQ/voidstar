#include <iostream>
#include <getopt.h>

#include <Arguments.hh>
#include <Manager.hh>
#include <Algorithm.hh>

static void
usage(const char* prgname) {
    std::cout << "Usage: " << prgname << " [OPTIONS] file" << std::endl
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
              << " -w, --sliding      Length of sliding window" << std::endl
              << " -s, --slide-step   Amount of points slid" << std::endl
              << " -m, --move         Move sliding window forward" << std::endl
              << " -n, --spin         Don't spin shape on itself" << std::endl
              << std::endl
              << " -b, --begin        begin offset for the range" << std::endl
              << " -e, --end          end offset for the range" << std::endl
              << std::endl
              << " -h, --help         this help" << std::endl
              << std::endl;
}

static void
listComponents() {
    std::cout << "Available UIs:" << std::endl;
    for (const auto &pair : managers) {
        std::cout << " - " << pair.first << std::endl;
    }
    std::cout << std::endl
              << "Available algorithms:" << std::endl;
    for (const auto &pair : algorithms) {
        std::cout << " - " << pair.first << std::endl;
    }
    std::cout << std::endl;
}

std::shared_ptr<Arguments>
parseArgs(int argc, char *argv[]) {
    static auto short_options = ":a:b:e:fmn_hls:w:u:x:y:";
    static const struct option long_options[] = {
        {"algorithm",  1, 0, 'a'},
        {"begin",      1, 0, 'b'},
        {"end",        1, 0, 'e'},
        {"fullscreen", 0, 0, 'f'},
        {"keep-chrome",0, 0, '_'},
        {"height",     1, 0, 'y'},
        {"help",       0, 0, 'h'},
        {"list",       0, 0, 'l'},
        {"slide-step", 1, 0, 's'},
        {"sliding",    1, 0, 'w'},
        {"move",       0, 0, 'm'},
        {"spin",       0, 0, 'n'},
        {"ui",         1, 0, 'u'},
        {"width",      1, 0, 'x'},
        {NULL,         0, 0,  0}
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
            args->range_begin = std::stoull(optarg);
            break;
        case 'e':
            args->range_end = std::stoull(optarg);
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
        case 'm':
            args->move_window = true;
            break;
        case 'n':
            args->spin_shape = false;
            break;
        case 's':
            args->sliding_step = std::stoul(optarg);
            break;
        case 'u':
            args->manager = optarg;
            break;
        case 'w':
            args->sliding_window_length = std::stoul(optarg);
            break;
        case 'x':
            args->width = std::stoul(optarg);
            break;
        case 'y':
            args->height = std::stoul(optarg);
            break;
        case '_':
            args->keep_chrome = true;
            break;
        case '?':
            std::cerr << "Unknown option '" << (char)optopt << "'" << std::endl;
            errors++;
            break;
        case ':':
            std::cerr << "Missing argument for option '" << (char)optopt << "'" << std::endl;
            errors++;
            break;
        default:
            std::cerr << "Failed to process '" << (char)optopt << "'" << std::endl;
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
        args->paths.push_back(argv[i]);

    if (!args->paths.size()) {
        std::cerr << "missing file to process" << std::endl;
        usage(argv[0]);
        return NULL;
    }

    return args;
}

#include "voidstar/arguments.h"

#include <getopt.h>

#include <cassert>
#include <iostream>

REGISTRY_IMPLEMENTATION_FOR(Meta)

static void usage(const char* prgname __unused) {
  std::cout << R"(Usage:
  voidstar  [OPTIONS]  FILE...

    -l, --list         list backends
    -u, --ui           choose ui mode
    -a, --algorithm    algorithm to apply

    -x, --width        window width [default: 800]
    -y, --height       window height [default: 600]
    -f, --fullscreen   start on fullscreen
        --keep-chrome  show title bar & allow resizing
        --exit-at-fin  terminate when show's over

    -w, --sliding      length of sliding window
    -s, --slide-step   amount of points slid
    -m, --move         move sliding window forward
    -n, --no-spin      don't spin shape on itself

    -b, --begin        begin offset for the range
    -e, --end          end offset for the range (0: till end of file)

    -h, --help         this help

  # Press H and L to switch between files
  # Use A W S D Z X and your mouse to move in the 3D space
  # Press F for full screen
  # Use the arrows to slide and enlarge the sliding window
  # Press M to slide the window to the end
  # Use > to slide faster, < to slow down
  # SPACE to toggle spinning the shape
  # Press O to reset the camera position
  # ESC to quit

)";
}

static void listComponents() {
  for (const auto& [category, namesFactory] : RegistryForMeta()) {
    std::cout << "Available " << category << ":\n";
    assert(namesFactory);
    const auto& names = namesFactory();
    for (const auto& name : *names) std::cout << "    " << name << std::endl;
    std::cout << std::endl;
  }
}

std::shared_ptr<Arguments> parseArgs(int argc, char* argv[]) {
  static auto short_options = ":a:b:e:fmn12hls:w:u:x:y:";
  static const struct option long_options[] = {{"algorithm", 1, 0, 'a'},
                                               {"begin", 1, 0, 'b'},
                                               {"end", 1, 0, 'e'},
                                               {"fullscreen", 0, 0, 'f'},
                                               {"keep-chrome", 0, 0, '1'},
                                               {"exit-at-fin", 0, 0, '2'},
                                               {"height", 1, 0, 'y'},
                                               {"help", 0, 0, 'h'},
                                               {"list", 0, 0, 'l'},
                                               {"slide-step", 1, 0, 's'},
                                               {"sliding", 1, 0, 'w'},
                                               {"move", 0, 0, 'm'},
                                               {"no-spin", 0, 0, 'n'},
                                               {"ui", 1, 0, 'u'},
                                               {"width", 1, 0, 'x'},
                                               {NULL, 0, 0, 0}};

  bool list = false;
  bool end = false;
  int c;
  int errors = 0;
  int opt_index;
  auto args = std::make_shared<Arguments>();

  while ((c = getopt_long(argc, argv, short_options, long_options,
                          &opt_index)) != -1) {
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
      case '1':
        args->keep_chrome = true;
        break;
      case '2':
        args->exit_at_fin = true;
        break;
      case '?':
        std::cerr << "Unknown option '" << (char)optopt << "'" << std::endl;
        errors++;
        break;
      case ':':
        std::cerr << "Missing argument for option '" << (char)optopt << "'"
                  << std::endl;
        errors++;
        break;
      default:
        std::cerr << "Failed to process '" << (char)optopt << "'" << std::endl;
        errors++;
    }

    if (end) break;
  }

  if (list) {
    listComponents();
    return NULL;
  }

  if (args->range_end != 0 && args->range_begin >= args->range_end) {
    // TODO: clearer message suggesting to swap numbers + show the numbers
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

  for (int i = optind; i < argc; ++i) args->paths.push_back(argv[i]);

  if (!args->paths.size()) {
    std::cerr << "missing file to process" << std::endl;
    usage(argv[0]);
    return NULL;
  }

  return args;
}

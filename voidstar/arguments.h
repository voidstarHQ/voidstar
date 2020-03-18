#pragma once

#include <algorithm>
#include <memory>

#include "voidstar/registrar.h"

struct Arguments {
  Arguments() {}

  std::vector<std::string> paths;
  std::string name = "void*";
  std::string algo = "Algo3DCubeContiFrebet";
  std::string manager = "GLFW3Manager";
  size_t width = 800;
  size_t height = 600;
  size_t range_begin = 0;
  size_t range_end = 0;
  bool fullscreen = false;
  bool keep_chrome = false;
  size_t sliding_window_length = 37 * 1024;
  size_t sliding_step = 1024;
  size_t sliding_step_factor = 1;
  bool move_window = false;
  bool spin_shape = true;
};

std::shared_ptr<Arguments> parseArgs(int argc, char* argv[]);

REGISTRY_DECLARATION_FOR(Meta, std::shared_ptr<std::vector<std::string>>());
#define REGISTER_META(NAME, KLASS)                                       \
  REGISTRY_REGISTER_FOR(                                                 \
      Meta, NAME, KLASS, ()->std::shared_ptr<std::vector<std::string>> { \
        const auto& meta = RegistryFor##KLASS();                         \
        auto names = std::make_shared<std::vector<std::string>>();       \
        names->reserve(meta.size());                                     \
        for (const auto& [n, _] : meta) names->push_back(n);             \
        std::sort(names->begin(), names->end());                         \
        return names;                                                    \
      })

#pragma once

#include <algorithm>
#include <memory>

#include "voidstar/registrar.h"
#include "voidstar/types.h"

struct Arguments {
  Arguments() {}

  std::vector<std::string> paths;
  std::string name = "void*";
  std::string algo = "Algo3DCubeContiFrebet";
  std::string manager = "GLFW3Manager";
  u32 width = 800;
  u32 height = 600;
  u32 range_begin = 0;
  u32 range_end = 0;
  bool fullscreen = false;
  bool keep_chrome = false;
  u32 sliding_window_length = 37 * 1024;
  u32 sliding_step = 1024;
  u32 sliding_step_factor = 1;
  bool move_window = false;
  bool spin_shape = true;
  bool exit_at_fin = false;
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

#pragma once

#include <cstddef>
#include <iostream>
#include <memory>

#include "voidstar/size2str.h"
#include "voidstar/algorithm.h"
#include "voidstar/arguments.h"
#include "voidstar/registrar.h"

class Scene {
 public:
  Scene(std::string type) : type_(type) {}
  virtual ~Scene() {}

  virtual void init(std::shared_ptr<Arguments> args) = 0;
  virtual bool update(float elapsedTime) = 0;
  virtual void render() = 0;
  virtual void load(std::shared_ptr<Algorithm> algo);
  virtual void unload() {}
  virtual void reload() {}

  virtual void resize(u32 viewport_width, u32 viewport_height) {
    const float aspect_ratio = static_cast<float>(viewport_width) / static_cast<float>(viewport_height);
    std::cout << "aspect: " << aspect_ratio
              << " (" << size2str(viewport_width)
               << 'x' << size2str(viewport_height)
               << ")\n";
  }

  GLint program() const {
    assertm(program_<=std::numeric_limits<GLint>::max(), "program ID overflows");
    return static_cast<GLint>(program_);
  }
  inline std::string type() const { return type_; }
  inline VertIndices& selected() { return selected_; };
  inline const VertIndices& indices() const { return indices_; };

  std::shared_ptr<Algorithm> algorithm() const { return algo_; }

 protected:
  std::string type_;
  std::shared_ptr<Algorithm> algo_ = nullptr;
  GLuint program_ = 0;

  VertIndices selected_;
  VertIndices indices_;
};

REGISTRY_DECLARATION_FOR(Scene,
                         std::shared_ptr<Scene>(std::shared_ptr<Arguments>,
                                                std::shared_ptr<Algorithm>));
#define REGISTER_SCENE(KLASS)                                            \
  REGISTRY_REGISTER_FOR(                                                 \
      Scene, #KLASS, KLASS,                                              \
      (std::shared_ptr<Arguments> args, std::shared_ptr<Algorithm> algo) \
          ->std::shared_ptr<Scene> {                                     \
            auto scene = std::make_shared<KLASS>();                      \
            scene->init(args);                                           \
            scene->load(algo);                                           \
            return scene;                                                \
          })

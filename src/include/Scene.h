#pragma once

#include <GL/glew.h>

#include <cstddef>
#include <iostream>
#include <memory>
#define GLM_FORCE_RADIANS
// functions taking degrees as a parameter are deprecated
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "src/include/Algorithm.h"
#include "src/include/Arguments.h"
#include "src/include/Manager.h"

class Manager;

class Scene {
 public:
  Scene(SceneType type) : type_(type), algo_(nullptr) {}
  virtual ~Scene() {}

  virtual void init(std::shared_ptr<Arguments> args) = 0;
  virtual bool update(std::shared_ptr<Manager> manager, float elapsedTime) = 0;
  virtual void render() = 0;
  virtual void load(std::shared_ptr<Algorithm> algo);
  virtual void unload() {}
  virtual void reload() {}

  virtual void resize(int viewport_width, int viewport_height) {
    float aspect_ratio = static_cast<float>(viewport_width) /
                         static_cast<float>(viewport_height);
    std::cout << "aspect: " << aspect_ratio << " (" << viewport_width << 'x'
              << viewport_height << ")\n";
  }

  inline SceneType type() const { return type_; }
  inline GLuint program() const { return program_; }
  std::shared_ptr<Algorithm> algorithm() const { return algo_; }
  static std::shared_ptr<Scene> with_algo(std::shared_ptr<Arguments> args,
                                          std::shared_ptr<Algorithm> algo);

 protected:
  SceneType type_;
  std::shared_ptr<Algorithm> algo_;
  GLuint program_;
};

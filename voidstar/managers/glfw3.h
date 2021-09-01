#pragma once

#include <bitset>
#include <memory>

#define GLM_FORCE_RADIANS
// functions taking degrees as a parameter are deprecated
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "GLFW/glfw3.h"
#include "voidstar/managers/manager.h"
#include "voidstar/types.h"

struct GlfwModifiers {
  int shift : 1;
  int ctrl : 1;
  int alt : 1;
  int super : 1;
} __attribute__((packed));

struct GlfwKeyboardState {
  std::bitset<512> keys;
  union {
    int rawmods;
    GlfwModifiers mods;
  };

  void copy(const std::shared_ptr<GlfwKeyboardState>& state) {
    keys = state->keys;
    rawmods = state->rawmods;
  }
};

class GlfwKeyboardEvents : public Events {
 public:
  GlfwKeyboardEvents()
      : current_(std::make_shared<GlfwKeyboardState>()),
        previous_(std::make_shared<GlfwKeyboardState>()) {}
  virtual ~GlfwKeyboardEvents();

  virtual bool keyPressed(int key);
  virtual bool keyReleased(int key);
  virtual bool keyDown(int key);
  virtual bool keyUp(int key);

  virtual void update();

  void process(int key, int scancode, int action, int mods);

  // protected:
  std::shared_ptr<GlfwKeyboardState> current_;
  std::shared_ptr<GlfwKeyboardState> previous_;
};

class GLFW3Manager : public Manager {
 public:
  GLFW3Manager(std::shared_ptr<Arguments>& args)
      : Manager(args),
        window_(nullptr),
        viewport_width_(args->width),
        viewport_height_(args->height) {
    resetFloats();
  }
  virtual ~GLFW3Manager() {}

  virtual void init() override;
  virtual void run() override;

  virtual std::shared_ptr<Events> getEvents() final { return events_; }

  virtual void ToggleFullscreen() override;

  void viewport(int w, int h) {
    viewport_width_ = w;
    viewport_height_ = h;
  }

  static void glProcessErrors(bool quiet = false);

  static std::shared_ptr<GLFW3Manager> instance(
      std::shared_ptr<Arguments> args) {
    if (instance_ || !args)
      throw std::runtime_error("Bad call to instance of GLFW3Manager");
    instance_ = std::make_shared<GLFW3Manager>(args);
    return instance_;
  }

  static std::shared_ptr<GLFW3Manager> instance() {
    if (!instance_)
      throw std::runtime_error("GLFW3Manager wasn't previously instanciated");
    return instance_;
  }

 private:
  void resetFloats() {
    position_ = glm::vec3(0, 0, 5);
    horizontal_angle_ = 3.14f;
    vertical_angle_ = 0.0f;  // look at the horizon
    initial_fov_ = 45.0f;
  }
  glm::vec3 position_;
  // horizontal angle : toward -Z
  float horizontal_angle_;
  // vertical angle : 0, look at the horizon
  float vertical_angle_;
  // Initial Field of View
  float initial_fov_;

 protected:
  static std::shared_ptr<GLFW3Manager> instance_;
  GLFWwindow* window_;
  std::shared_ptr<GlfwKeyboardEvents> events_;
  int viewport_width_, viewport_height_;

 private:
  bool SlideWindow();
  bool updateFirst(float deltaTime, glm::mat4* MVP);
  float degrees_rotated_ = 0;
  float degrees_per_second_ = 10;
  float move_speed_ = 3.0f;           // 3 units / second
  float mouse_sensitivity_ = 0.005f;  // 0.1f;
  // FoV is the level of zoom. 80° = very wide angle, huge deformations.
  // 60° - 45°: standard. 20°: big zoom.
};
REGISTER_MANAGER(GLFW3Manager)

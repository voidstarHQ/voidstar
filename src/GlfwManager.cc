#define GLEW_STATIC
#include <GL/glew.h>

// This forces clang-format to move below headers up.

#include "include/GLFW/glfw3.h"
#include "src/include/GlfwManager.h"

std::shared_ptr<GlfwManager> GlfwManager::instance_;

void onFramebufferResize(GLFWwindow* window __unused, int width, int height) {
  glViewport(0, 0, width, height);
  GlfwManager::instance()->viewport(width, height);
  auto scene = GlfwManager::instance()->scene();
  scene->resize(width, height);
}

// records how far the y axis has been scrolled
static void onScroll(GLFWwindow* window __unused, double deltaX,
                     double deltaY) {
  auto mouse = GlfwManager::instance()->getMouse();
  mouse->scrollY += deltaY;
  mouse->scrollX += deltaX;
}

static void onError(int errorCode __unused, const char* msg) {
  throw std::runtime_error(msg);
}

static void onKeyEvent(GLFWwindow* window __unused, int key, int scancode,
                       int action, int mods) {
  auto events = GlfwManager::instance()->getEvents();
  auto ev = std::static_pointer_cast<GlfwKeyboardEvents>(events);
  ev->process(key, scancode, action, mods);
}

void GlfwManager::init() {
  if (!glfwInit()) {
    std::cerr << "Failed to initialize GLFW\n";
    getchar();
    throw std::runtime_error("!glfwInit");
  }

  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  // GLFW_OPENGL_FORWARD_COMPAT to make macOS happy; should not be needed
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
  if (!args_->keep_chrome) glfwWindowHint(GLFW_DECORATED, false);

  GLFWmonitor* monitor = NULL;
  if (args_->fullscreen) {
    monitor = glfwGetPrimaryMonitor();
  }

  // Create a GLFWwindow object that we can use for GLFW's functions
  window_ = glfwCreateWindow(args_->width, args_->height, args_->name.c_str(),
                             monitor, nullptr);
  if (!window_) {
    std::cerr << "Failed to open GLFW window.\n";
    getchar();
    glfwTerminate();
    throw std::runtime_error("!glfwCreateWindow");
  }
  glfwMakeContextCurrent(window_);

  glfwSetFramebufferSizeCallback(window_, onFramebufferResize);
  // Set the required callback functions
  glfwSetKeyCallback(window_, onKeyEvent);

  // Set this to true so GLEW knows to use a modern approach to retrieving
  // function pointers and extensions
  glewExperimental = GL_TRUE;
  // Initialize GLEW to setup the OpenGL Function pointers
  if (glewInit() != GLEW_OK) {
    std::cerr << "Failed to initialize GLEW\n";
    getchar();
    glfwTerminate();
    throw std::runtime_error("!glewInit");
  }

  // Ensure we can capture the escape key being pressed below
  glfwSetInputMode(window_, GLFW_STICKY_KEYS, GL_TRUE);
  // Hide the mouse and enable unlimited mouvement
  glfwSetInputMode(window_, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

  // Define the viewport dimensions
  glfwGetFramebufferSize(window_, &viewport_width_, &viewport_height_);
  glViewport(0, 0, viewport_width_, viewport_height_);

  // Set the mouse at the center of the screen
  glfwPollEvents();
  glfwSetCursorPos(window_, viewport_width_ / 2, viewport_height_ / 2);

  glfwSetErrorCallback(onError);

  // glfwSetWindowUserPointer(window_, this);
  // glfwSetScrollCallback(window_, onScroll);

  mouse_ = std::make_shared<GlfwMouse>();
  events_ = std::make_shared<GlfwKeyboardEvents>();
}

void GlfwManager::glProcessErrors(bool quiet) {
  while (true) {
    GLenum error = glGetError();
    if (error == GL_NO_ERROR) break;
    if (!quiet) std::cerr << "OpenGL Error " << error << std::endl;
  }
}

void GlfwManager::computeMatricesFromInputs(glm::mat4* ProjectionMatrix,
                                            glm::mat4* ViewMatrix) {
  static double lastTime = glfwGetTime();
  double currentTime = glfwGetTime();
  float deltaTime = float(currentTime - lastTime);

  // Get mouse position
  double xpos, ypos;
  glfwGetCursorPos(window_, &xpos, &ypos);
  // Reset mouse position for next frame
  glfwSetCursorPos(window_, viewport_width_ / 2, viewport_height_ / 2);

  // Compute new orientation
  horizontal_angle_ += mouse_sensitivity_ * float(viewport_width_ / 2 - xpos);
  vertical_angle_ += mouse_sensitivity_ * float(viewport_height_ / 2 - ypos);

  glm::vec3 direction, right, up;
  auto resetVecs = [this, &direction, &right, &up]() {
    // Direction : Spherical coordinates to Cartesian coordinates conversion
    direction = glm::vec3(cos(vertical_angle_) * sin(horizontal_angle_),
                          sin(vertical_angle_),
                          cos(vertical_angle_) * cos(horizontal_angle_));

    right = glm::vec3(sin(horizontal_angle_ - 3.14f / 2.0f), 0,
                      cos(horizontal_angle_ - 3.14f / 2.0f));
    up = glm::cross(right, direction);
  };
  resetVecs();

  if (events_->keyDown('W'))  // forward
    position_ += direction * deltaTime * speed_;
  if (events_->keyDown('S'))  // backward
    position_ -= direction * deltaTime * speed_;
  if (events_->keyDown('D'))  // strafe right
    position_ += right * deltaTime * speed_;
  if (events_->keyDown('A'))  // strafe left
    position_ -= right * deltaTime * speed_;
  if (events_->keyDown('X'))  // upward
    position_ += up * deltaTime * speed_;
  if (events_->keyDown('Z'))  // downward
    position_ -= up * deltaTime * speed_;

  if (events_->keyPressed('O')) {
    resetFloats();
    resetVecs();
  }

  if (events_->keyPressed(' '))  // toggle spinning shape
    args_->spin_shape = !args_->spin_shape;
  if (events_->keyPressed('M'))  // toggle sliding window
    args_->move_window = !args_->move_window;
  if (events_->keyPressed('.'))  // FIXME: '>'
    args_->sliding_step_factor *= 2;
  if (events_->keyPressed(',')) {  // FIXME: '<'
    args_->sliding_step_factor /= 2;
    if (args_->sliding_step_factor == 0) {
      args_->sliding_step_factor = 1;
    }
  }

  float FoV =
      initial_fov_;  // - 5 * glfwGetMouseWheel();
                     // Now GLFW 3 requires setting
                     // up a callback for this. It's a bit too complicated for
                     // this beginner's tutorial, so it's disabled instead.

  // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit
  // <-> 100 units
  *ProjectionMatrix = glm::perspective(
      glm::radians(FoV), (float)viewport_width_ / (float)viewport_height_, 0.1f,
      100.0f);
  // Camera matrix
  *ViewMatrix = glm::lookAt(
      position_,  // Camera is here
      position_ +
          direction,  // and looks here : at the same position, plus "direction"
      up              // Head is up (set to 0,-1,0 to look upside-down)
  );

  // For the next frame, the "last time" will be "now"
  lastTime = currentTime;
}

void GlfwManager::run() {
  if (scene_->type() == SCENE_3D)
    glfwSetInputMode(window_, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

  double lastTime = glfwGetTime();
  while (!glfwWindowShouldClose(window_)) {
    // process pending events
    events_->update();

    // update the scene based on the time elapsed since last update
    double thisTime = glfwGetTime();
    float elapsedTime = thisTime - lastTime;
    bool redraw = scene_->update(GlfwManager::instance(), elapsedTime);
    lastTime = thisTime;

    if (redraw) {
      scene_->render();
      glfwSwapBuffers(window_);
    }

    glProcessErrors();

    if (events_->keyPressed(GLFW_KEY_ESCAPE))
      glfwSetWindowShouldClose(window_, GL_TRUE);
    if (events_->keyPressed('F')) toggleFullscreen();

    if (events_->keyPressed('H')) loadPrevFile();
    if (events_->keyPressed('L')) loadNextFile();
  }
  glfwTerminate();
}

GlfwKeyboardEvents::~GlfwKeyboardEvents() {}

bool GlfwKeyboardEvents::keyDown(int key) { return current_->keys[key]; }

bool GlfwKeyboardEvents::keyUp(int key) { return !current_->keys[key]; }

bool GlfwKeyboardEvents::keyPressed(int key) {
  return current_->keys[key] && !previous_->keys[key];
}

bool GlfwKeyboardEvents::keyReleased(int key) {
  return !current_->keys[key] && previous_->keys[key];
}

void GlfwKeyboardEvents::update() {
  previous_->copy(current_);
  glfwPollEvents();
}

void GlfwKeyboardEvents::process(int key, int scancode, int action, int mods) {
  (void)scancode;
  if (key < 0) return;
  current_->keys[key] = action != GLFW_RELEASE;
  current_->rawmods = mods;
}

void GlfwMouse::getCursorPos() {
  glfwGetCursorPos(GlfwManager::instance()->window(), &x, &y);
}

void GlfwMouse::setCursorPos() {
  glfwSetCursorPos(GlfwManager::instance()->window(), x, y);
}

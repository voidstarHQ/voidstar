#include "GL/glew.h"
// This comments prevents clang-format from reordering includes
#include "voidstar/managers/glfw3.h"

std::shared_ptr<GLFW3Manager> GLFW3Manager::instance_;

void onFramebufferResize(GLFWwindow* window __unused, int width, int height) {
  glViewport(0, 0, width, height);
  GLFW3Manager::instance()->viewport(width, height);
  auto scene = GLFW3Manager::instance()->scene();
  scene->resize(width, height);
}

static void onError(int errorCode __unused, const char* msg) {
  throw std::runtime_error(msg);
}

static void onKeyEvent(GLFWwindow* window __unused, int key, int scancode,
                       int action, int mods) {
  auto events = GLFW3Manager::instance()->getEvents();
  auto ev = std::static_pointer_cast<GlfwKeyboardEvents>(events);
  ev->process(key, scancode, action, mods);
}

void GLFW3Manager::init() {
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

  // Define the viewport dimensions
  glfwGetFramebufferSize(window_, &viewport_width_, &viewport_height_);
  glViewport(0, 0, viewport_width_, viewport_height_);

  glfwPollEvents();

  glfwSetErrorCallback(onError);

  // glfwSetWindowUserPointer(window_, this);
  // glfwSetScrollCallback(window_, onScroll);

  events_ = std::make_shared<GlfwKeyboardEvents>();
}

void GLFW3Manager::glProcessErrors(bool quiet) {
  while (true) {
    GLenum error = glGetError();
    if (error == GL_NO_ERROR) break;
    if (!quiet) std::cerr << "OpenGL Error " << error << std::endl;
  }
}

void GLFW3Manager::ToggleFullscreen() {
  int w, h;
  fullscreen_ = !fullscreen_;
  if (fullscreen_) {
    w = static_cast<int>(args_->width);
    h = static_cast<int>(args_->height);
  } else {
    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    glfwSetWindowPos(window_, 0, 0);
    w = mode->width;
    h = mode->height;
  }
  glfwSetWindowSize(window_, w, h);
}

bool GLFW3Manager::SlideWindow() {
  bool ret = false;
  if (events_->keyDown(GLFW_KEY_LEFT)) {
    ret = true;
    slide_window_left();
  } else if (events_->keyDown(GLFW_KEY_RIGHT)) {
    ret = true;
    slide_window_right();
  }
  if (events_->keyDown(GLFW_KEY_UP)) {
    ret = true;
    slide_window_up();
  } else if (events_->keyDown(GLFW_KEY_DOWN)) {
    ret = true;
    slide_window_down();
  }
  return ret;
}

bool GLFW3Manager::updateFirst(float deltaTime, glm::mat4* MVP) {
  // Get mouse position
  double xpos, ypos;
  glfwGetCursorPos(window_, &xpos, &ypos);

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
    position_ += deltaTime * move_speed_ * direction;
  if (events_->keyDown('S'))  // backward
    position_ -= deltaTime * move_speed_ * direction;
  if (events_->keyDown('D'))  // strafe right
    position_ += deltaTime * move_speed_ * right;
  if (events_->keyDown('A'))  // strafe left
    position_ -= deltaTime * move_speed_ * right;
  if (events_->keyDown('X'))  // upward
    position_ += deltaTime * move_speed_ * up;
  if (events_->keyDown('Z'))  // downward
    position_ -= deltaTime * move_speed_ * up;

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
  if (events_->keyPressed(','))  // FIXME: '<'
    args_->sliding_step_factor =
        std::max<u32>(1, args_->sliding_step_factor / 2);

  const glm::mat4 projection = glm::perspective(
      // TODO: change field of view when scrolling
      glm::radians(initial_fov_),
      // aspect ratio
      (float)viewport_width_ / (float)viewport_height_,
      // display range : 0.1 unit <-> 100 units
      0.1f, 100.0f);
  const glm::mat4 view = glm::lookAt(
      // Camera is here
      position_,
      // and looks here : at the same position, plus "direction"
      position_ + direction,
      // Head is up (set to 0,-1,0 to look upside-down)
      up);

  if (args_->spin_shape) {
    degrees_rotated_ += deltaTime * degrees_per_second_;
    while (degrees_rotated_ > 360.0f) degrees_rotated_ -= 360.0f;
  }

  // Model matrix : an identity matrix (model will be at the origin)
  const glm::mat4 model = glm::rotate(
      // id mat
      glm::mat4(1.0),
      // rotate
      glm::radians(degrees_rotated_),
      // around Y axis
      glm::vec3(0, 1, 0));
  // Note matrix multiplication is not commutative
  *MVP = projection * view * model;

  const bool file_changed = FileJustChanged();
  if (false ||
      // Args ask to slide window
      args_->move_window ||
      // Window contains nothing
      scene_->selected().empty() ||
      // User changed window
      SlideWindow() ||
      // User loaded a different file
      file_changed || false) {
    if (args_->move_window) slide_window_right();
    bool slid = slide_window(scene_->selected(), scene_->indices());
    if (!slid && args_->move_window) args_->move_window = false;
  }

  return true;
}

void GLFW3Manager::run() {
  const bool is3D = scene_->type() == "Scene3D";
  GLuint uMVP = 0;
  if (is3D) {
    // Get uniform uMVP slot within shader program
    uMVP = glGetUniformLocation(scene_->program(), "uMVP");
    // Hide the mouse and enable unlimited mouvement
    glfwSetInputMode(window_, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    // Set the mouse at the center of the screen
    glfwSetCursorPos(window_, viewport_width_ / 2, viewport_height_ / 2);
  }

  double lastTime = glfwGetTime();
  while (!glfwWindowShouldClose(window_)) {
    // process pending events
    events_->update();

    // Clear the colorbuffer
    glClearColor(0, 0, 0, 1);
    // glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    if (is3D) {
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    } else {
      glClear(GL_COLOR_BUFFER_BIT);
    }

    // use program so uniforms can be set in scene update/render
    glUseProgram(scene_->program());

    // update the scene based on the time elapsed since last update
    double thisTime = glfwGetTime();
    float elapsedTime = static_cast<float>(thisTime - lastTime);
    glm::mat4 MVP;
    bool redraw = updateFirst(elapsedTime, &MVP);
    if (redraw) {
      if (is3D) glUniformMatrix4fv(uMVP, 1, GL_FALSE, &MVP[0][0]);
      redraw |= scene_->update(elapsedTime);
    }
    lastTime = thisTime;

    if (redraw) {
      scene_->render();
      glfwSwapBuffers(window_);
    }

    glUseProgram(0);  // stop using

    // Set the mouse at the center of the screen
    if (is3D)
      glfwSetCursorPos(window_, viewport_width_ / 2, viewport_height_ / 2);
    if (events_->keyPressed(GLFW_KEY_ESCAPE))
      glfwSetWindowShouldClose(window_, GL_TRUE);
    if (events_->keyPressed('F')) ToggleFullscreen();
    if (events_->keyPressed('H')) loadPrevFile();
    if (events_->keyPressed('L')) loadNextFile();
    if (!args_->move_window && args_->exit_at_fin)
      glfwSetWindowShouldClose(window_, GLFW_TRUE);
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

#define GLEW_STATIC
#include <GL/glew.h>

#include "include/GLFW/glfw3.h"
#include "src/include/GlfwManager.h"


std::shared_ptr<GlfwManager> GlfwManager::instance_;

int viewportW = 800, viewportH = 600;

void onFramebufferResize(GLFWwindow* window __unused, int width, int height) {
  glViewport(0, 0, width, height);
  viewportW = width;
  viewportH = height;
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

  // if (action == GLFW_PRESS)
  //     std::cout << "pressed: ";
  // else if (action == GLFW_RELEASE)
  //     std::cout << "released: ";
  // else if (action == GLFW_REPEAT)
  //     std::cout << "repeat: ";
  // else
  //     std::cout << "wtf: ";
  // std::cout << "key " << key << " (" << scancode << ", " << mods << ")" <<
  // std::endl;
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
  glfwGetFramebufferSize(window_, &viewportW, &viewportH);
  glViewport(0, 0, viewportW, viewportH);

  // Set the mouse at the center of the screen
  glfwPollEvents();
  glfwSetCursorPos(window_, viewportW / 2, viewportH / 2);

  glfwSetErrorCallback(onError);

  // glfwSetWindowUserPointer(window_, this);
  // glfwSetScrollCallback(window_, onScroll);

  mouse_ = std::make_shared<GlfwMouse>();
  events_ = std::make_shared<GlfwKeyboardEvents>();
}

// void
// GlfwManager::glInit() {
//     glewExperimental = GL_TRUE; //stops glew from crashing on OSX :-/
//     if (glewInit() != GLEW_OK)
//         throw std::runtime_error("!glewInit");

//     // GLEW throws some errors, so discard all the errors so far
//     glProcessErrors();

//     std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl
//               << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION)
//               << std::endl
//               << "Vendor: " << glGetString(GL_VENDOR) << std::endl
//               << "Renderer: " << glGetString(GL_RENDERER) << std::endl;

//     if (!GLEW_VERSION_3_2)
//         throw std::runtime_error("OpenGL 3.2 API is not available.");
// }

void GlfwManager::glProcessErrors(bool quiet) {
  while (true) {
    GLenum error = glGetError();
    if (error == GL_NO_ERROR) break;
    if (!quiet) std::cerr << "OpenGL Error " << error << std::endl;
  }
}

glm::vec3 position = glm::vec3(0, 0, 5);
// horizontal angle : toward -Z
float horizontalAngle = 3.14f;
// vertical angle : 0, look at the horizon
float verticalAngle = 0.0f;
// Initial Field of View
float initialFoV = 45.0f;

float speed = 3.0f;  // 3 units / second
float mouseSpeed = 0.005f;
// FoV is the level of zoom. 80° = very wide angle, huge deformations.
// 60° - 45°: standard. 20°: big zoom.

void GlfwManager::computeMatricesFromInputs(glm::mat4* ProjectionMatrix,
                                            glm::mat4* ViewMatrix) {
  static double lastTime = glfwGetTime();
  double currentTime = glfwGetTime();
  float deltaTime = float(currentTime - lastTime);

  // Get mouse position
  double xpos, ypos;
  glfwGetCursorPos(window_, &xpos, &ypos);
  // Reset mouse position for next frame
  glfwSetCursorPos(window_, viewportW / 2, viewportH / 2);

  // Compute new orientation
  horizontalAngle += mouseSpeed * float(viewportW / 2 - xpos);
  verticalAngle += mouseSpeed * float(viewportH / 2 - ypos);

  // Direction : Spherical coordinates to Cartesian coordinates conversion
  glm::vec3 direction(cos(verticalAngle) * sin(horizontalAngle),
                      sin(verticalAngle),
                      cos(verticalAngle) * cos(horizontalAngle));

  glm::vec3 right = glm::vec3(sin(horizontalAngle - 3.14f / 2.0f), 0,
                              cos(horizontalAngle - 3.14f / 2.0f));
  glm::vec3 up = glm::cross(right, direction);

  // GLFW_KEY_UP, GLFW_KEY_DOWN, GLFW_KEY_RIGHT, GLFW_KEY_LEFT
  if (glfwGetKey(window_, 'W') == GLFW_PRESS) {
    position += direction * deltaTime * speed;  // forward
  }
  if (glfwGetKey(window_, 'S') == GLFW_PRESS) {
    position -= direction * deltaTime * speed;  // backward
  }
  if (glfwGetKey(window_, 'D') == GLFW_PRESS) {
    position += right * deltaTime * speed;  // strafe right
  }
  if (glfwGetKey(window_, 'A') == GLFW_PRESS) {
    position -= right * deltaTime * speed;  // strafe left
  }
  if (glfwGetKey(window_, 'X') == GLFW_PRESS) {
    position += up * deltaTime * speed;  // up
  }
  if (glfwGetKey(window_, 'Z') == GLFW_PRESS) {
    position -= up * deltaTime * speed;  // down
  }

  if (glfwGetKey(window_, 'O') == GLFW_PRESS) {
    position = glm::vec3(0, 0, 5);
    horizontalAngle = 3.14f;
    verticalAngle = 0.0f;
    initialFoV = 45.0f;
    direction =
        glm::vec3(cos(verticalAngle) * sin(horizontalAngle), sin(verticalAngle),
                  cos(verticalAngle) * cos(horizontalAngle));
    right = glm::vec3(sin(horizontalAngle - 3.14f / 2.0f), 0,
                      cos(horizontalAngle - 3.14f / 2.0f));
    up = glm::cross(right, direction);
  }

  if (glfwGetKey(window_, GLFW_KEY_SPACE) == GLFW_PRESS)
    args_->spin_shape = !args_->spin_shape;
  if (glfwGetKey(window_, 'M') == GLFW_PRESS)
    args_->move_window = !args_->move_window;
  if (glfwGetKey(window_, '.') == GLFW_PRESS) {  // '>'
    args_->sliding_step_factor *= 2;
  }
  if (glfwGetKey(window_, ',') == GLFW_PRESS) {  // '<'
    args_->sliding_step_factor /= 2;
    if (args_->sliding_step_factor == 0) {
      args_->sliding_step_factor = 1;
    }
  }

  float FoV =
      initialFoV;  // - 5 * glfwGetMouseWheel(); // Now GLFW 3 requires setting
                   // up a callback for this. It's a bit too complicated for
                   // this beginner's tutorial, so it's disabled instead.

  // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit
  // <-> 100 units
  *ProjectionMatrix = glm::perspective(
      glm::radians(FoV), (float)viewportW / (float)viewportH, 0.1f, 100.0f);
  // Camera matrix
  *ViewMatrix = glm::lookAt(
      position,  // Camera is here
      position +
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

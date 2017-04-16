#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <GlfwManager.hh>

std::shared_ptr<GlfwManager> GlfwManager::instance_;// = NULL;

// static std::shared_ptr<GlfwManager>
// get_manager_ptr(GLFWwindow* window) {
//     GlfwManager* m = glfwGetWindowUserPointer(window);
//     return std::static_pointer_cast<GlfwManager>(m);
// }

#define get_manager_ptr(Window)                                         \
    GlfwManager::instance()
//     do {                                                                \
//     GlfwManager* m = glfwGetWindowUserPointer(Window);                  \
//     std::static_pointer_cast<GlfwManager>()
//     } while (false)
    // reinterpret_cast<std::shared_ptr<GlfwManager>>(glfwGetWindowUserPointer(Window))

void
onFramebufferResize(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
    auto scene = get_manager_ptr(window)->scene();
    scene->resize(width, height);
}

// records how far the y axis has been scrolled
static void
onScroll(GLFWwindow* window, double deltaX, double deltaY) {
    auto mouse = get_manager_ptr(window)->getMouse();
    mouse->scrollY += deltaY;
    mouse->scrollX += deltaX;
}

static void
onError(int errorCode __unused, const char* msg) {
    throw std::runtime_error(msg);
}

static void
onKeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods) {
    auto events = get_manager_ptr(window)->getEvents();
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
    // std::cout << "key " << key << " (" << scancode << ", " << mods << ")" << std::endl;
}

void
GlfwManager::init() {
    glfwSetErrorCallback(onError);
    if (!glfwInit())
        throw std::runtime_error("!glfwInit");

    // open a window with GLFW
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

    GLFWmonitor* monitor = NULL;
    if (args_->fullscreen) {
        monitor = glfwGetPrimaryMonitor();
    }

    window_ = glfwCreateWindow(args_->width, args_->height, "void*", monitor, NULL);
    if (!window_)
        throw std::runtime_error("!glfwCreateWindow. Can your hardware handle OpenGL 3.2?");

    glfwSetWindowUserPointer(window_, this);
    glfwSetFramebufferSizeCallback(window_, onFramebufferResize);
    glfwSetKeyCallback(window_, onKeyEvent);

    // GLFW settings
    glfwSetInputMode(window_, GLFW_STICKY_KEYS, GL_TRUE);
    glfwSetCursorPos(window_, 0, 0);
    glfwSetScrollCallback(window_, onScroll);
    glfwMakeContextCurrent(window_);

    mouse_ = std::make_shared<GlfwMouse>();
    events_ = std::make_shared<GlfwKeyboardEvents>();

    glInit();
}

void
GlfwManager::glInit() {
    glewExperimental = GL_TRUE; //stops glew from crashing on OSX :-/
    if (glewInit() != GLEW_OK)
        throw std::runtime_error("!glewInit");

    // GLEW throws some errors, so discard all the errors so far
    glProcessErrors(true);

    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl
              << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl
              << "Vendor: " << glGetString(GL_VENDOR) << std::endl
              << "Renderer: " << glGetString(GL_RENDERER) << std::endl;

    if (!GLEW_VERSION_3_2)
        throw std::runtime_error("OpenGL 3.2 API is not available.");
}

void
GlfwManager::glProcessErrors(bool quiet) {
    while (true) {
        GLenum error = glGetError();
        if (error == GL_NO_ERROR)
            break;
        if (!quiet)
            std::cerr << "OpenGL Error " << error << std::endl;
    }
}

void
GlfwManager::run() {
    if (scene_->type() == SCENE_3D)
        glfwSetInputMode(window_, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    double lastTime = glfwGetTime();
    while (!glfwWindowShouldClose(window_)) {
        // process pending events
        events_->update();

        // update the scene based on the time elapsed since last update
        double thisTime = glfwGetTime();
        float elapsedTime = thisTime - lastTime;
        // auto self = get_manager_ptr(window);
        bool redraw = scene_->update(instance_, elapsedTime);
        lastTime = thisTime;

        if (redraw) {
            scene_->render();
            glfwSwapBuffers(window_);
        }

        glProcessErrors();

        if (events_->keyPressed(GLFW_KEY_ESCAPE))
            glfwSetWindowShouldClose(window_, GL_TRUE);
        if (events_->keyPressed('F'))
            toggleFullscreen();

        if (events_->keyPressed('H'))
            loadPrevFile();
        if (events_->keyPressed('L'))
            loadNextFile();
    }
    glfwTerminate();
}

GlfwKeyboardEvents::GlfwKeyboardEvents() {
    current_ = std::make_shared<GlfwKeyboardState>();
    previous_ = std::make_shared<GlfwKeyboardState>();
}

GlfwKeyboardEvents::~GlfwKeyboardEvents() {
}

bool GlfwKeyboardEvents::keyDown(int key) {
    return current_->keys[key];
}

bool GlfwKeyboardEvents::keyUp(int key) {
    return !current_->keys[key];
}

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
    current_->keys[key] = (action == GLFW_RELEASE) ? 0 : 1;
    current_->rawmods = mods;
}

void
GlfwMouse::getCursorPos() {
    glfwGetCursorPos(GlfwManager::instance()->window(), &x, &y);
}

void
GlfwMouse::setCursorPos() {
    glfwSetCursorPos(GlfwManager::instance()->window(), x, y);
}

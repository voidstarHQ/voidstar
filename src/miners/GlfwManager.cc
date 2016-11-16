#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <GlfwManager.hh>

GlfwManager *GlfwManager::instance_ = 0;

// records how far the y axis has been scrolled
static void
OnScroll(GLFWwindow* window, double deltaX, double deltaY) {
    auto mouse = GlfwManager::instance()->getMouse();
    mouse->scrollY += deltaY;
    mouse->scrollX += deltaX;
}

static void
OnError(int errorCode, const char* msg) {
    throw std::runtime_error(msg);
}

void GlfwManager::init()
{
    glfwSetErrorCallback(OnError);
    if (!glfwInit())
        throw std::runtime_error("!glfwInit");

    // open a window with GLFW
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWmonitor* monitor = 0;
    if (args_->fullscreen) {
        monitor = glfwGetPrimaryMonitor();
    }

    window_ = glfwCreateWindow(args_->width, args_->height, "points", monitor, NULL);
    if (!window_)
        throw std::runtime_error("!glfwCreateWindow. Can your hardware handle OpenGL 3.2?");

    // GLFW settings
    glfwSetInputMode(window_, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPos(window_, 0, 0);
    glfwSetScrollCallback(window_, OnScroll);
    glfwMakeContextCurrent(window_);

    mouse_ = new GlfwMouse();
    events_ = new GlfwEvents();
}

void GlfwManager::run()
{
    double lastTime = glfwGetTime();
    while (!glfwWindowShouldClose(window_)) {
        // process pending events
        glfwPollEvents();

        // update the scene based on the time elapsed since last update
        double thisTime = glfwGetTime();
        float elapsedTime = thisTime - lastTime;
        bool redraw = scene_->update(elapsedTime);
        lastTime = thisTime;

        if (redraw) {
            scene_->render();
            glfwSwapBuffers(window_);
        }

        scene_->processErrors();

        if (glfwGetKey(window_, GLFW_KEY_ESCAPE))
            glfwSetWindowShouldClose(window_, GL_TRUE);
    }
    glfwTerminate();
}

bool GlfwEvents::keyPressed(int key) {
    return glfwGetKey(GlfwManager::instance()->window(), key);
}

void GlfwMouse::getCursorPos() {
    glfwGetCursorPos(GlfwManager::instance()->window(), &x, &y);
}

void GlfwMouse::setCursorPos() {
    glfwSetCursorPos(GlfwManager::instance()->window(), x, y);
}

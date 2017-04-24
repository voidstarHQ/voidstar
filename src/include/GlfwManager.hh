#pragma once

#include <bitset>
#include <memory>

#include <GLFW/glfw3.h>

#include <Types.hh>
#include <Manager.hh>

class GlfwManager;

struct GlfwModifiers {
    int shift:1;
    int ctrl:1;
    int alt:1;
    int super:1;
} __attribute__((packed));

struct GlfwKeyboardState {
    std::bitset<512> keys;
    union {
        int rawmods;
        GlfwModifiers mods;
    };

    void copy(const std::shared_ptr<GlfwKeyboardState> state) {
        keys = state->keys;
        rawmods = state->rawmods;
    }
};

class GlfwKeyboardEvents : public Events {
public:
    GlfwKeyboardEvents();
    virtual ~GlfwKeyboardEvents();

    virtual bool keyPressed(int key);
    virtual bool keyReleased(int key);
    virtual bool keyDown(int key);
    virtual bool keyUp(int key);

    virtual void update();

    void process(int key, int scancode, int action, int mods);

//protected:
    std::shared_ptr<GlfwKeyboardState> current_;
    std::shared_ptr<GlfwKeyboardState> previous_;
};

class GlfwMouse : public Mouse {
public:
    virtual void getCursorPos();
    virtual void setCursorPos();
};

class GlfwManager : public Manager {
// private:
public:
    GlfwManager(std::shared_ptr<Arguments> args)
        : Manager(args)
        {}
public:
    virtual ~GlfwManager() {}

    virtual void init();
    virtual void run();

    virtual std::shared_ptr<Events> getEvents() { return events_; }
    virtual std::shared_ptr<Mouse> getMouse() { return mouse_; }

    GLFWwindow* window() { return window_; }

    // TODO: move these in an OpenGl backend
    void glInit();
    void glProcessErrors(bool quiet=false);

    static std::shared_ptr<GlfwManager>
    instance(std::shared_ptr<Arguments> args) {
        if (instance_ || !args)
            throw std::runtime_error("Bad call to instance of GlfwManager");
        instance_ = std::make_shared<GlfwManager>(args);
        return instance_;
    }

    static std::shared_ptr<GlfwManager>
    instance() {
        if (!instance_)
            throw std::runtime_error("GlfwManager wasn't previously instanciated");
        return instance_;
    }

    void
    toggleFullscreen() {
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

    bool slide_window() {
        bool ret = false;
        if (events_->keyDown(GLFW_KEY_LEFT)) {
            ret = true;
            slide_window_left();
        }
        else if (events_->keyDown(GLFW_KEY_RIGHT)) {
            ret = true;
            slide_window_right();
        }
        if (events_->keyDown(GLFW_KEY_UP)) {
            ret = true;
            slide_window_up();
        }
        else if (events_->keyDown(GLFW_KEY_DOWN)) {
            ret = true;
            slide_window_down();
        }
        return ret;
    }

protected:
    static std::shared_ptr<GlfwManager> instance_;
    GLFWwindow* window_;
    std::shared_ptr<GlfwKeyboardEvents> events_;
    std::shared_ptr<GlfwMouse> mouse_;
};

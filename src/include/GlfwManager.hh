#pragma once

#include <iostream>
#include <bitset>

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

    void copy(const GlfwKeyboardState* state) {
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
    GlfwKeyboardState *current_;
    GlfwKeyboardState *previous_;
};

class GlfwMouse : public Mouse {
public:
    virtual void getCursorPos();
    virtual void setCursorPos();
};

class GlfwManager : public Manager {
public:
    GlfwManager(Arguments* args) : Manager(args) {
        if (instance_)
            throw std::runtime_error("GlfwManager was previously instanciated");
        instance_ = this;
    }
    virtual ~GlfwManager() {}

    virtual void init();
    virtual void run();

    virtual Events* getEvents(int id=0) { (void)id; return events_; }
    virtual Mouse* getMouse(int id=0) { (void)id; return mouse_; }

    GLFWwindow* window() { return window_; }

    // TODO: move these in an OpenGl backend
    void glInit();
    void glProcessErrors(bool quiet=false);

    static GlfwManager*
    instance() {
        if (!instance_)
            throw std::runtime_error("GlfwManager wasn't previously instanciated");
        return instance_;
    }

    void
    toggleFullscreen() {
        int w, h;
        fullscreen_ = !fullscreen_;
        if (!fullscreen_) {
            const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
            glfwSetWindowPos(window_, 0, 0);
            w = mode->width;
            h = mode->height;
        } else {
            w = static_cast<int>(args_->width);
            h = static_cast<int>(args_->height);
        }
        std::cout << "glfwSetWindowSize " << w << 'x' << h << std::endl;
        glfwSetWindowSize(window_, w, h);
    }

protected:
    static GlfwManager* instance_;
    GLFWwindow* window_;
    GlfwKeyboardEvents* events_;
    GlfwMouse* mouse_;
};

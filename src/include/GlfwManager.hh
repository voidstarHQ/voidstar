#pragma once

#include <iostream>

#include <GLFW/glfw3.h>

#include <Types.hh>
#include <Manager.hh>

class GlfwManager;

class GlfwEvents : public Events {
public:
    virtual bool keyPressed(int key);
    virtual bool keyReleased(int key);
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
    GlfwEvents* events_;
    GlfwMouse* mouse_;
};

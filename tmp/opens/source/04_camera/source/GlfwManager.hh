#pragma once

#include <stdexcept>
#include <GLFW/glfw3.h>

#include "Manager.hh"

class GlfwManager;

class GlfwEvents : public Events {
public:
    virtual bool keyPressed(int key);
};

class GlfwMouse : public Mouse {
public:
    virtual void getCursorPos();
    virtual void setCursorPos();
};

class GlfwManager : public Manager {
public:
    GlfwManager(Arguments *args) : Manager(args) {
        if (instance_)
            throw std::runtime_error("GlfwManager was previously instanciated");
        instance_ = this;
    }
    virtual ~GlfwManager() {}

    virtual void init();
    virtual void run();

    virtual Events *getEvents(int id=0) { return events_; }
    virtual Mouse *getMouse(int id=0) { return mouse_; }

    GLFWwindow *window() { return window_; }

    static GlfwManager *instance() {
        if (!instance_)
            throw std::runtime_error("GlfwManager wasn't previously instanciated");
        return instance_;
    }

protected:
    static GlfwManager *instance_;
    GLFWwindow* window_;
    GlfwEvents *events_;
    GlfwMouse *mouse_;
};


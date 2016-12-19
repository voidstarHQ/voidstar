#pragma once

struct Events {
public:
    virtual ~Events() {}
    virtual bool keyPressed(int key) = 0;
    virtual bool keyReleased(int key) = 0;
    virtual bool keyUp(int key) = 0;
    virtual bool keyDown(int key) = 0;
    virtual void update() = 0;
};

struct Mouse {
    virtual ~Mouse() {}
    virtual void getCursorPos() = 0;
    void getCursorPos(double& x, double& y) {
        getCursorPos();
        x = this->x;
        y = this->y;
    }
    virtual void setCursorPos() = 0;
    void setCursorPos(double x, double y) {
        this->x = x;
        this->y = y;
        setCursorPos();
    }

    double x;
    double y;
    double sensitivity = 0.1f;
    double scrollX;
    double scrollY;
    double zoomSensitivity = -0.2f;
};


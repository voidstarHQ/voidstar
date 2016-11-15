#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <Scene.hh>
#include <Algorithm2D.hh>

class Scene2D : public Scene {
public:
    Scene2D(Manager* manager) : Scene(manager) {}
    virtual ~Scene2D() { unload(); }

    virtual void init();
    virtual void load(Algorithm2D* algorithm);
    virtual void unload() {
        delete[] vertices_;
        delete[] colors_;
    }
    virtual bool update(float elapsedTime);
    virtual void render();
    virtual void processErrors(bool quiet=false);
protected:
    GLfloat* vertices_;
    GLfloat* colors_;
};

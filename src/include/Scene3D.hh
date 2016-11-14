#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <Scene.hh>
#include <Algorithm3D.hh>

class Scene3D : public Scene {
public:
    Scene3D(Manager* manager) : Scene(manager) {}
    virtual ~Scene3D() { unload(); }

    virtual void init();
    virtual void load(Algorithm3D* algorithm);
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

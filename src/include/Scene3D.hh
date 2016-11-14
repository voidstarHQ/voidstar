#pragma once

#include <Scene.hh>

class Scene3D : public Scene {
public:
    Scene3D(Manager* manager) : Scene(manager) {}
    virtual ~Scene3D() {}

    virtual void init();
    virtual void load(Algorithm* algorithm);
    virtual void unload();
    virtual bool update(float elapsedTime);
    virtual void render();
    virtual void processErrors(bool quiet=false);
};

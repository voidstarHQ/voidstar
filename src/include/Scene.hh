#pragma once

#include <cstddef>
#include <iostream>

#include <GL/glew.h>
#define GLM_FORCE_RADIANS
// functions taking degrees as a parameter are deprecated
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <tdogl/Camera.h>

#include <Algorithm.hh>

class Manager;

class Scene {
public:
    Scene(Manager* manager, SceneType type)
        : manager_(manager), type_(type), algo_(0) {}
    virtual ~Scene() {}

    virtual void init() = 0;
    virtual bool update(float elapsedTime) = 0;
    virtual void render() = 0;
    virtual void load(Algorithm* algo);
    virtual void unload();
    virtual void reload();

    virtual void resize(size_t width, size_t height) {
        width_ = width;
        height_ = height;
        aspect_ratio_ = static_cast<float>(width) / static_cast<float>(height);
        std::cout << "aspect: " << aspect_ratio_
                  << " (" << width_ << 'x' << height_ << ')' << std::endl;
        camera_.setViewportAspectRatio(aspect_ratio_);
    }

    Algorithm* algorithm() { return algo_; }
    static Scene* forAlgo(Manager* manager, Algorithm* algo);

protected:
    Manager* manager_;
    SceneType type_;
    Algorithm* algo_;
    tdogl::Camera camera_;

    size_t width_;
    size_t height_;
    float aspect_ratio_;
};

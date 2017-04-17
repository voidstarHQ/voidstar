#pragma once

#include <cstddef>
#include <memory>
#include <iostream>

#include <GL/glew.h>
#define GLM_FORCE_RADIANS
// functions taking degrees as a parameter are deprecated
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <tdogl/Camera.h>

#include <Algorithm.hh>
#include <Arguments.hh>
#include <Manager.hh>

class Manager;

class Scene {
public:
    Scene(SceneType type)
        : type_(type), algo_(0)
        {}
    virtual ~Scene() {}

    virtual void init(std::shared_ptr<Arguments> args) = 0;
    virtual bool update(std::shared_ptr<Manager> manager, float elapsedTime) = 0;
    virtual void render() = 0;
    virtual void load(std::shared_ptr<Algorithm> algo);
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

    inline SceneType type() const { return type_; }
    std::shared_ptr<Algorithm> algorithm() { return algo_; }
    static std::shared_ptr<Scene> with_algo(std::shared_ptr<Arguments> args, std::shared_ptr<Algorithm> algo);

protected:
    SceneType type_;
    std::shared_ptr<Algorithm> algo_;
    tdogl::Camera camera_;

    size_t width_;
    size_t height_;
    float aspect_ratio_;
};

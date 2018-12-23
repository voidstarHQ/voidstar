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
#include <Algo2D.hh>
#include <Algo3D.hh>
#include <Arguments.hh>
#include <Manager.hh>

class Manager;

enum SceneType {
    SCENE_UNDEFINED,
    SCENE_2D,
    SCENE_3D,
};

class Scene {
public:
    Scene(SceneType type)
        : type_(type)
        {}
    virtual ~Scene() {}

    virtual void init(std::shared_ptr<Arguments> args) = 0;
    virtual bool update(std::shared_ptr<Manager> manager, float elapsedTime) = 0;
    virtual void render() = 0;

    virtual void load(std::shared_ptr<Algo2D> algo) {
        if (algo2D_ && algo2D_ != algo)
            std::cerr << "deleting 2D algo" << std::endl;
        algo2D_ = algo;
    }
    virtual void load(std::shared_ptr<Algo3D> algo) {
        if (algo3D_ && algo3D_ != algo)
            std::cerr << "deleting 3D algo" << std::endl;
        algo3D_ = algo;
    }

    virtual void unload() {}
    virtual void reload() {}

    virtual void resize(int viewport_width, int viewport_height) {
        float aspect_ratio = static_cast<float>(viewport_width) / static_cast<float>(viewport_height);
        std::cout << "aspect: " << aspect_ratio
                  << " (" << viewport_width << 'x' << viewport_height << ')' << std::endl;
        camera_.setViewportAspectRatio(aspect_ratio);
    }

    inline SceneType type() const { return type_; }
    std::shared_ptr<Algorithm> algorithm() const {
        if (algo3D_)
            return static_cast<const std::shared_ptr<Algorithm>>(algo3D_);
        return static_cast<const std::shared_ptr<Algorithm>>(algo2D_);
    }

    static std::shared_ptr<Scene> with_algo(const std::shared_ptr<Arguments> args, const std::shared_ptr<Algo2D> algo);
    static std::shared_ptr<Scene> with_algo(const std::shared_ptr<Arguments> args, const std::shared_ptr<Algo3D> algo);

protected:
    SceneType type_;
    std::shared_ptr<Algo2D> algo2D_;
    std::shared_ptr<Algo3D> algo3D_;
    tdogl::Camera camera_;
};

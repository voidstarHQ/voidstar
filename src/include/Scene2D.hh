#pragma once

#include <tdogl/Program.h>

#include <Scene.hh>
#include <Algo2D.hh>

class Scene2D : public Scene {
public:
    Scene2D()
        : Scene(SCENE_2D),
          vao_(0), vbo_(0),
          width_(256), height_(256),
          n_points_(width_ * height_),
          colors_id_(0)
        {
            vertices_.reserve(2 * n_points_);
            colors_.reserve(4 * n_points_);
        }
    virtual ~Scene2D() { unload(); }

    virtual void init(std::shared_ptr<Arguments> args);
    virtual void load(std::shared_ptr<Algorithm> algo);
    virtual void unload();
    virtual void reload();
    virtual bool update(std::shared_ptr<Manager> manager, float elapsedTime);
    virtual void render();
private:
    void load_shaders();
    void load_buffers();
    void reset_points() {
        vertices_ = Floats(vertices_.size());
        colors_ = Floats(colors_.size());
    }

protected:
    GLuint vao_;
    GLuint vbo_;

    size_t  width_;
    size_t  height_;
    size_t  n_points_;

    GLuint colors_id_;
    Floats vertices_;
    Floats colors_;

    std::shared_ptr<tdogl::Program> program_;
};

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
          vertices_size_(n_points_ * 2 * sizeof (GLfloat)),
          colors_size_(n_points_ * 4 * sizeof (GLfloat)),
          colors_id_(0),
          vertices_(std::make_unique<GLfloat[]>(vertices_size_)),
          colors_(std::make_unique<GLfloat[]>(colors_size_)),
          program_(NULL)
        {}
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
        colors_ = std::make_unique<GLfloat[]>(colors_size_);
        vertices_ = std::make_unique<GLfloat[]>(vertices_size_);
    }

protected:
    GLuint vao_;
    GLuint vbo_;

    size_t  width_;
    size_t  height_;
    size_t  n_points_;

    size_t   vertices_size_;
    size_t   colors_size_;
    GLuint   colors_id_;
    std::unique_ptr<GLfloat[]> vertices_;
    std::unique_ptr<GLfloat[]> colors_;

    std::shared_ptr<tdogl::Program> program_;
};

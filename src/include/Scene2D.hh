#pragma once

#include <tdogl/Program.h>

#include <Scene.hh>
#include <Algo2D.hh>

class Scene2D : public Scene {
public:
    Scene2D(Manager* manager)
        : Scene(manager, SCENE_2D),
          vao_(0), vbo_(0),
          width_(256), height_(256),
          n_points_(width_ * height_),
          vertices_size_(n_points_ * 2 * sizeof (GLfloat)),
          colors_size_(n_points_ * 4 * sizeof (GLfloat)),
          colors_id_(0),
          vertices_(new GLfloat[vertices_size_]),
          colors_(new GLfloat[colors_size_]),
          program_(NULL)
        {}
    virtual ~Scene2D() {
        delete[] vertices_;
        delete[] colors_;
        delete program_;
    }

    virtual void init();
    virtual void load(Algorithm* algo);
    virtual bool update(float elapsedTime);
    virtual void render();
private:
    void load_shaders();
    void load_buffers();
protected:
    GLuint vao_;
    GLuint vbo_;

    size_t  width_;
    size_t  height_;
    size_t  n_points_;

    size_t   vertices_size_;
    size_t   colors_size_;
    GLuint   colors_id_;
    GLfloat* vertices_;
    GLfloat* colors_;

    tdogl::Program* program_;
};

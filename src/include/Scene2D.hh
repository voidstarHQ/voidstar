#pragma once

#include <tdogl/Program.h>

#include <Scene.hh>
#include <Algo2D.hh>

struct Scene2DContext {
    Scene2DContext(size_t w, size_t h)
        : vao(0), vbo(0),
          width(w), height(h),
          n_points(width * height),
          vertices_size(n_points * 3 * sizeof (GLfloat)),
          colors_size(n_points * 4 * sizeof (GLfloat)),
          colors_id(0),
          vertices(new GLfloat[vertices_size]),
          colors(new GLfloat[colors_size]),
          degreesRotated(0.0f), program(NULL)
        {}
    ~Scene2DContext() {
        delete[] vertices;
        delete[] colors;
        delete program;
    }

    GLuint vao;
    GLuint vbo;

    size_t  width;
    size_t  height;
    size_t  n_points;

    size_t   vertices_size;
    size_t   colors_size;
    GLuint   colors_id;
    GLfloat* vertices;
    GLfloat* colors;

    GLfloat degreesRotated;
    tdogl::Program* program;
};

class Scene2D : public Scene {
public:
    Scene2D(Manager* manager) : Scene(manager, SCENE_2D), ctx_(256, 256) {}
    virtual ~Scene2D() {}

    virtual void init();
    virtual void load(Algorithm* algo);
    virtual bool update(float elapsedTime);
    virtual void render();
private:
    void load_shaders();
    void load_buffers();
protected:
    Scene2DContext ctx_;
};

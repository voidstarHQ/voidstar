#pragma once

#include <tdogl/Program.h>

#include <Scene.hh>
#include <Algo3D.hh>

struct Scene3DContext {
    Scene3DContext(size_t w, size_t h, size_t d)
        : vao(0), vbo(0), elements(0),
          width(w), height(h), depth(d),
          n_points(width * height * depth),
          vertices_size(n_points * 3 * sizeof (GLfloat)),
          colors_size(n_points * 4 * sizeof (GLfloat)),
          colors_id(0),
          vertices(std::make_shared<GLfloat>(vertices_size)),
          colors(std::make_shared<GLfloat>(colors_size)),
          degreesRotated(0.0f), rotationEnabled(false), program(NULL)
        {}
    ~Scene3DContext() {}

    void reset_points() {
        colors = std::make_shared<GLfloat>(colors_size);
        vertices = std::make_shared<GLfloat>(vertices_size);
        selected.clear();
    }

    GLuint vao;
    GLuint vbo;
    GLuint elements;

    size_t  width;
    size_t  height;
    size_t  depth;
    size_t  n_points;

    VertIndices selected;
    size_t   vertices_size;
    size_t   colors_size;
    GLuint   colors_id;
    std::shared_ptr<GLfloat> vertices;
    std::shared_ptr<GLfloat> colors;

    GLfloat degreesRotated;
    bool rotationEnabled;
    std::shared_ptr<tdogl::Program> program;
};

class Scene3D : public Scene {
public:
    Scene3D()
        : Scene(SCENE_3D), ctx_(256, 256, 256)
        {}
    virtual ~Scene3D() { unload(); }

    virtual void init(std::shared_ptr<Arguments> args);
    virtual void load(std::shared_ptr<Algorithm> algo);
    virtual void unload();
    virtual void reload();
    virtual bool update(std::shared_ptr<Manager> manager, float elapsedTime);
    virtual void render();
private:
    void load_shaders();
    void load_buffers();
protected:
    Scene3DContext ctx_;
};

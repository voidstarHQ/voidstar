#pragma once

#include <tdogl/Program.h>

#include <Scene.hh>
#include <Algo3D.hh>

struct Scene3DContext {
    Scene3DContext(size_t w, size_t h, size_t d)
        : vao(0), vbo(0), elements(0),
          width(w), height(h), depth(d),
          n_points(width * height * depth),
          colors_id(0),
          degreesRotated(0.0f), rotationEnabled(false)
        {
            vertices.reserve(3 * n_points);
            colors.reserve(4 * n_points);
        }
    ~Scene3DContext() {}

    void reset_points() {
        vertices = Floats(vertices.size());
        colors = Floats(colors.size());
        selected.clear();
    }

    GLuint vao;
    GLuint vbo;
    GLuint elements;

    size_t  width;
    size_t  height;
    size_t  depth;
    size_t  n_points;

    GLuint colors_id;
    Floats vertices;
    Floats colors;
    VertIndices selected;

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

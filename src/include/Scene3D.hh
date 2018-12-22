#pragma once

#include <tdogl/Program.h>

#include <Scene.hh>
#include <Algo3D.hh>

class Scene3D : public Scene {
public:
    Scene3D()
        : Scene(SCENE_3D),
          vao_(0), vbo_(0), elements_(0), colors_id_(0),
          width_(256), height_(256), depth_(256),
          n_points_(width_ * height_ * depth_),
          vertices_(3 * n_points_), colors_(3 * n_points_),
          degrees_rotated_(0.0f), degrees_per_second_(10.0f), move_speed_(2.0f)
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
    void reset_points() {
        vertices_ = Floats(3 * n_points_);
        colors_ = Floats(3 * n_points_);
        indices_.clear();
    }
    void apply() {
        auto algo = std::static_pointer_cast<Algo3D>(algo_);
        algo->apply(vertices_, colors_, indices_, width_, height_, depth_)
            || std::cerr << "!apply" << std::endl;
        std::cout << "#indices: " << Manager::size2str(indices_.size()) << std::endl;
        load_buffers();
    }

protected:
    GLuint vao_;
    GLuint vbo_;
    GLuint elements_;
    GLuint colors_id_;

    size_t  width_;
    size_t  height_;
    size_t  depth_;
    size_t  n_points_;

    Floats vertices_;
    Floats colors_;
    VertIndices selected_;
    VertIndices indices_;

    GLfloat degrees_rotated_;
    GLfloat degrees_per_second_;
    GLfloat move_speed_;
    std::shared_ptr<tdogl::Program> program_;
};

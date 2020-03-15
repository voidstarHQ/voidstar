#pragma once

#include "src/include/Algo3D.h"
#include "src/include/Scene.h"

class Scene3D : public Scene {
 public:
  Scene3D()
      : Scene(SCENE_3D),
        width_(256),
        height_(256),
        depth_(256),
        n_points_(width_ * height_ * depth_) {
    reset_points();
  }
  virtual ~Scene3D() { unload(); }

  virtual void init(std::shared_ptr<Arguments> args) override;
  virtual void load(std::shared_ptr<Algorithm> algo) override;
  virtual void unload() override;
  virtual void reload() override;
  virtual bool update(std::shared_ptr<Manager> manager,
                      float elapsedTime) override;
  virtual void render() override;

 private:
  void load_shaders();
  void load_buffers();
  void reset_points() {
    vertices_ = Floats(3 * n_points_);
    colors_ = Floats(3 * n_points_);
    indices_.clear();
  }

 protected:
  GLuint vao_ = 0;
  GLuint vbo_ = 0;
  GLuint cbo_ = 0;
  GLuint ebo_ = 0;

  GLuint uMVP_ = 0;

  size_t width_;
  size_t height_;
  size_t depth_;
  size_t n_points_;

  Floats vertices_;
  Floats colors_;
  VertIndices selected_;
  VertIndices indices_;

  GLfloat degrees_rotated_ = 0;
  GLfloat degrees_per_second_ = 10;
  GLfloat move_speed_ = 2;
};

#include "voidstar/algos_2d/algo_2d.h"
#include "voidstar/scenes/scene.h"
#include "voidstar/shaders/fragment.h"
#include "voidstar/shaders/vertex_2d.h"

class Scene2D : public Scene {
 public:
  Scene2D()
      : Scene("2D"), width_(256), height_(256), n_points_(width_ * height_) {
    reset_points();
  }
  virtual ~Scene2D() { unload(); }

  virtual void init(std::shared_ptr<Arguments> args) override;
  virtual void load(std::shared_ptr<Algorithm> algo) override;
  virtual void unload() override;
  virtual void reload() override;
  virtual bool update(float elapsedTime) override;
  virtual void render() override;

 private:
  void load_shaders();
  void load_buffers();
  void reset_points() {
    vertices_ = Floats(3 * n_points_);
    colors_ = Floats(3 * n_points_);
    // selected_.clear();
    indices_.clear();
  }

 protected:
  GLuint vao_ = 0;
  GLuint vbo_ = 0;
  GLuint cbo_ = 0;

  size_t width_;
  size_t height_;
  size_t n_points_;

  Floats vertices_;
  Floats colors_;
};
REGISTER_SCENE("2D", Scene2D);

void Scene2D::load_shaders() {
  // Build and compile our shader program
  GLint success;
  GLchar infoLog[512];

  // Vertex shader
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &shader__vertex_2d, NULL);
  glCompileShader(vertexShader);
  // Check for compile time errors
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    std::cerr << "Error compiling vertex shader:\n" << infoLog << std::endl;
    throw std::runtime_error("!glCompileShader");
  }

  // Fragment shader
  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &shader__fragment, NULL);
  glCompileShader(fragmentShader);
  // Check for compile time errors
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    std::cerr << "Error compiling fragment shader:\n" << infoLog << std::endl;
    throw std::runtime_error("!glCompileShader");
  }

  // Link shaders
  program_ = glCreateProgram();
  if (program_ == 0) throw std::runtime_error("!glCreateProgram");
  glAttachShader(program_, vertexShader);
  glAttachShader(program_, fragmentShader);
  glLinkProgram(program_);
  // Check for linking errors
  glGetProgramiv(program_, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(program_, 512, NULL, infoLog);
    std::cerr << "Error linking shaders:\n" << infoLog << std::endl;
    throw std::runtime_error("!glLinkProgram");
  }
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
  std::cerr << "Compiled shaders\n";
}

void Scene2D::load_buffers() {
  // make and bind the VAO
  glGenVertexArrays(1, &vao_);
  glBindVertexArray(vao_);

  // vertices
  glGenBuffers(1, &vbo_);
  glBindBuffer(GL_ARRAY_BUFFER, vbo_);
  glBufferData(GL_ARRAY_BUFFER, Size(vertices_), &vertices_[0], GL_STATIC_DRAW);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0,                    // layout = 0
                        2,                    // it's 2D points
                        GL_FLOAT,             // type
                        GL_FALSE,             // normalized?
                        0 * sizeof(GLfloat),  // stride
                        NULL                  // array buffer offset
  );

  // colors
  glGenBuffers(1, &cbo_);
  glBindBuffer(GL_ARRAY_BUFFER, cbo_);
  glBufferData(GL_ARRAY_BUFFER, Size(colors_), &colors_[0], GL_STATIC_DRAW);
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(1,                    // layout = 1
                        3,                    // size(RGB) = 3
                        GL_FLOAT,             // type
                        GL_FALSE,             // normalized?
                        0 * sizeof(GLfloat),  // stride
                        NULL                  // array buffer offset
  );

  // unbind the VAO
  glBindVertexArray(0);
}

void Scene2D::init(std::shared_ptr<Arguments> args) {
  resize(args->width, args->height);
}

void Scene2D::unload() {
  if (program_) {
    glDeleteBuffers(1, &vbo_);
    glDeleteBuffers(1, &cbo_);
    glDeleteVertexArrays(1, &vao_);
  }
}

void Scene2D::reload() {
  auto algo = std::static_pointer_cast<Algo2D>(algo_);
  reset_points();
  algo->apply(vertices_, colors_, width_, height_) || std::cerr << "!apply\n";
  glBindVertexArray(vao_);
  glBindBuffer(GL_ARRAY_BUFFER, cbo_);
  glBufferData(GL_ARRAY_BUFFER, Size(colors_), &colors_[0], GL_STATIC_DRAW);
  glBindVertexArray(0);
}

void Scene2D::load(std::shared_ptr<Algorithm> algorithm) {
  Scene::load(algorithm);
  auto algo = std::static_pointer_cast<Algo2D>(algorithm);

  glEnable(GL_PROGRAM_POINT_SIZE);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  load_shaders();
  algo->apply(vertices_, colors_, width_, height_) || std::cerr << "!apply\n";
  load_buffers();
}

bool Scene2D::update(float elapsedTime __unused) { return true; }

void Scene2D::render() {
  // bind the VAO
  glBindVertexArray(vao_);

  // draw the VAO
  glDrawArrays(GL_POINTS, 0, n_points_);

  // unbind the VAO and the program
  glBindVertexArray(0);
}

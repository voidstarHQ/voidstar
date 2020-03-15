#include "src/include/Scene3D.h"

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <stdexcept>

#include "src/include/GlfwManager.h"
#include "src/shaders/fragment.h"
#include "src/shaders/vertex_3d.h"

void Scene3D::load_shaders() {
  // Build and compile our shader program
  GLint success;
  GLchar infoLog[512];

  // Vertex shader
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &shader__vertex_3d, NULL);
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

void Scene3D::load_buffers() {
  // make and bind the VAO
  glGenVertexArrays(1, &vao_);
  glBindVertexArray(vao_);

  // vertices
  glGenBuffers(1, &vbo_);
  glBindBuffer(GL_ARRAY_BUFFER, vbo_);
  glBufferData(GL_ARRAY_BUFFER, Size(vertices_), &vertices_[0], GL_STATIC_DRAW);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0,                    // layout = 0
                        3,                    // it's 3D points
                        GL_FLOAT,             // type
                        GL_FALSE,             // normalized?
                        3 * sizeof(GLfloat),  // stride
                        NULL                  // array buffer offset
  );
  std::cerr << "Loaded " << vertices_.size() / 3 << " vertices.\n";

  // colors
  glGenBuffers(1, &cbo_);
  glBindBuffer(GL_ARRAY_BUFFER, cbo_);
  glBufferData(GL_ARRAY_BUFFER, Size(colors_), &colors_[0], GL_STATIC_DRAW);
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(1,                    // layout = 1
                        3,                    // size(RGB) = 3
                        GL_FLOAT,             // type
                        GL_FALSE,             // normalized?
                        3 * sizeof(GLfloat),  // stride
                        NULL                  // array buffer offset
  );
  std::cerr << "Loaded " << colors_.size() / 3 << " colors.\n";

  // indices
  const auto right = std::min(indices_.end(), 8192 + indices_.begin());
  selected_.assign(indices_.begin(), right);
  glGenBuffers(1, &ebo_);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, Size(selected_), &selected_[0],
               GL_STATIC_DRAW);
  std::cerr << "Loaded " << selected_.size() << " elements.\n";

  glBindVertexArray(0);  // Unbind VAO (it's always a good thing to unbind any
                         // buffer/array to prevent strange bugs)

  uMVP_ = glGetUniformLocation(program_, "uMVP");

  std::cerr << "Ready!\n";
}

void Scene3D::init(std::shared_ptr<Arguments> args) {
  resize(args->width, args->height);
}

void Scene3D::unload() {
  if (program_) {
    glDeleteVertexArrays(1, &vao_);
    glDeleteBuffers(1, &vbo_);
    glDeleteBuffers(1, &cbo_);
    glDeleteBuffers(1, &ebo_);
  }
}

void Scene3D::reload() {
  auto algo = std::static_pointer_cast<Algo3D>(algo_);
  reset_points();
  algo->apply(vertices_, colors_, indices_, width_, height_, depth_) ||
      std::cerr << "!apply\n";
  load_buffers();
  glBindVertexArray(vao_);
  glBindBuffer(GL_ARRAY_BUFFER, cbo_);
  glBufferData(GL_ARRAY_BUFFER, Size(colors_), &colors_[0], GL_STATIC_DRAW);
  glBindVertexArray(0);
}

void Scene3D::load(std::shared_ptr<Algorithm> algorithm) {
  Scene::load(algorithm);
  auto algo = std::static_pointer_cast<Algo3D>(algorithm);

  glEnable(GL_DEBUG_OUTPUT);

  // Enable depth test
  glEnable(GL_DEPTH_TEST);
  // Accept fragment if it closer to the camera than the former one
  glDepthFunc(GL_LESS);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  load_shaders();
  algo->apply(vertices_, colors_, indices_, width_, height_, depth_) ||
      std::cerr << "!apply\n";
  load_buffers();
}

bool Scene3D::update(std::shared_ptr<Manager> manager, float elapsedTime) {
  glm::mat4 projection, view;
  manager->computeMatricesFromInputs(&projection, &view);
  if (manager->args()->spin_shape) {
    degrees_rotated_ += elapsedTime * degrees_per_second_;
    while (degrees_rotated_ > 360.0f) degrees_rotated_ -= 360.0f;
  }
  // Model matrix : an identity matrix (model will be at the origin)
  glm::mat4 model = glm::mat4(1.0);
  model =
      glm::rotate(model, glm::radians(degrees_rotated_), glm::vec3(0, 1, 0));

  // Our ModelViewProjection : multiplication of our 3 matrices
  // Note matrix multiplication is not commutative
  glm::mat4 MVP = projection * view * model;
  glUniformMatrix4fv(uMVP_, 1, GL_FALSE, &MVP[0][0]);

  if (manager->args()->move_window || selected_.empty() ||
      manager->SlideWindow()) {
    if (manager->args()->move_window) manager->slide_window_right();
    bool slid = manager->slide_window(selected_, indices_);
    if (manager->args()->move_window && !slid)
      manager->args()->move_window = !manager->args()->move_window;
  }

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_);
  GlfwManager::glProcessErrors();
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, Size(selected_), &selected_[0],
               GL_STATIC_DRAW);
  GlfwManager::glProcessErrors();

  return true;
}

void Scene3D::render() {
  // bind the VAO
  glBindVertexArray(vao_);
  GlfwManager::glProcessErrors();

  // draw only the VAO's points we colored
  auto mM = std::minmax_element(selected_.begin(), selected_.end());
  glDrawRangeElements(GL_POINTS, *mM.first, *mM.second, selected_.size(),
                      GL_UNSIGNED_INT, NULL);

  GlfwManager::glProcessErrors();

  // unbind the VAO and the program
  glBindVertexArray(0);
  GlfwManager::glProcessErrors();
}

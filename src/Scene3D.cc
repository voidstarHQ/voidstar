#include "src/include/Scene3D.h"

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <stdexcept>

#include "src/include/GlfwManager.h"
#include "src/resources/shaders.h"

void Scene3D::load_shaders() {
  const std::vector<tdogl::Shader> shaders{
      tdogl::Shader(shader__vertex_3d, GL_VERTEX_SHADER),
      tdogl::Shader(shader__fragment, GL_FRAGMENT_SHADER)};
  program_ = std::make_shared<tdogl::Program>(shaders);
}

void Scene3D::load_buffers() {
  // make and bind the VAO
  glGenVertexArrays(1, &vao_);
  glGenBuffers(1, &vbo_);
  glBindVertexArray(vao_);

  glBindBuffer(GL_ARRAY_BUFFER, vbo_);
  glBufferData(GL_ARRAY_BUFFER, Size(vertices_), vertices_.data(),
               GL_STATIC_DRAW);
  // connect the xyz to the "vert" attribute of the vertex shader
  glVertexAttribPointer(0,                    // layout = 0
                        3,                    // it's triangles
                        GL_FLOAT,             // type
                        GL_FALSE,             // normalized?
                        3 * sizeof(GLfloat),  // stride
                        NULL                  // array buffer offset
  );
  glEnableVertexAttribArray(0);
  // Note that this is allowed, the call to glVertexAttribPointer
  // registered VBO as the currently bound vertex buffer object so
  // afterwards we can safely unbind
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  std::cerr << "Loaded " << vertices_.size() << " vertices.\n";

  // make and bind the VBO
  glGenBuffers(1, &colors_id_);
  glBindBuffer(GL_ARRAY_BUFFER, colors_id_);
  glBufferData(GL_ARRAY_BUFFER, Size(colors_), &colors_[0], GL_STATIC_DRAW);
  // 2nd attribute buffer
  glEnableVertexAttribArray(1);
  glBindBuffer(GL_ARRAY_BUFFER, colors_id_);
  glVertexAttribPointer(1,                    // layout = 1
                        3,                    // size
                        GL_FLOAT,             // type
                        GL_FALSE,             // normalized?
                        3 * sizeof(GLfloat),  // stride
                        NULL                  // array buffer offset
  );
  std::cerr << "Loaded " << colors_.size() << " colors.\n";

  // Load an initial set of points
  selected_.assign(indices_.begin(),
                   std::min(indices_.end(), 8192 + indices_.begin()));
  glGenBuffers(1, &ebo_);
  GlfwManager::glProcessErrors();
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_);
  GlfwManager::glProcessErrors();
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, Size(selected_), &selected_[0],
               GL_STATIC_DRAW);
  GlfwManager::glProcessErrors();
  std::cerr << "Loaded " << selected_.size() << " elements.\n";

  glBindVertexArray(0);  // Unbind VAO (it's always a good thing to unbind any
                         // buffer/array to prevent strange bugs)

  std::cerr << "Ready!\n";
}

void Scene3D::init(std::shared_ptr<Arguments> args) {
  resize(args->width, args->height);
}

void Scene3D::unload() {
  if (program_) {
    glDeleteVertexArrays(1, &vao_);
    glDeleteBuffers(1, &vbo_);
    glDeleteBuffers(1, &colors_id_);
    glDeleteBuffers(1, &ebo_);
  }
}

void Scene3D::reload() {
  auto algo = std::static_pointer_cast<Algo3D>(algo_);
  reset_points();
  algo->apply(vertices_, colors_, indices_, width_, height_, depth_) ||
      std::cerr << "!apply" << std::endl;
  load_buffers();
  glBindVertexArray(vao_);
  glBindBuffer(GL_ARRAY_BUFFER, colors_id_);
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
      std::cerr << "!apply" << std::endl;
  load_buffers();
}

bool Scene3D::update(std::shared_ptr<Manager> manager, float elapsedTime) {
  // auto mouse = manager->getMouse();
  // mouse->getCursorPos();
  // camera_.offsetOrientation(mouse->sensitivity * mouse->y,
  //                           mouse->sensitivity * mouse->x);
  // reset the mouse, so it doesn't go out of the window
  // mouse->setCursorPos(0, 0);
  // mouse->scrollY = 0.0;

  // bind the program (the shaders)
  program_->use();

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
  program_->setUniformMatrix4("uMVP", &MVP[0][0]);

  if (manager->args()->move_window || selected_.empty() ||
      manager->slide_window()) {
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
  // Clear the colorbuffer
  glClearColor(0, 0, 0, 0);
  // glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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

  program_->stopUsing();
}

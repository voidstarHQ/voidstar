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

  // std::cout << "load_buffers:: " << vbo_ << std::endl;
  glBindBuffer(GL_ARRAY_BUFFER, vbo_);
  glBufferData(GL_ARRAY_BUFFER, Algorithm::vsize(vertices_), vertices_.data(),
               GL_STATIC_DRAW);
  // connect the xyz to the "vert" attribute of the vertex shader
  glVertexAttribPointer(0,                    // layout = 0
                        3,                    // it's triangles
                        GL_FLOAT,             // type
                        GL_FALSE,             // normalized?
                        3 * sizeof(GLfloat),  // stride
                        (GLvoid*)0            // array buffer offset
  );
  glEnableVertexAttribArray(0);
  // Note that this is allowed, the call to glVertexAttribPointer
  // registered VBO as the currently bound vertex buffer object so
  // afterwards we can safely unbind
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  std::cerr << "Loaded vertices.\n";

  // make and bind the VBO
  glGenBuffers(1, &colors_id_);
  // std::cout << "load_buffers:: " << colors_id_ << std::endl;
  glBindBuffer(GL_ARRAY_BUFFER, colors_id_);
  glBufferData(GL_ARRAY_BUFFER, Algorithm::vsize(colors_), &colors_[0],
               GL_STATIC_DRAW);
  // 2nd attribute buffer
  glEnableVertexAttribArray(1);
  glBindBuffer(GL_ARRAY_BUFFER, colors_id_);
  glVertexAttribPointer(1,         // layout = 1
                        3,         // size
                        GL_FLOAT,  // type
                        GL_FALSE,  // normalized?
                        0,         // stride
                        NULL       // array buffer offset
  );
  std::cerr << "Loaded UV.\n";

  glGenBuffers(1, &ebo_);
  GlfwManager::glProcessErrors();
  // std::cout << "load_buffers:: " << ebo_ << std::endl;
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_);
  GlfwManager::glProcessErrors();
  // std::cout << "load_buffers:: size_selected = " << size_selected <<
  // std::endl;
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * selected_.size(),
               &selected_[0], GL_STATIC_DRAW);
  // glBufferData(GL_ELEMENT_ARRAY_BUFFER, size_selected, NULL, GL_STATIC_DRAW);
  GlfwManager::glProcessErrors();
  std::cerr << "Loaded elements.\n";

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
  // std::cout << "#indices: " << Manager::size2str(indices_.size()) <<
  // std::endl;
  load_buffers();
  glBindVertexArray(vao_);
  glBindBuffer(GL_ARRAY_BUFFER, colors_id_);
  glBufferData(GL_ARRAY_BUFFER, Algorithm::vsize(colors_), colors_.data(),
               GL_STATIC_DRAW);
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
  // std::cout << "#indices: " << Manager::size2str(indices_.size()) <<
  // std::endl;
  load_buffers();

  // camera_.setPosition(glm::vec3(0, -0.1, 3));
  // camera_.lookAt(glm::vec3(0,0,4));
  // camera_.setNearAndFarPlanes(0.1, 100.);
}

bool Scene3D::update(std::shared_ptr<Manager> manager, float elapsedTime) {
  if (manager->args()->spin_shape) {
    degrees_rotated_ += elapsedTime * degrees_per_second_;
    ;
    while (degrees_rotated_ > 360.0f) degrees_rotated_ -= 360.0f;
  }

  auto events = manager->getEvents();

  // move position of camera based on WASD keys, and XZ keys for up and down
  if (events->keyDown('S'))
    camera_.offsetPosition(elapsedTime * move_speed_ * -camera_.forward());
  else if (events->keyDown('W'))
    camera_.offsetPosition(elapsedTime * move_speed_ * camera_.forward());
  if (events->keyDown('A'))
    camera_.offsetPosition(elapsedTime * move_speed_ * -camera_.right());
  else if (events->keyDown('D'))
    camera_.offsetPosition(elapsedTime * move_speed_ * camera_.right());
  if (events->keyDown('Z'))
    camera_.offsetPosition(elapsedTime * move_speed_ * -glm::vec3(0, 1, 0));
  else if (events->keyDown('X'))
    camera_.offsetPosition(elapsedTime * move_speed_ * glm::vec3(0, 1, 0));
  if (events->keyPressed('O')) {
    camera_.setPosition(glm::vec3(0, -0.1, 3.8));
    camera_.lookAt(glm::vec3(0, 0, 4));
  }
  if (events->keyPressed(' '))
    manager->args()->spin_shape = !manager->args()->spin_shape;
  if (events->keyPressed('M'))
    manager->args()->move_window = !manager->args()->move_window;
  if (events->keyPressed('.')) {  // '>'
    manager->args()->sliding_step_factor *= 2;
  }
  if (events->keyPressed(',')) {  // '<'
    manager->args()->sliding_step_factor /= 2;
    if (manager->args()->sliding_step_factor == 0) {
      manager->args()->sliding_step_factor = 1;
    }
  }

  if (manager->args()->move_window || selected_.empty() ||
      manager->slide_window()) {
    if (manager->args()->move_window) manager->slide_window_right();
    bool slid = manager->slide_window(selected_, indices_);
    if (manager->args()->move_window && !slid)
      manager->args()->move_window = !manager->args()->move_window;
  }

  auto mouse = manager->getMouse();
  mouse->getCursorPos();
  camera_.offsetOrientation(mouse->sensitivity * mouse->y,
                            mouse->sensitivity * mouse->x);
  // reset the mouse, so it doesn't go out of the window
  mouse->setCursorPos(0, 0);
  mouse->scrollY = 0.0;

  // bind the program (the shaders)
  program_->use();

  // Model matrix : an identity matrix (model will be at the origin)
  glm::mat4 ProjectionMatrix, ViewMatrix, ModelMatrix = glm::mat4(1.0);
  manager->computeMatricesFromInputs(&ProjectionMatrix, &ViewMatrix);
  // Our ModelViewProjection : multiplication of our 3 matrices
  glm::mat4 MVP =
      ProjectionMatrix * ViewMatrix *
      ModelMatrix;  // Remember, matrix multiplication is the other way around
  program_->setUniformMatrix4("uMVP", &MVP[0][0]);

  return true;
}

void Scene3D::render() {
  // Clear the colorbuffer
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // program_->setUniform("camera", camera_.matrix());

  // // set the "model" uniform in the vertex shader, based on degreesRotated
  // auto rotated = glm::rotate(glm::mat4(), glm::radians(degrees_rotated_),
  // glm::vec3(0,1,0)); program_->setUniform("model", rotated);

  constexpr size_t SAMPLE = 999UL;

  // const VertIndices sels =

  VertIndices sels;
  sels.reserve(SAMPLE);
  for (int i = 0; i < SAMPLE; ++i) {
    sels.emplace_back(i);
  }
  selected_.assign(sels.begin(), sels.end());

  Floats cols;
  cols.reserve(4 * SAMPLE);
  for (int i = 0; i < 4 * SAMPLE; ++i) {
    cols.emplace_back(1.0f);
  }
  colors_.assign(cols.begin(), cols.end());

  // // send newly selected elements
  auto size_selected =
      sizeof(decltype(selected_)::value_type) * selected_.size();
  // std::cout << "render:: size_selected = " << size_selected << std::endl;
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, size_selected, selected_.data(),
               GL_STATIC_DRAW);
  GlfwManager::glProcessErrors();

  // std::ostringstream SSsels;
  // for (size_t i = 0; i < std::min(selected_.size(), SAMPLE); ++i) {
  //     // SSsels << ", " << selected_[i];
  // }
  // std::cout << SSsels.str() << " = SSsels" << std::endl;

  // bind the VAO
  glBindVertexArray(vao_);

  glDrawArrays(GL_POINTS, 0, n_points_);

  std::cerr << "#elements: " << selected_.size() << " " << selected_[0] << "-"
            << selected_.back() << std::endl;
  // // // draw only the VAO's points we colored
  // auto mM = std::minmax_element(selected_.begin(), selected_.end());
  // // std::cout << "render:: min:" << *mM.first << " max:" << *mM.second << "
  // #:" << selected_.size() << std::endl; glDrawRangeElements(GL_POINTS,
  // *mM.first, *mM.second, selected_.size(), GL_UNSIGNED_INT, NULL);
  // GlfwManager::glProcessErrors();

  // glDrawArrays(GL_POINTS, 0, n_points_);
  // glDrawElements(GL_POINTS, selected_.size(), GL_UNSIGNED_INT,
  // selected_.data());

  // unbind the VAO and the program
  glBindVertexArray(0);
  program_->stopUsing();
}

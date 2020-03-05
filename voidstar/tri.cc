#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h>

#include "include/GLFW/glfw3.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action,
                  int mode);

const GLuint WIDTH = 800, HEIGHT = 600;

const GLchar* vertexShaderSource = R"(
#version 330 core

// Input vertex data, different for all executions of this shader.
layout (location = 0) in vec3 vertexPosition_modelspace;

// Notice that the "1" here equals the "1" in glVertexAttribPointer
layout(location = 1) in vec3 vertexColor;

// Values that stay constant for the whole mesh.
uniform mat4 MVP;

out vec3 fragmentColor;

void main() {
  // Output position of the vertex, in clip space : MVP * position
  gl_Position =  MVP * vec4(vertexPosition_modelspace, 1);

  fragmentColor = vertexColor;
}
)";

const GLchar* fragmentShaderSource = R"(
#version 330 core

in vec3 fragmentColor;

out vec4 color;

void main() {
  // Output color = color specified in the vertex shader,
  // interpolated between all 3 surrounding vertices
  color = vec4(fragmentColor, 1);
}
)";

// The MAIN function, from here we start the application and run the game loop
int main() {
  // Init GLFW
  glfwInit();
  // Set all the required options for GLFW
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  // Create a GLFWwindow object that we can use for GLFW's functions
  GLFWwindow* window =
      glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
  glfwMakeContextCurrent(window);

  // Set the required callback functions
  glfwSetKeyCallback(window, key_callback);

  // Set this to true so GLEW knows to use a modern approach to retrieving
  // function pointers and extensions
  glewExperimental = GL_TRUE;
  // Initialize GLEW to setup the OpenGL Function pointers
  glewInit();

  // Define the viewport dimensions
  int width, height;
  glfwGetFramebufferSize(window, &width, &height);
  glViewport(0, 0, width, height);

  // Build and compile our shader program
  // Vertex shader
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);
  // Check for compile time errors
  GLint success;
  GLchar infoLog[512];
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
              << infoLog << std::endl;
  }
  // Fragment shader
  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);
  // Check for compile time errors
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
              << infoLog << std::endl;
  }
  // Link shaders
  GLuint shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);
  // Check for linking errors
  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
              << infoLog << std::endl;
  }
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive
  // vertices give a triangle. A cube has 6 faces with 2 triangles each, so this
  // makes 6*2=12 triangles, and 12*3 vertices
  static const GLfloat g_vertex_buffer_data[] = {
      -1.0f, -1.0f, -1.0f,                       // triangle 1 : begin
      -1.0f, -1.0f, 1.0f,  -1.0f, 1.0f,  1.0f,   // triangle 1 : end
      1.0f,  1.0f,  -1.0f,                       // triangle 2 : begin
      -1.0f, -1.0f, -1.0f, -1.0f, 1.0f,  -1.0f,  // triangle 2 : end
      1.0f,  -1.0f, 1.0f,  -1.0f, -1.0f, -1.0f, 1.0f,  -1.0f, -1.0f, 1.0f,
      1.0f,  -1.0f, 1.0f,  -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f,
      -1.0f, -1.0f, 1.0f,  1.0f,  -1.0f, 1.0f,  -1.0f, 1.0f,  -1.0f, 1.0f,
      -1.0f, -1.0f, 1.0f,  -1.0f, -1.0f, -1.0f, -1.0f, 1.0f,  1.0f,  -1.0f,
      -1.0f, 1.0f,  1.0f,  -1.0f, 1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  -1.0f,
      -1.0f, 1.0f,  1.0f,  -1.0f, 1.0f,  -1.0f, -1.0f, 1.0f,  1.0f,  1.0f,
      1.0f,  -1.0f, 1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  -1.0f, -1.0f,
      1.0f,  -1.0f, 1.0f,  1.0f,  1.0f,  -1.0f, 1.0f,  -1.0f, -1.0f, 1.0f,
      1.0f,  1.0f,  1.0f,  1.0f,  -1.0f, 1.0f,  1.0f,  1.0f,  -1.0f, 1.0f};
  GLuint VBO, VAO;
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and
  // attribute pointer(s).
  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data),
               g_vertex_buffer_data, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat),
                        (GLvoid*)0);
  glEnableVertexAttribArray(0);

  glBindBuffer(
      GL_ARRAY_BUFFER,
      0);  // Note that this is allowed, the call to glVertexAttribPointer
           // registered VBO as the currently bound vertex buffer object so
           // afterwards we can safely unbind

  // One color for each vertex. They were generated randomly.
  static GLfloat g_color_buffer_data[12 * 3 * 3];
  for (int v = 0; v < 12 * 3; ++v) {
    g_color_buffer_data[3 * v + 0] = 3.0f / v;
    g_color_buffer_data[3 * v + 1] = 4.0f / v;
    g_color_buffer_data[3 * v + 2] = 3.0f / v;
  }
  GLuint colorbuffer;
  glGenBuffers(1, &colorbuffer);
  glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data),
               g_color_buffer_data, GL_STATIC_DRAW);
  // 2nd attribute buffer : colors
  glEnableVertexAttribArray(1);
  glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
  glVertexAttribPointer(1,  // attribute. No particular reason for 1, but must
                            // match the layout in the shader.
                        3,  // size
                        GL_FLOAT,  // type
                        GL_FALSE,  // normalized?
                        0,         // stride
                        (void*)0   // array buffer offset
  );

  glBindVertexArray(0);  // Unbind VAO (it's always a good thing to unbind any
                         // buffer/array to prevent strange bugs)

  // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit
  // <-> 100 units
  glm::mat4 Projection = glm::perspective(
      glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);

  // Camera matrix
  glm::mat4 View = glm::lookAt(
      glm::vec3(4, 3, 3),  // Camera is at (4,3,3), in World Space
      glm::vec3(0, 0, 0),  // and looks at the origin
      glm::vec3(0, 1, 0)   // Head is up (set to 0,-1,0 to look upside-down)
  );

  // Model matrix : an identity matrix (model will be at the origin)
  glm::mat4 Model = glm::mat4(1.0f);
  // Our ModelViewProjection : multiplication of our 3 matrices
  glm::mat4 mvp =
      Projection * View *
      Model;  // Remember, matrix multiplication is the other way around

  // Get a handle for our "MVP" uniform
  // Only during the initialisation
  GLuint MatrixID = glGetUniformLocation(shaderProgram, "MVP");

  // Enable depth test
  glEnable(GL_DEPTH_TEST);
  // Accept fragment if it closer to the camera than the former one
  glDepthFunc(GL_LESS);

  // Game loop
  while (!glfwWindowShouldClose(window)) {
    // Check if any events have been activiated (key pressed, mouse moved etc.)
    // and call corresponding response functions
    glfwPollEvents();

    // Render

    // Clear the colorbuffer
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Send our transformation to the currently bound shader, in the "MVP"
    // uniform
    // This is done in the main loop since each model will have a different MVP
    // matrix (At least for the M part)
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &mvp[0][0]);

    // Draw our first triangle
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawArrays(
        GL_TRIANGLES, 0,
        12 * 3);  // 12*3 indices starting at 0 -> 12 triangles -> 6 squares
    glBindVertexArray(0);

    // Swap the screen buffers
    glfwSwapBuffers(window);
  }
  // Properly de-allocate all resources once they've outlived their purpose
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  // Terminate GLFW, clearing any resources allocated by GLFW.
  glfwTerminate();
  return 0;
}

// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action,
                  int mode) {
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GL_TRUE);
}

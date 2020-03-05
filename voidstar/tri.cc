#include <cstdint>
#include <fstream>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <vector>

#define GLEW_STATIC
#include <GL/glew.h>

#include "include/GLFW/glfw3.h"

bool readFile(const int to_read, const char* filename,
              std::vector<uint8_t>& vec) {
  std::ifstream is(filename, std::ios::binary);
  if (!is) return false;

  // Stop eating new lines in binary mode!!!
  is.unsetf(std::ios::skipws);

  is.seekg(0, std::ios::end);
  std::streampos size = is.tellg();
  is.seekg(0, std::ios::beg);
  if (size < to_read) return false;

  vec.reserve(to_read);
  is.read(reinterpret_cast<char*>(vec.data()), to_read);
  if (!is) return false;
  return true;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action,
                  int mode);

const GLuint WIDTH = 800, HEIGHT = 600;

const GLchar* vertexShaderSource = R"(
#version 330 core

// Input vertex data, different for all executions of this shader.
layout (location = 0) in vec3 vertexPosition_modelspace;
layout (location = 1) in vec2 vertexUV;

// Output data ; will be interpolated for each fragment.
out vec2 UV;

// Values that stay constant for the whole mesh.
uniform mat4 MVP;

out vec3 fragmentColor;

void main() {
  // Output position of the vertex, in clip space : MVP * position
  gl_Position =  MVP * vec4(vertexPosition_modelspace, 1);

  // UV of the vertex. No special space for this one.
  UV = vertexUV;
}
)";

const GLchar* fragmentShaderSource = R"(
#version 330 core

// Interpolated values from the vertex shaders
in vec2 UV;

in vec3 fragmentColor;

// Values that stay constant for the whole mesh.
uniform sampler2D myTextureSampler;

out vec3 color;

void main() {
  // Output color = color of the texture at the specified UV
  color = texture( myTextureSampler, UV ).rgb;
}
)";

// The MAIN function, from here we start the application and run the game loop
int main(int argc, const char* argv[]) {
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
  static const GLfloat vertices[] = {
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
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat),
                        (GLvoid*)0);
  glEnableVertexAttribArray(0);
  glBindBuffer(
      GL_ARRAY_BUFFER,
      0);  // Note that this is allowed, the call to glVertexAttribPointer
           // registered VBO as the currently bound vertex buffer object so
           // afterwards we can safely unbind

  // Two UV coordinatesfor each vertex. They were created with Blender. You'll
  // learn shortly how to do this yourself.
  static const GLfloat uv[] = {
      0.000059f, 1.0f - 0.000004f, 0.000103f, 1.0f - 0.336048f,
      0.335973f, 1.0f - 0.335903f, 1.000023f, 1.0f - 0.000013f,
      0.667979f, 1.0f - 0.335851f, 0.999958f, 1.0f - 0.336064f,
      0.667979f, 1.0f - 0.335851f, 0.336024f, 1.0f - 0.671877f,
      0.667969f, 1.0f - 0.671889f, 1.000023f, 1.0f - 0.000013f,
      0.668104f, 1.0f - 0.000013f, 0.667979f, 1.0f - 0.335851f,
      0.000059f, 1.0f - 0.000004f, 0.335973f, 1.0f - 0.335903f,
      0.336098f, 1.0f - 0.000071f, 0.667979f, 1.0f - 0.335851f,
      0.335973f, 1.0f - 0.335903f, 0.336024f, 1.0f - 0.671877f,
      1.000004f, 1.0f - 0.671847f, 0.999958f, 1.0f - 0.336064f,
      0.667979f, 1.0f - 0.335851f, 0.668104f, 1.0f - 0.000013f,
      0.335973f, 1.0f - 0.335903f, 0.667979f, 1.0f - 0.335851f,
      0.335973f, 1.0f - 0.335903f, 0.668104f, 1.0f - 0.000013f,
      0.336098f, 1.0f - 0.000071f, 0.000103f, 1.0f - 0.336048f,
      0.000004f, 1.0f - 0.671870f, 0.336024f, 1.0f - 0.671877f,
      0.000103f, 1.0f - 0.336048f, 0.336024f, 1.0f - 0.671877f,
      0.335973f, 1.0f - 0.335903f, 0.667969f, 1.0f - 0.671889f,
      1.000004f, 1.0f - 0.671847f, 0.667979f, 1.0f - 0.335851f};
  GLuint uvbuffer;
  glGenBuffers(1, &uvbuffer);
  glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(uv), uv, GL_STATIC_DRAW);
  // 2nd attribute buffer
  glEnableVertexAttribArray(1);
  glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
  glVertexAttribPointer(1,  // attribute. No particular reason for 1, but must
                            // match the layout in the shader.
                        2,  // size
                        GL_FLOAT,  // type
                        GL_FALSE,  // normalized?
                        0,         // stride
                        (void*)0   // array buffer offset
  );

  if (argc != 2) {
    std::cerr << "Needs one argument.\n";
    return 1;
  }
  const char* filename = argv[1];
  // Powers of two
  const int fffff = 128;
  const int fW = fffff, fH = fffff;
  std::vector<uint8_t> someFile;
  if (!readFile(fW * fH, filename, someFile)) {
    std::cerr << "Couln't read " << fW * fH << " bytes from " << filename
              << std::endl;
    return 1;
  }
  // Create one OpenGL texture
  GLuint textureID;
  glGenTextures(1, &textureID);
  // "Bind" the newly created texture : all future texture functions will modify
  // this texture
  glBindTexture(GL_TEXTURE_2D, textureID);
  // Give the image to OpenGL
  // GL_RGB indicates that we are talking about a 3-component color,
  // and GL_BGR says how exactly it is represented in RAM.
  // As a matter of fact, BMP does not store Red->Green->Blue but
  // Blue->Green->Red
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, fW, fH, 0, GL_BGR, GL_UNSIGNED_BYTE,
               someFile.data());
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
  // GL_LINEAR_MIPMAP_LINEAR); glGenerateMipmap(GL_TEXTURE_2D);

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

  std::cerr << "Ready!\n";
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

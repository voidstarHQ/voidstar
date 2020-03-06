#include <cstdint>
#include <fstream>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <memory>
#include <vector>

#define GLEW_STATIC
#include <GL/glew.h>

#include "include/GLFW/glfw3.h"

using Floats = std::vector<GLfloat>;

bool readFile(const int to_read, const char* filename,
              std::vector<uint8_t>& vec) {
  std::ifstream is(filename, std::ios::binary);
  if (!is) return false;
  is.unsetf(std::ios::skipws);  // don't eat newlines

  is.seekg(0, std::ios::end);
  std::streampos size = is.tellg();
  is.seekg(0, std::ios::beg);
  if (size < to_read) return false;

  vec.reserve(to_read);
  is.read(reinterpret_cast<char*>(vec.data()), to_read);
  if (!is) return false;
  return true;
}

void bytecube_vertices(Floats& vertices) {
  vertices.reserve(256 * 256 * 256);
  for (float z = 0; z < 256; ++z)
    for (float y = 0; y < 256; ++y)
      for (float x = 0; x < 256; ++x) {
        vertices.emplace_back((x - 128.0f) / 256.0f);
        vertices.emplace_back((y - 128.0f) / 256.0f);
        vertices.emplace_back((z - 128.0f) / 256.0f);
      }
}

void key_callback(GLFWwindow* window, int key, int scancode, int action,
                  int mode);

const GLuint WIDTH = 800, HEIGHT = 600;
int viewportW = WIDTH, viewportH = HEIGHT;  // TODO: atomic pair

void onFramebufferResize(GLFWwindow* /*window*/, int width, int height) {
  glViewport(0, 0, width, height);
  viewportW = width;
  viewportH = height;
}

#define DRAW_TRI (12 * 3)
const GLchar* vertexShaderSource = R"(
#version 330 core

layout (location = 0) in vec3 Position;
layout (location = 1) in vec3 Color;

out VS_OUT {
  vec3 vColor;
} vs_out;

uniform mat4 uMVP;

void main() {
  gl_Position = uMVP * vec4(Position, 1);
  vs_out.vColor = Color;
}
)";

const GLchar* fragmentShaderSource = R"(
#version 330 core

in VS_OUT {
  vec3 vColor;
} vs_in;

out vec3 color;

uniform sampler2D myTextureSampler;

void main() {
  // color = texture(myTextureSampler, vec2(0,0)).rgb;
  // color = texture(myTextureSampler, gl_FragCoord.xy).rgb;
  color = texture(myTextureSampler, gl_PointCoord).rgb;
  // color = texture(myTextureSampler, vs_in.vColor.xy).rgb;

  // color = texture(myTextureSampler, vs_in.vUV).rgb;
  // color = vs_in.vColor;
  // color = vec3(0,1,0);
}
)";

glm::vec3 position = glm::vec3(0, 0, 5);
// horizontal angle : toward -Z
float horizontalAngle = 3.14f;
// vertical angle : 0, look at the horizon
float verticalAngle = 0.0f;
// Initial Field of View
float initialFoV = 45.0f;

float speed = 3.0f;  // 3 units / second
float mouseSpeed = 0.005f;
// FoV is the level of zoom. 80° = very wide angle, huge deformations.
// 60° - 45°: standard. 20°: big zoom.

void computeMatricesFromInputs(GLFWwindow* window, glm::mat4* ProjectionMatrix,
                               glm::mat4* ViewMatrix) {
  static double lastTime = glfwGetTime();
  double currentTime = glfwGetTime();
  float deltaTime = float(currentTime - lastTime);

  // Get mouse position
  double xpos, ypos;
  glfwGetCursorPos(window, &xpos, &ypos);
  // Reset mouse position for next frame
  glfwSetCursorPos(window, viewportW / 2, viewportH / 2);

  // Compute new orientation
  horizontalAngle += mouseSpeed * float(viewportW / 2 - xpos);
  verticalAngle += mouseSpeed * float(viewportH / 2 - ypos);

  // Direction : Spherical coordinates to Cartesian coordinates conversion
  glm::vec3 direction(cos(verticalAngle) * sin(horizontalAngle),
                      sin(verticalAngle),
                      cos(verticalAngle) * cos(horizontalAngle));

  glm::vec3 right = glm::vec3(sin(horizontalAngle - 3.14f / 2.0f), 0,
                              cos(horizontalAngle - 3.14f / 2.0f));
  glm::vec3 up = glm::cross(right, direction);

  // GLFW_KEY_UP, GLFW_KEY_DOWN, GLFW_KEY_RIGHT, GLFW_KEY_LEFT
  if (glfwGetKey(window, 'W') == GLFW_PRESS) {
    position += direction * deltaTime * speed;  // forward
  }
  if (glfwGetKey(window, 'S') == GLFW_PRESS) {
    position -= direction * deltaTime * speed;  // backward
  }
  if (glfwGetKey(window, 'D') == GLFW_PRESS) {
    position += right * deltaTime * speed;  // strafe right
  }
  if (glfwGetKey(window, 'A') == GLFW_PRESS) {
    position -= right * deltaTime * speed;  // strafe left
  }
  if (glfwGetKey(window, 'X') == GLFW_PRESS) {
    position += up * deltaTime * speed;  // up
  }
  if (glfwGetKey(window, 'Z') == GLFW_PRESS) {
    position -= up * deltaTime * speed;  // down
  }

  if (glfwGetKey(window, 'O') == GLFW_PRESS) {
    position = glm::vec3(0, 0, 5);
    horizontalAngle = 3.14f;
    verticalAngle = 0.0f;
    initialFoV = 45.0f;
    direction =
        glm::vec3(cos(verticalAngle) * sin(horizontalAngle), sin(verticalAngle),
                  cos(verticalAngle) * cos(horizontalAngle));
    right = glm::vec3(sin(horizontalAngle - 3.14f / 2.0f), 0,
                      cos(horizontalAngle - 3.14f / 2.0f));
    up = glm::cross(right, direction);
  }

  float FoV =
      initialFoV;  // - 5 * glfwGetMouseWheel(); // Now GLFW 3 requires setting
                   // up a callback for this. It's a bit too complicated for
                   // this beginner's tutorial, so it's disabled instead.

  // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit
  // <-> 100 units
  *ProjectionMatrix = glm::perspective(
      glm::radians(FoV), (float)viewportW / (float)viewportH, 0.1f, 100.0f);
  // Camera matrix
  *ViewMatrix = glm::lookAt(
      position,  // Camera is here
      position +
          direction,  // and looks here : at the same position, plus "direction"
      up              // Head is up (set to 0,-1,0 to look upside-down)
  );

  // For the next frame, the "last time" will be "now"
  lastTime = currentTime;
}

// The MAIN function, from here we start the application and run the game loop
int main(int argc, const char* argv[]) {
  if (!glfwInit()) {
    std::cerr << "Failed to initialize GLFW\n";
    getchar();
    return -1;
  }

  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  // GLFW_OPENGL_FORWARD_COMPAT to make macOS happy; should not be needed
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  // glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  // Create a GLFWwindow object that we can use for GLFW's functions
  GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "tri", nullptr, nullptr);
  if (window == NULL) {
    std::cerr << "Failed to open GLFW window.\n";
    getchar();
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);

  glfwSetFramebufferSizeCallback(window, onFramebufferResize);
  // Set the required callback functions
  glfwSetKeyCallback(window, key_callback);

  // Set this to true so GLEW knows to use a modern approach to retrieving
  // function pointers and extensions
  glewExperimental = GL_TRUE;
  // Initialize GLEW to setup the OpenGL Function pointers
  if (glewInit() != GLEW_OK) {
    std::cerr << "Failed to initialize GLEW\n";
    getchar();
    glfwTerminate();
    return -1;
  }

  // Ensure we can capture the escape key being pressed below
  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
  // Hide the mouse and enable unlimited mouvement
  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

  // Define the viewport dimensions
  glfwGetFramebufferSize(window, &viewportW, &viewportH);
  glViewport(0, 0, viewportW, viewportH);

  // Set the mouse at the center of the screen
  glfwPollEvents();
  glfwSetCursorPos(window, viewportW / 2, viewportH / 2);

  // Enable depth test
  glEnable(GL_DEPTH_TEST);
  // Accept fragment if it closer to the camera than the former one
  glDepthFunc(GL_LESS);

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
    std::cout << "Error compiling vertex shader:\n" << infoLog << std::endl;
    return -1;
  }
  // Fragment shader
  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);
  // Check for compile time errors
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    std::cout << "Error compiling fragment shader:\n" << infoLog << std::endl;
    return -1;
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
    std::cout << "Error linking shaders:\n" << infoLog << std::endl;
    return -1;
  }
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
  std::cerr << "Compiled shaders\n";

  // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive
  // vertices give a triangle. A cube has 6 faces with 2 triangles each, so this
  // makes 6*2=12 triangles, and 12*3 vertices
  Floats vertices;
  bytecube_vertices(vertices);
  std::cerr << "Created vertices.\n";
  GLuint VBO, VAO;
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and
  // attribute pointer(s).
  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  // glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * vertices.size(), &vertices[0],
               GL_STATIC_DRAW);
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
  glVertexAttribPointer(1,         // layout = 1
                        2,         // size
                        GL_FLOAT,  // type
                        GL_FALSE,  // normalized?
                        0,         // stride
                        (void*)0   // array buffer offset
  );
  std::cerr << "Loaded UV.\n";

  std::vector<GLuint> elements;
  for (size_t i = 0; i < 256 * 256 * 256; ++i) elements.push_back(i);
  GLuint EBO;
  glGenBuffers(1, &EBO);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * elements.size(),
               &elements[0], GL_STATIC_DRAW);
  // // 3rd attribute buffer REAL UNSURE BOUT THIS
  // glEnableVertexAttribArray(2);
  // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  // glVertexAttribPointer(2,         // layout = 2
  //                       1,         // size
  //                       GL_UNSIGNED_INT,  // type
  //                       GL_FALSE,  // normalized?
  //                       0,         // stride
  //                       (void*)0   // array buffer offset
  // );
  std::cerr << "Loaded elements.\n";

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
  std::cerr << "Loaded texture.\n";

  glBindVertexArray(0);  // Unbind VAO (it's always a good thing to unbind any
                         // buffer/array to prevent strange bugs)

  GLuint uMVP = glGetUniformLocation(shaderProgram, "uMVP");
  GLuint uModel = glGetUniformLocation(shaderProgram, "uModel");
  GLuint uView = glGetUniformLocation(shaderProgram, "uView");
  GLuint uProjection = glGetUniformLocation(shaderProgram, "uProjection");

  std::cerr << "Ready!\n";
  while (!glfwWindowShouldClose(window)) {
    // Clear the colorbuffer
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Model matrix : an identity matrix (model will be at the origin)
    glm::mat4 ProjectionMatrix, ViewMatrix, ModelMatrix = glm::mat4(1.0);
    computeMatricesFromInputs(window, &ProjectionMatrix, &ViewMatrix);
    // Our ModelViewProjection : multiplication of our 3 matrices
    glm::mat4 MVP =
        ProjectionMatrix * ViewMatrix *
        ModelMatrix;  // Remember, matrix multiplication is the other way around
    glUniformMatrix4fv(uMVP, 1, GL_FALSE, &MVP[0][0]);
    glUniformMatrix4fv(uModel, 1, GL_FALSE, &ModelMatrix[0][0]);
    glUniformMatrix4fv(uView, 1, GL_FALSE, &ViewMatrix[0][0]);
    glUniformMatrix4fv(uProjection, 1, GL_FALSE, &ProjectionMatrix[0][0]);

    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawArrays(GL_POINTS, 0, 256 * 256 * 256);
    glDrawRangeElements(GL_POINTS, elements[0], elements.back(),
                        elements.size(), GL_UNSIGNED_INT, elements.data());
    glBindVertexArray(0);

    // Swap the screen buffers
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  // Properly de-allocate all resources once they've outlived their purpose
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteBuffers(1, &uvbuffer);
  glDeleteBuffers(1, &EBO);

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

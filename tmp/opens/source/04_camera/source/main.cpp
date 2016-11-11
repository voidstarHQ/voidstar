/*
 main

 Copyright 2012 Thomas Dalling - http://tomdalling.com/

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#include "platform.hpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <cassert>
#include <iostream>
#include <stdexcept>
#include <cmath>

#include "tdogl/Program.h"
#include "tdogl/Camera.h"

typedef struct {
    size_t screen_w;
    size_t screen_h;
    float  screen_aspect;

    GLuint vao = 0;
    GLuint vbo = 0;

    size_t width;
    size_t height;
    size_t depth;
    size_t n_points;

    GLfloat* vertex_buffer = NULL;
    GLfloat* vertex_colors = NULL;
    size_t   vertex_buffer_size;
    size_t   colors_buffer_size;
    GLuint   colors_buffer_id = 0;

    tdogl::Program* program = NULL;
    tdogl::Camera   camera;

    double scroll_y = 0.0;
    GLfloat degreesRotated = 0.0f;
} state;

state Ctx;
// globals
GLFWwindow* gWindow = NULL;


static void
init_state(state* ctx, size_t w, size_t h) {
    ctx->screen_w = w;
    ctx->screen_h = h;
    ctx->screen_aspect = w / h;
    ctx->width = 256;
    ctx->height = 256;
    ctx->depth = 256;
    ctx->n_points = ctx->width * ctx->height * ctx->depth;
    ctx->vertex_buffer_size = ctx->n_points * 3 * sizeof (GLfloat);
    ctx->colors_buffer_size = ctx->n_points * 4 * sizeof (GLfloat);
}


static void
LoadShaders() {
    std::vector<tdogl::Shader> shaders{
        tdogl::Shader::shaderFromFile(ResourcePath("vertex.glsl"), GL_VERTEX_SHADER),
        tdogl::Shader::shaderFromFile(ResourcePath("fragment.glsl"), GL_FRAGMENT_SHADER)};
    Ctx.program = new tdogl::Program(shaders);
}


static void
LoadBuffers() {
    // make and bind the VAO
    glGenVertexArrays(1, &Ctx.vao);
    glBindVertexArray(Ctx.vao);

    // make and bind the VBO
    glGenBuffers(1, &Ctx.vbo);
    glBindBuffer(GL_ARRAY_BUFFER, Ctx.vbo);

    Ctx.vertex_buffer = new GLfloat[Ctx.vertex_buffer_size];
    Ctx.vertex_colors = new GLfloat[Ctx.colors_buffer_size];
    size_t pos_v = 0;
    size_t pos_c = 0;
    for (size_t x = 0; x < Ctx.width; ++x) {
        for (size_t y = 0; y < Ctx.height; ++y) {
            for (size_t z = 0; z < Ctx.depth; ++z) {
                float vx = ((float)x - (float)Ctx.width / 2) / 128;
                float vy = ((float)y - (float)Ctx.height / 2) / 128;
                float vz = ((float)z - (float)Ctx.depth / 2) / 128;
                Ctx.vertex_buffer[pos_v++] = vx;
                Ctx.vertex_buffer[pos_v++] = vy;
                Ctx.vertex_buffer[pos_v++] = vz;

                Ctx.vertex_colors[pos_c++] = (float)x / (float)Ctx.width;
                Ctx.vertex_colors[pos_c++] = (float)y / (float)Ctx.height;
                Ctx.vertex_colors[pos_c++] = (float)z / (float)Ctx.depth;
                float res = std::abs( vx*vx + vy*vy - vz*vz );
                if ( res >= 0.9f && res <= 1.1f ) {
                    Ctx.vertex_colors[pos_c++] = 1.0f;
                } else {
                    Ctx.vertex_colors[pos_c++] = 0.0f;
                }
            }
        }
    }

    glBufferData(GL_ARRAY_BUFFER, Ctx.vertex_buffer_size, Ctx.vertex_buffer, GL_STATIC_DRAW);

    // connect the xyz to the "vert" attribute of the vertex shader
    glEnableVertexAttribArray(Ctx.program->attrib("vert"));
    glVertexAttribPointer(Ctx.program->attrib("vert"), 3, GL_FLOAT, GL_FALSE, 0, NULL);

    // make and bind the VBO
    glGenBuffers(1, &Ctx.colors_buffer_id);
    glBindBuffer(GL_ARRAY_BUFFER, Ctx.colors_buffer_id);
    glBufferData(GL_ARRAY_BUFFER, Ctx.vertex_buffer_size, Ctx.vertex_colors, GL_STATIC_DRAW);
    glEnableVertexAttribArray(Ctx.program->attrib("colr"));
    glVertexAttribPointer(Ctx.program->attrib("colr"), 4, GL_FLOAT, GL_FALSE, 0, NULL);

    // unbind the VAO
    glBindVertexArray(0);
}


// draws a single frame
static void
Render() {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // bind the program (the shaders)
    Ctx.program->use();

    Ctx.program->setUniform("camera", Ctx.camera.matrix());

    // set the "model" uniform in the vertex shader, based on the degreesRotated global
    Ctx.program->setUniform("model", glm::rotate(glm::mat4(), glm::radians(Ctx.degreesRotated), glm::vec3(0,1,0)));

    // bind the VAO
    glBindVertexArray(Ctx.vao);

    // draw the VAO
    glDrawArrays(GL_POINTS, 0, Ctx.n_points);

    // unbind the VAO and the program
    glBindVertexArray(0);
    Ctx.program->stopUsing();

    glfwSwapBuffers(gWindow);
}


// update the scene based on the time elapsed since last update
static void
Update(float secondsElapsed) {
    //rotate the cube
    // const GLfloat degreesPerSecond = 180.0f;
    // Ctx.degreesRotated += secondsElapsed * degreesPerSecond;
    // while (Ctx.degreesRotated > 360.0f)
    //     Ctx.degreesRotated -= 360.0f;

    //move position of camera based on WASD keys, and XZ keys for up and down
    const float moveSpeed = 2.0; //units per second
    if (glfwGetKey(gWindow, 'S'))
        Ctx.camera.offsetPosition(secondsElapsed * moveSpeed * -Ctx.camera.forward());
    else if (glfwGetKey(gWindow, 'W'))
        Ctx.camera.offsetPosition(secondsElapsed * moveSpeed * Ctx.camera.forward());
    if (glfwGetKey(gWindow, 'A'))
        Ctx.camera.offsetPosition(secondsElapsed * moveSpeed * -Ctx.camera.right());
    else if(glfwGetKey(gWindow, 'D'))
        Ctx.camera.offsetPosition(secondsElapsed * moveSpeed * Ctx.camera.right());
    if (glfwGetKey(gWindow, 'Z'))
        Ctx.camera.offsetPosition(secondsElapsed * moveSpeed * -glm::vec3(0,1,0));
    else if (glfwGetKey(gWindow, 'X'))
        Ctx.camera.offsetPosition(secondsElapsed * moveSpeed * glm::vec3(0,1,0));

    //rotate camera based on mouse movement
    const float mouseSensitivity = 0.1f;
    double mouseX, mouseY;
    glfwGetCursorPos(gWindow, &mouseX, &mouseY);
    Ctx.camera.offsetOrientation(mouseSensitivity * (float)mouseY, mouseSensitivity * (float)mouseX);
    glfwSetCursorPos(gWindow, 0, 0); //reset the mouse, so it doesn't go out of the window

    //increase or decrease field of view based on mouse wheel
    const float zoomSensitivity = -0.2f;
    float fieldOfView = Ctx.camera.fieldOfView() + zoomSensitivity * (float)Ctx.scroll_y;
    if (fieldOfView < 5.0f) fieldOfView = 5.0f;
    if (fieldOfView > 130.0f) fieldOfView = 130.0f;
    Ctx.camera.setFieldOfView(fieldOfView);
    Ctx.scroll_y = 0.0;
}

// records how far the y axis has been scrolled
static void
OnScroll(GLFWwindow* window, double deltaX, double deltaY) {
    Ctx.scroll_y += deltaY;
}

static void
OnError(int errorCode, const char* msg) {
    throw std::runtime_error(msg);
}


static void
AppMain() {
    glfwSetErrorCallback(OnError);
    if (!glfwInit())
        throw std::runtime_error("!glfwInit");

    // open a window with GLFW
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    init_state(&Ctx, 800, 600);
    gWindow = glfwCreateWindow(Ctx.screen_w, Ctx.screen_h, "points", NULL, NULL);
    if (!gWindow)
        throw std::runtime_error("!glfwCreateWindow. Can your hardware handle OpenGL 3.2?");

    // GLFW settings
    glfwSetInputMode(gWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPos(gWindow, 0, 0);
    glfwSetScrollCallback(gWindow, OnScroll);
    glfwMakeContextCurrent(gWindow);

    glewExperimental = GL_TRUE; //stops glew crashing on OSX :-/
    if (glewInit() != GLEW_OK)
        throw std::runtime_error("!glewInit");
    // GLEW throws some errors, so discard all the errors so far
    while (glGetError() != GL_NO_ERROR) {}

    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
    std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;

    if (!GLEW_VERSION_3_2)
        throw std::runtime_error("OpenGL 3.2 API is not available.");

    // OpenGL settings
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    LoadShaders();

    LoadBuffers();

    Ctx.camera.setPosition(glm::vec3(0,0,4));
    Ctx.camera.setViewportAspectRatio(Ctx.screen_aspect);

    double lastTime = glfwGetTime();
    while (!glfwWindowShouldClose(gWindow)) {
        // process pending events
        glfwPollEvents();

        // update the scene based on the time elapsed since last update
        double thisTime = glfwGetTime();
        Update((float)(thisTime - lastTime));
        lastTime = thisTime;

        Render();

        GLenum error = glGetError();
        if (error != GL_NO_ERROR)
            std::cerr << "OpenGL Error " << error << std::endl;

        if (glfwGetKey(gWindow, GLFW_KEY_ESCAPE))
            glfwSetWindowShouldClose(gWindow, GL_TRUE);
    }

    // clean up and exit
    glfwTerminate();
}


int
main(int argc, char *argv[]) {
    try { AppMain(); }
    catch (const std::exception& e){
        std::cerr << "ERROR: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

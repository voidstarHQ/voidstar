#include <iostream>
#include <stdexcept>


#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <platform.hpp>

#include <tdogl/Program.h>
#include <tdogl/Camera.h>

#include <Scene.hh>
#include <Manager.hh>

struct SceneContext {
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

    GLfloat degreesRotated = 0.0f;
    tdogl::Program* program = NULL;
};

// TODO remove this
SceneContext Ctx;

static void
LoadShaders() {
    std::vector<tdogl::Shader> shaders{
        tdogl::Shader::shaderFromFile(ResourcePath("vertex.glsl"), GL_VERTEX_SHADER),
        tdogl::Shader::shaderFromFile(ResourcePath("fragment.glsl"), GL_FRAGMENT_SHADER)
    };
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
    Ctx.vertex_colors = new GLfloat[Ctx.colors_buffer_size]();
    size_t pos = 0;
    for (size_t z = 0; z < Ctx.depth; ++z)
        for (size_t y = 0; y < Ctx.height; ++y)
            for (size_t x = 0; x < Ctx.width; ++x) {
                Ctx.vertex_buffer[pos++] = ((float)x - (float)Ctx.width  / 2.0f) / 128;
                Ctx.vertex_buffer[pos++] = ((float)y - (float)Ctx.height / 2.0f) / 128;
                Ctx.vertex_buffer[pos++] = ((float)z - (float)Ctx.depth  / 2.0f) / 128;
                // Ctx.vertex_buffer[pos++] = static_cast<float>(x);
                // Ctx.vertex_buffer[pos++] = static_cast<float>(y);
                // Ctx.vertex_buffer[pos++] = static_cast<float>(z);
            }
    glBufferData(GL_ARRAY_BUFFER, Ctx.vertex_buffer_size, Ctx.vertex_buffer, GL_STATIC_DRAW);
    // connect the xyz to the "vert" attribute of the vertex shader
    glEnableVertexAttribArray(Ctx.program->attrib("vert"));
    glVertexAttribPointer(Ctx.program->attrib("vert"), 3, GL_FLOAT, GL_FALSE, 0, NULL);

    // make and bind the VBO
    glGenBuffers(1, &Ctx.colors_buffer_id);
    glBindBuffer(GL_ARRAY_BUFFER, Ctx.colors_buffer_id);

    const size_t chunk = 1024 * 5;
    unsigned char read[chunk];
    if (fread(read, 1, chunk, stdin) == chunk) {
        unsigned char x = read[0];
        unsigned char y = read[1];
        for (size_t i = 2; i < chunk; ++i) {
            unsigned char z = read[i];
            size_t idx = 4 * (x + y * Ctx.height + z * Ctx.depth * Ctx.height);
            Ctx.vertex_colors[idx + 0] = 1.0f;
            Ctx.vertex_colors[idx + 1] = 1.0f;
            Ctx.vertex_colors[idx + 2] = 1.0f;
            // float opacity = Ctx.vertex_colors[idx + 3];
            // Ctx.vertex_colors[idx + 3] = std::min(1.0f, 1.0f/255.0f + opacity);
            Ctx.vertex_colors[idx + 3] = 1.0f;
            x = y;
            y = z;
        }
    }
    std::cout << "done reading" << std::endl;
    glBufferData(GL_ARRAY_BUFFER, Ctx.vertex_buffer_size, Ctx.vertex_colors, GL_STATIC_DRAW);
    glEnableVertexAttribArray(Ctx.program->attrib("colr"));
    glVertexAttribPointer(Ctx.program->attrib("colr"), 4, GL_FLOAT, GL_FALSE, 0, NULL);

    // unbind the VAO
    glBindVertexArray(0);
}


void Scene::init()
{
    glewExperimental = GL_TRUE; //stops glew crashing on OSX :-/
    if (glewInit() != GLEW_OK)
        throw std::runtime_error("!glewInit");

    // GLEW throws some errors, so discard all the errors so far
    //while (glGetError() != GL_NO_ERROR) {}
    processErrors();

    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
    std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;

    if (!GLEW_VERSION_3_2)
        throw std::runtime_error("OpenGL 3.2 API is not available.");

    resize(manager_->args()->height, manager_->args()->width);
}

void Scene::load(Algorithm *algorithm)
{
    // OpenGL settings
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    Ctx.width = 256;
    Ctx.height = 256;
    Ctx.depth = 256;
    Ctx.n_points = Ctx.width * Ctx.height * Ctx.depth;
    Ctx.vertex_buffer_size = Ctx.n_points * 3 * sizeof (GLfloat);
    Ctx.colors_buffer_size = Ctx.n_points * 4 * sizeof (GLfloat);

    LoadShaders();
    LoadBuffers();

    camera_.setPosition(glm::vec3(0,0,4));
    camera_.setViewportAspectRatio(aspect_ratio_);
    camera_.setNearAndFarPlanes(0.1, 100.);
}

void Scene::unload()
{
    // TODO:
}

bool Scene::update(float elapsedTime)
{
    //rotate the cube
    // const GLfloat degreesPerSecond = 180.0f;
    // Ctx.degreesRotated += elapsedTime * degreesPerSecond;
    // while (Ctx.degreesRotated > 360.0f)
    //     Ctx.degreesRotated -= 360.0f;

    auto events = manager_->getEvents();

    //move position of camera based on WASD keys, and XZ keys for up and down
    const float moveSpeed = 2.0; //units per second
    if (events->keyPressed('S'))
        camera_.offsetPosition(elapsedTime * moveSpeed * -camera_.forward());
    else if (events->keyPressed('W'))
        camera_.offsetPosition(elapsedTime * moveSpeed * camera_.forward());
    if (events->keyPressed('A'))
        camera_.offsetPosition(elapsedTime * moveSpeed * -camera_.right());
    else if(events->keyPressed('D'))
        camera_.offsetPosition(elapsedTime * moveSpeed * camera_.right());
    if (events->keyPressed('Z'))
        camera_.offsetPosition(elapsedTime * moveSpeed * -glm::vec3(0,1,0));
    else if (events->keyPressed('X'))
        camera_.offsetPosition(elapsedTime * moveSpeed * glm::vec3(0,1,0));

    auto mouse = manager_->getMouse();
    mouse->getCursorPos();
    camera_.offsetOrientation(mouse->sensitivity * mouse->y,
                              mouse->sensitivity * mouse->x);
    //reset the mouse, so it doesn't go out of the window
    mouse->setCursorPos(0, 0);

    //increase or decrease field of view based on mouse wheel
    float fieldOfView = camera_.fieldOfView() +
                        mouse->zoomSensitivity * mouse->scrollY;
    if (fieldOfView < 5.0f) fieldOfView = 5.0f;
    if (fieldOfView > 130.0f) fieldOfView = 130.0f;
    camera_.setFieldOfView(fieldOfView);
    mouse->scrollY = 0.0;
    return true;
}

void Scene::render()
{
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // bind the program (the shaders)
    Ctx.program->use();

    Ctx.program->setUniform("camera", camera_.matrix());

    // set the "model" uniform in the vertex shader, based on the degreesRotated global
    Ctx.program->setUniform("model", glm::rotate(glm::mat4(), glm::radians(Ctx.degreesRotated), glm::vec3(0,1,0)));

    // bind the VAO
    glBindVertexArray(Ctx.vao);

    // draw the VAO
    glDrawArrays(GL_POINTS, 0, Ctx.n_points);

    // unbind the VAO and the program
    glBindVertexArray(0);
    Ctx.program->stopUsing();
}

void Scene::processErrors(bool quiet)
{
    while (true) {
        GLenum error = glGetError();
        if (error == GL_NO_ERROR)
            break;
        if (!quiet)
            std::cerr << "OpenGL Error " << error << std::endl;
    }
}

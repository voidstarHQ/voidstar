#include <iostream>
#include <stdexcept>

#include <platform.hpp>

#include <Scene3D.hh>
#include <Manager.hh>

void
Scene3D::load_shaders() {
    const std::vector<tdogl::Shader> shaders{
        tdogl::Shader::shaderFromFile(ResourcePath("vertex.glsl"), GL_VERTEX_SHADER),
        tdogl::Shader::shaderFromFile(ResourcePath("fragment.glsl"), GL_FRAGMENT_SHADER)
    };
    ctx_.program = new tdogl::Program(shaders);
}


void
Scene3D::load_buffers() {
    // make and bind the VAO
    glGenVertexArrays(1, &ctx_.vao);
    glBindVertexArray(ctx_.vao);

    // make and bind the VBO
    glGenBuffers(1, &ctx_.vbo);
    glBindBuffer(GL_ARRAY_BUFFER, ctx_.vbo);

    glBufferData(GL_ARRAY_BUFFER, ctx_.vertices_size, ctx_.vertices, GL_STATIC_DRAW);
    // connect the xyz to the "vert" attribute of the vertex shader
    glEnableVertexAttribArray(ctx_.program->attrib("vert"));
    glVertexAttribPointer(ctx_.program->attrib("vert"), 3, GL_FLOAT, GL_FALSE, 0, NULL);

    // make and bind the VBO
    glGenBuffers(1, &ctx_.colors_id);
    glBindBuffer(GL_ARRAY_BUFFER, ctx_.colors_id);

    glBufferData(GL_ARRAY_BUFFER, ctx_.colors_size, ctx_.colors, GL_STATIC_DRAW);
    glEnableVertexAttribArray(ctx_.program->attrib("colr"));
    glVertexAttribPointer(ctx_.program->attrib("colr"), 4, GL_FLOAT, GL_FALSE, 0, NULL);

    // unbind the VAO
    glBindVertexArray(0);
}


void
Scene3D::init()
{
    glewExperimental = GL_TRUE; //stops glew crashing on OSX :-/
    if (glewInit() != GLEW_OK)
        throw std::runtime_error("!glewInit");

    // GLEW throws some errors, so discard all the errors so far
    //while (glGetError() != GL_NO_ERROR) {}
    processErrors();

    if (!GLEW_VERSION_3_2)
        throw std::runtime_error("OpenGL 3.2 API is not available.");

    resize(manager_->args()->height, manager_->args()->width);
}

void
Scene3D::load(Algorithm3D* algorithm)
{
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    load_shaders();
    algorithm->apply(ctx_.vertices, ctx_.colors, ctx_.width, ctx_.height, ctx_.depth)
        || std::cerr << "!apply" << std::endl;
    load_buffers();

    camera_.setPosition(glm::vec3(0, 0, 4));
    camera_.setViewportAspectRatio(aspect_ratio_);
    camera_.setNearAndFarPlanes(0.1, 100.);
}

bool
Scene3D::update(float elapsedTime)
{
    //rotate the cube
    // const GLfloat degreesPerSecond = 180.0f;
    // ctx_.degreesRotated += elapsedTime * degreesPerSecond;
    // while (ctx_.degreesRotated > 360.0f)
    //     ctx_.degreesRotated -= 360.0f;

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
    fieldOfView = std::min(5.0f, fieldOfView);
    fieldOfView = std::max(130.0f, fieldOfView);
    camera_.setFieldOfView(fieldOfView);
    mouse->scrollY = 0.0;
    return true;
}

void
Scene3D::render()
{
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // bind the program (the shaders)
    ctx_.program->use();

    ctx_.program->setUniform("camera", camera_.matrix());

    // set the "model" uniform in the vertex shader, based on degreesRotated
    ctx_.program->setUniform("model", glm::rotate(glm::mat4(), glm::radians(ctx_.degreesRotated), glm::vec3(0,1,0)));

    // bind the VAO
    glBindVertexArray(ctx_.vao);

    // draw the VAO
    glDrawArrays(GL_POINTS, 0, ctx_.n_points);

    // unbind the VAO and the program
    glBindVertexArray(0);
    ctx_.program->stopUsing();
}

void
Scene3D::processErrors(bool quiet)
{
    while (true) {
        GLenum error = glGetError();
        if (error == GL_NO_ERROR)
            break;
        if (!quiet)
            std::cerr << "OpenGL Error " << error << std::endl;
    }
}

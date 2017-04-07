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
    glVertexAttribPointer(ctx_.program->attrib("vert"), 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(ctx_.program->attrib("vert"));

    // make and bind the VBO
    glGenBuffers(1, &ctx_.colors_id);
    glBindBuffer(GL_ARRAY_BUFFER, ctx_.colors_id);

    glBufferData(GL_ARRAY_BUFFER, ctx_.colors_size, ctx_.colors, GL_STATIC_DRAW);
    glVertexAttribPointer(ctx_.program->attrib("colr"), 4, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(ctx_.program->attrib("colr"));

    // unbind the VAO
    glBindVertexArray(0);
}


void
Scene3D::init()
{
    resize(manager_->args()->width, manager_->args()->height);
}

void
Scene3D::unload()
{
    if (ctx_.program) {
        delete ctx_.program;
        glDeleteBuffers(1, &ctx_.vbo);
        glDeleteBuffers(1, &ctx_.colors_id);
        glDeleteVertexArrays(1, &ctx_.vao);
    }
}

void
Scene3D::reload()
{
    auto* algo = reinterpret_cast<Algo3D*>(algo_);
    ctx_.reset_points();
    algo->apply(ctx_.vertices, ctx_.colors, ctx_.selected, ctx_.width, ctx_.height, ctx_.depth)
        || std::cerr << "!apply" << std::endl;
    std::cout << "#points: " << ctx_.selected.size() << std::endl;
    load_buffers();
    glBindVertexArray(ctx_.vao);
    glBindBuffer(GL_ARRAY_BUFFER, ctx_.colors_id);
    glBufferData(GL_ARRAY_BUFFER, ctx_.colors_size, ctx_.colors, GL_STATIC_DRAW);
    glBindVertexArray(0);
}

void
Scene3D::load(Algorithm* algorithm)
{
    Scene::load(algorithm);
    auto* algo = reinterpret_cast<Algo3D*>(algorithm);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    load_shaders();
    algo->apply(ctx_.vertices, ctx_.colors, ctx_.selected, ctx_.width, ctx_.height, ctx_.depth)
        || std::cerr << "!apply" << std::endl;
    std::cout << "#points: " << ctx_.selected.size() << std::endl;
    load_buffers();

    camera_.setPosition(glm::vec3(0, 0, 4));
    camera_.setViewportAspectRatio(aspect_ratio_);
    camera_.setNearAndFarPlanes(0.1, 100.);
}

bool
Scene3D::update(float elapsedTime)
{
    //rotate the volume
    GLfloat degreesPerSecond = 10.0f;
    if (ctx_.rotationEnabled) {
        ctx_.degreesRotated += elapsedTime * degreesPerSecond;
        while (ctx_.degreesRotated > 360.0f)
            ctx_.degreesRotated -= 360.0f;
    }

    auto events = manager_->getEvents();

    //move position of camera based on WASD keys, and XZ keys for up and down
    const float moveSpeed = 2.0; //units per second
    if (events->keyDown('S'))
        camera_.offsetPosition(elapsedTime * moveSpeed * -camera_.forward());
    else if (events->keyDown('W'))
        camera_.offsetPosition(elapsedTime * moveSpeed * camera_.forward());
    if (events->keyDown('A'))
        camera_.offsetPosition(elapsedTime * moveSpeed * -camera_.right());
    else if(events->keyDown('D'))
        camera_.offsetPosition(elapsedTime * moveSpeed * camera_.right());
    if (events->keyDown('Z'))
        camera_.offsetPosition(elapsedTime * moveSpeed * -glm::vec3(0,1,0));
    else if (events->keyDown('X'))
        camera_.offsetPosition(elapsedTime * moveSpeed * glm::vec3(0,1,0));
    if (events->keyPressed(' '))
        ctx_.rotationEnabled = !ctx_.rotationEnabled;

    auto mouse = manager_->getMouse();
    mouse->getCursorPos();
    camera_.offsetOrientation(mouse->sensitivity * mouse->y,
                              mouse->sensitivity * mouse->x);
    //reset the mouse, so it doesn't go out of the window
    mouse->setCursorPos(0, 0);

    mouse->scrollY = 0.0;
    return true;
}

void
Scene3D::render()
{
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // bind the program (the shaders)
    ctx_.program->use();

    ctx_.program->setUniform("camera", camera_.matrix());

    // set the "model" uniform in the vertex shader, based on degreesRotated
    ctx_.program->setUniform("model", glm::rotate(glm::mat4(), glm::radians(ctx_.degreesRotated), glm::vec3(0,1,0)));

    // bind the VAO
    glBindVertexArray(ctx_.vao);

#ifdef __APPLE__
    glDrawArrays(GL_POINTS, 0, ctx_.n_points);
#else
    // draw only the VAO's points we colored
    glDrawElements(GL_POINTS, ctx_.selected.size(), GL_UNSIGNED_INT, ctx_.selected.data());
#endif

    // unbind the VAO and the program
    glBindVertexArray(0);
    ctx_.program->stopUsing();
}

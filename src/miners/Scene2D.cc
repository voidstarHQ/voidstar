#include <iostream>
#include <stdexcept>

#include <platform.hpp>

#include <Scene2D.hh>
#include <Manager.hh>

void
Scene2D::load_shaders() {
    const std::vector<tdogl::Shader> shaders{
        tdogl::Shader::shaderFromFile(ResourcePath("vertex_2d.glsl"), GL_VERTEX_SHADER),
        tdogl::Shader::shaderFromFile(ResourcePath("fragment.glsl"), GL_FRAGMENT_SHADER)
    };
    program_ = new tdogl::Program(shaders);
}


void
Scene2D::load_buffers() {
    // make and bind the VAO
    glGenVertexArrays(1, &vao_);
    glBindVertexArray(vao_);

    // make and bind the VBO
    glGenBuffers(1, &vbo_);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_);

    glBufferData(GL_ARRAY_BUFFER, vertices_size_, vertices_, GL_STATIC_DRAW);
    // connect the xyz to the "vert" attribute of the vertex shader
    glEnableVertexAttribArray(program_->attrib("vert"));
    glVertexAttribPointer(program_->attrib("vert"), 2, GL_FLOAT, GL_FALSE, 0, NULL);

    // make and bind the VBO
    glGenBuffers(1, &colors_id_);
    glBindBuffer(GL_ARRAY_BUFFER, colors_id_);

    glBufferData(GL_ARRAY_BUFFER, vertices_size_, colors_, GL_STATIC_DRAW);
    glEnableVertexAttribArray(program_->attrib("colr"));
    glVertexAttribPointer(program_->attrib("colr"), 4, GL_FLOAT, GL_FALSE, 0, NULL);

    // unbind the VAO
    glBindVertexArray(0);
}

void
Scene2D::init()
{
    resize(manager_->args()->width, manager_->args()->height);
}

void
Scene2D::load(Algorithm* algorithm)
{
    Scene::load(algorithm);
    auto* algo = reinterpret_cast<Algo2D*>(algorithm);

    glEnable(GL_PROGRAM_POINT_SIZE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    load_shaders();
    algo->apply(vertices_, colors_, width_, height_)
        || std::cerr << "!apply" << std::endl;
    load_buffers();
}

bool
Scene2D::update(float elapsedTime)
{
    return true;
}

void
Scene2D::render()
{
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // bind the program (the shaders)
    program_->use();

    // bind the VAO
    glBindVertexArray(vao_);

    // draw the VAO
    glDrawArrays(GL_POINTS, 0, n_points_);

    // unbind the VAO and the program
    glBindVertexArray(0);
    program_->stopUsing();
}

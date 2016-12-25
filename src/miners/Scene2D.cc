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
    ctx_.program = new tdogl::Program(shaders);
}


void
Scene2D::load_buffers() {
    // make and bind the VAO
    glGenVertexArrays(1, &ctx_.vao);
    glBindVertexArray(ctx_.vao);

    // make and bind the VBO
    glGenBuffers(1, &ctx_.vbo);
    glBindBuffer(GL_ARRAY_BUFFER, ctx_.vbo);

    glBufferData(GL_ARRAY_BUFFER, ctx_.vertices_size, ctx_.vertices, GL_STATIC_DRAW);
    // connect the xyz to the "vert" attribute of the vertex shader
    glEnableVertexAttribArray(ctx_.program->attrib("vert"));
    glVertexAttribPointer(ctx_.program->attrib("vert"), 2, GL_FLOAT, GL_FALSE, 0, NULL);

    // make and bind the VBO
    glGenBuffers(1, &ctx_.colors_id);
    glBindBuffer(GL_ARRAY_BUFFER, ctx_.colors_id);

    glBufferData(GL_ARRAY_BUFFER, ctx_.vertices_size, ctx_.colors, GL_STATIC_DRAW);
    glEnableVertexAttribArray(ctx_.program->attrib("colr"));
    glVertexAttribPointer(ctx_.program->attrib("colr"), 4, GL_FLOAT, GL_FALSE, 0, NULL);

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
    algo->apply(ctx_.vertices, ctx_.colors, ctx_.width, ctx_.height)
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
    ctx_.program->use();

    // bind the VAO
    glBindVertexArray(ctx_.vao);

    // draw the VAO
    glDrawArrays(GL_POINTS, 0, ctx_.n_points);

    // unbind the VAO and the program
    glBindVertexArray(0);
    ctx_.program->stopUsing();
}

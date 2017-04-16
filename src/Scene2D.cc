#include <stdexcept>

#include <shaders.hh>
#include <Scene2D.hh>

void
Scene2D::load_shaders() {
    const std::vector<tdogl::Shader> shaders{
        tdogl::Shader(shader__vertex_2d, GL_VERTEX_SHADER),
        tdogl::Shader(shader__fragment, GL_FRAGMENT_SHADER)
    };
    program_ = std::make_shared<tdogl::Program>(shaders);
}


void
Scene2D::load_buffers() {
    // make and bind the VAO
    glGenVertexArrays(1, &vao_);
    glBindVertexArray(vao_);

    // make and bind the VBO
    glGenBuffers(1, &vbo_);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_);

    glBufferData(GL_ARRAY_BUFFER, vertices_.size(), vertices_.data(), GL_STATIC_DRAW);
    // connect the xyz to the "vert" attribute of the vertex shader
    glEnableVertexAttribArray(program_->attrib("vert"));
    glVertexAttribPointer(program_->attrib("vert"), 2, GL_FLOAT, GL_FALSE, 0, NULL);

    // make and bind the VBO
    glGenBuffers(1, &colors_id_);
    glBindBuffer(GL_ARRAY_BUFFER, colors_id_);

    glBufferData(GL_ARRAY_BUFFER, colors_.size(), colors_.data(), GL_STATIC_DRAW);
    glEnableVertexAttribArray(program_->attrib("colr"));
    glVertexAttribPointer(program_->attrib("colr"), 4, GL_FLOAT, GL_FALSE, 0, NULL);

    // unbind the VAO
    glBindVertexArray(0);
}

void
Scene2D::init(std::shared_ptr<Arguments> args) {
    resize(args->width, args->height);
}

void
Scene2D::unload() {
    if (program_) {
        glDeleteBuffers(1, &vbo_);
        glDeleteBuffers(1, &colors_id_);
        glDeleteVertexArrays(1, &vao_);
    }
}

void
Scene2D::reload() {
    auto algo = std::static_pointer_cast<Algo2D>(algo_);
    reset_points();
    algo->apply(vertices_, colors_, width_, height_)
        || std::cerr << "!apply" << std::endl;
    glBindVertexArray(vao_);
    glBindBuffer(GL_ARRAY_BUFFER, colors_id_);
    glBufferData(GL_ARRAY_BUFFER, colors_.size(), colors_.data(), GL_STATIC_DRAW);
    glBindVertexArray(0);
}

void
Scene2D::load(std::shared_ptr<Algorithm> algorithm) {
    Scene::load(algorithm);
    auto algo = std::static_pointer_cast<Algo2D>(algorithm);

    glEnable(GL_PROGRAM_POINT_SIZE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    load_shaders();
    algo->apply(vertices_, colors_, width_, height_)
        || std::cerr << "!apply" << std::endl;
    load_buffers();
}

bool
Scene2D::update(std::shared_ptr<Manager> manager __unused, float elapsedTime __unused) {
    return true;
}

void
Scene2D::render() {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

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

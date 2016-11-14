#include <iostream>
#include <ContiAlgorithm3D.hh>

bool
ContiAlgorithm3D::apply(GLfloat* vertices, GLfloat* colors,
                      size_t width, size_t height, size_t depth) {
    size_t pos = 0;
    for (size_t z = 0; z < depth; ++z)
        for (size_t y = 0; y < height; ++y)
            for (size_t x = 0; x < width; ++x) {
                vertices[pos++] = ((float)x - (float)width  / 2.0f) / 128;
                vertices[pos++] = ((float)y - (float)height / 2.0f) / 128;
                vertices[pos++] = ((float)z - (float)depth  / 2.0f) / 128;
                // vertices[pos++] = static_cast<float>(x);
                // vertices[pos++] = static_cast<float>(y);
                // vertices[pos++] = static_cast<float>(z);
            }

    const size_t chunk = 1024 * 5;
    unsigned char read[chunk];
    if (fread(read, 1, chunk, stdin) == chunk) {
        std::cerr << "done reading" << std::endl;
        unsigned char x = read[0];
        unsigned char y = read[1];
        for (size_t i = 2; i < chunk; ++i) {
            unsigned char z = read[i];
            size_t idx = 4 * (x + y * height + z * depth * height);
            colors[idx + 0] = 1.0f;
            colors[idx + 1] = 1.0f;
            colors[idx + 2] = 1.0f;
            // float opacity = colors[idx + 3];
            // colors[idx + 3] = std::min(1.0f, 1.0f/255.0f + opacity);
            colors[idx + 3] = 1.0f;
            x = y;
            y = z;
        }
    }
    else
        return false;

    return true;
}

#pragma once

#include <vector>

#include <Algorithm.hh>

class Algo3D : public Algorithm {
public:
    virtual ~Algo3D() {}

    virtual void make_vertices(Floats& vertices,
                               size_t width, size_t height, size_t depth) = 0;

    virtual size_t value_size() const = 0;
    virtual Index cast(const u8* data, Floats& colors,
                       size_t width, size_t height, size_t depth) const = 0;
};

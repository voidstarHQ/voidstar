#pragma once

#include <Algo3DCube.hh>

class XYZRGB : public Algo3DCube {
public:
    XYZRGB() {}
    virtual ~XYZRGB() {}

    typedef struct {
        u8 x, y, z, R, G, B;
    } value_type;

    virtual size_t value_size() const { return sizeof (value_type); }

    virtual Index cast(const u8* data, Floats& colors,
                       size_t /*width*/, size_t height, size_t depth) const {
        auto* cast = (value_type*)(data);

        auto x = static_cast<Index>(cast->x);
        auto y = static_cast<Index>(cast->y);
        auto z = static_cast<Index>(cast->z);

        Index id = (x * height + y) * depth + z;
        Index idx = 3 * id;

        colors[idx+0] = static_cast<float>(cast->R) / 255.0f;
        colors[idx+1] = static_cast<float>(cast->G) / 255.0f;
        colors[idx+2] = static_cast<float>(cast->B) / 255.0f;

        return id;
    }
};

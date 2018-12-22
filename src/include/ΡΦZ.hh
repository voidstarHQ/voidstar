#pragma once

#include <Algo3DCylinder.hh>

class ΡΦZ : public Algo3DCylinder {
public:
    ΡΦZ() {}
    virtual ~ΡΦZ() {}

    typedef struct {
        u8 ρ, φ, z, R, G, B;
    } value_type;

    virtual size_t value_size() const { return sizeof (value_type); }

    virtual Index cast(const u8* data, Floats& colors,
                       size_t /*width*/, size_t height, size_t depth) const {
        auto* cast = (value_type*)(data);

        auto ρ = static_cast<Index>(cast->ρ);
        auto φ = static_cast<Index>(cast->φ);
        auto z = static_cast<Index>(cast->z);

        // TODO: actually use cylindrical coordinates
        Index id = (ρ * height + φ) * depth + z;
        Index idx = 3 * id;

        colors[idx+0] = static_cast<float>(cast->R) / 255.0f;
        colors[idx+1] = static_cast<float>(cast->G) / 255.0f;
        colors[idx+2] = static_cast<float>(cast->B) / 255.0f;

        return id;
    }
};

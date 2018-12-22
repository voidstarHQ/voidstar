#pragma once

#include <Algo3DSphere.hh>

class RΘΦ : public Algo3DSphere {
public:
    RΘΦ() {}
    virtual ~RΘΦ() {}

    typedef struct {
        u8 r, θ, φ, R, G, B;
    } value_type;

    virtual size_t value_size() const { return sizeof (value_type); }

    virtual Index cast(const u8* data, Floats& colors,
                       size_t /*width*/, size_t height, size_t depth) const {
        auto* cast = (value_type*)(data);

        auto r = static_cast<Index>(cast->r);
        auto θ = static_cast<Index>(cast->θ);
        auto φ = static_cast<Index>(cast->φ);

        // TODO: actually use spherical coordinates
        Index id = (r * height + θ) * depth + φ;
        Index idx = 3 * id;

        colors[idx+0] = static_cast<float>(cast->R) / 255.0f;
        colors[idx+1] = static_cast<float>(cast->G) / 255.0f;
        colors[idx+2] = static_cast<float>(cast->B) / 255.0f;

        return id;
    }
};

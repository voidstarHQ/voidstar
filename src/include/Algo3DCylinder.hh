#pragma once

#include <cmath>
#include <iostream>
#include <vector>

#include <Algo3D.hh>

class Algo3DCylinder : public Algo3D {
public:
    virtual ~Algo3DCylinder() {}

    virtual void make_vertices(Floats& vertices,
                               size_t /*width*/, size_t /*height*/, size_t /*depth*/) {
        // TODO

        std::cerr << "drawn cylinder of " << Manager::size2str(vertices.size() / 3)
                  << " vertices" << std::endl;
    }
};

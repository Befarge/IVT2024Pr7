#pragma once

#include "types/Vector.hpp"
#include "types/Face.hpp"

#include <vector>

class ShapeInterface {
public:
    virtual double getSurfaceArea() = 0;
    virtual double getVolume() = 0;
    
    virtual std::vector<Vector3D> getVertices() = 0;
    virtual std::vector<Face> getFaces() = 0;
};
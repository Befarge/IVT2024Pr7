#include "Vector.hpp"

#include <vector>

class ShapeInterface {
public:
    virtual double getSurfaceArea() = 0;
    virtual double getVolume() = 0;
    
    virtual std::vector<Vector3D> getVertices() = 0;
    virtual std::vector<double> getEdges() = 0;
};
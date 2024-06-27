#include <geomath/CubeShape.hpp>
#include <vector>

CubeShape::CubeShape(double side) {
    this->setSide(side);
}


void CubeShape::setSide(double side) {
    this->side = side;
}

double CubeShape::getSide() {
    return this->side;
}       


double CubeShape::getSurfaceArea() {
    
}

double CubeShape::getVolume() {
    
}

std::vector<Vector3D> CubeShape::getVertices() {
    
}

std::vector<double> CubeShape::getEdges() {
    
}
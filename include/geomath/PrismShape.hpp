#pragma once

#include "ShapeInterface.hpp"

class PrismShape : public ShapeInterface {
    double side;
public:
    PrismShape(double side);
    
    // Setters
    void setSide(double side);
    
    // Getters
    double getSide();
    
    // ShapeInterface implementation
    double getSurfaceArea() override;
    double getVolume() override;
    std::vector<Vector3D> getVertices() override;
    std::vector<Face> getFaces() override;
};
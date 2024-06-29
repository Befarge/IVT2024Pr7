#pragma once

#include "ShapeInterface.hpp"

class CubeShape : public ShapeInterface {
    double side;
public:
    CubeShape(double side);
    
    // Setters
    void setSide(double side);
    
    // Getters
    double getSide();
    
    // ShapeInterface implementation
    double getSurfaceArea() override;
    double getVolume() override;
    std::vector<Face> getFaces() override;
};
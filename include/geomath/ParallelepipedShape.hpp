#pragma once

#include "ShapeInterface.hpp"

class ParallelepipedShape : public ShapeInterface {
    double length;
    double width;
    double height;
    double alpha;
    Vector2DXZ top_offset;
public:
    ParallelepipedShape(
        double length = 1, 
        double width  = 1,
        double height = 1,
        double alpha = 90,
        Vector2DXZ top_offset = {0, 0}
    );
    
    // Setters
    void setLength(double length);
    void setWidth(double width);
    void setHeight(double height);
    void setAlpha(double alpha);
    void setTopOffset(Vector2DXZ offset);
    
    // Getters
    double getLenght();
    double getWidth();
    double getHeight();
    double getAlpha();
    Vector2DXZ getTopOffset();
    
    // ShapeInterface implementation
    double getSurfaceArea() override;
    double getVolume() override;
    std::vector<Face> getFaces() override;
};
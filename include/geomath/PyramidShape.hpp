#pragma once

#include <cstdint>
#include <vector>
#include "ShapeInterface.hpp"
#include "geomath/types/Vector.hpp"

class PyramidShape : public ShapeInterface {
    uint32_t segment_n;
    double radius;
    double height;
    Vector2DXZ offset;
    bool is_custom_vertices;
    std::vector<Vector2DXZ> custom_vertices;
public:
    PyramidShape(
        uint32_t segment_n = 4,
        double radius = 1,
        double height = 1,
        Vector2DXZ offset = {0, 0}
    );
    PyramidShape(
        std::vector<Vector2DXZ> vertices = {
            {-0.5, 0.5}, {0.5, 0.5}, {0.5, -0.5}, {-0.5, -0.5} 
        },
        double height = 1,
        Vector2DXZ offset = {0, 0}
    );
    
    // Setters
    void setSegmentNumber(uint32_t segment_n);
    void setBaseVertices(std::vector<Vector2DXZ> vertices);
    void setRadius(double radius);
    void setHeight(double height);
    void setOffset(Vector2DXZ offset);
    
    // Getters
    uint32_t getSegmentNumber();
    std::vector<Vector2DXZ> getBaseVertices();
    double getRadius();
    double getHeight();
    Vector2DXZ getOffset();
    
    // ShapeInterface implementation
    double getSurfaceArea() override;
    double getVolume() override;
    std::vector<Face> getFaces() override;
};
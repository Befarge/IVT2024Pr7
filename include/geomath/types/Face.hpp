#pragma once

#include <vector>
#include "Vector.hpp"


class Face {
private:
    std::vector<Vector3D> vertices3D;
    bool is_vertices3D;
public:
    Face(std::vector<Vector3D>);
    Face(std::vector<Vector2DXZ>);
    Face();

    double getArea();
    std::vector<Vector3D> getVertices();
    void addVertex(Vector3D vertex);
    double getPerimetr();
    // TODO: Добавить метод для расчёта площади 
};
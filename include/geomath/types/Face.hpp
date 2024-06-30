#pragma once

#include <vector>
#include "Vector.hpp"


class Face {
private:
    std::vector<Vector3D> vertices3D;
    std::vector<Vector2DXZ> vertices2DXZ;
    bool is_3D_vertices;
public:
    Face(std::vector<Vector3D>);
    Face(std::vector<Vector2DXZ>);

    double getArea();
    double getPerimetr();
    // TODO: Добавить метод для расчёта площади 
};
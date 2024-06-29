#pragma once

#include <vector>
#include "Vector.hpp"


class Face {
    std::vector<Vector3D> vertices;
public:
    Face(std::vector<Vector3D> vertices);
    
    double getArea();
    // TODO: Добавить метод для расчёта площади 
};
#include "geomath/types/Vector.hpp"
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
    return side * side * 6;
}

double CubeShape::getVolume() {
    return side * side * side;
}

std::vector<Face> CubeShape::getFaces() {
    double hs = this->side / 2;
    std::vector<Vector3D> ptr = {{1,2,3}, {2,4,5}};
    std::vector<Face> obj;
    return obj;
    /*return {
        // Передняя
        Face({
            {-hs, -hs, hs},
            { hs, -hs, hs},
            { hs,  hs, hs},
            {-hs,  hs, hs}
        }),
        // Правая
        Face({
            {hs, -hs,  hs},
            {hs, -hs, -hs},
            {hs,  hs, -hs},
            {hs,  hs,  hs}
        }),
        // Задняя
        Face({
            { hs, -hs, hs},
            {-hs, -hs, hs},
            {-hs,  hs, hs},
            { hs,  hs, hs}
        }),
        // Левая
        Face({
            {-hs, -hs, hs},
            { hs, -hs, hs},
            { hs,  hs, hs},
            {-hs,  hs, hs}
        }),
        // Нижняя
        Face({
            {-hs, -hs, -hs},
            { hs, -hs, -hs},
            { hs, -hs,  hs},
            {-hs, -hs,  hs}
        }),
        // Верхняя
        Face({
            {-hs, hs,  hs},
            { hs, hs,  hs},
            { hs, hs, -hs},
            {-hs, hs, -hs}
        })};
        */
}
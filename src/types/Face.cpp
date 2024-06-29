#include <geomath/types/Face.hpp>

Face::Face(std::vector<Vector3D> vertices) {
    this->vertices = std::move(vertices);
}

double Face::getArea() {
    return 0;
    // TODO: Добавить тело функции 
}
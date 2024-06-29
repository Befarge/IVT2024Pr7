#include <geomath/ParallelepipedShape.hpp>

ParallelepipedShape::ParallelepipedShape(
    double length, double width, double height, Vector2DXZ top_offset
) {
    this->setLength(length);
    this->setWidth(width);
    this->setHeight(height);
    this->setTopOffset(top_offset);
}

// Setters
void ParallelepipedShape::setLength(double length) {
    this->length = length;
}
void ParallelepipedShape::setWidth(double width) {
    this->width = width;
}
void ParallelepipedShape::setHeight(double height) {
    this->height = height;
}
void ParallelepipedShape::setTopOffset(Vector2DXZ offset) {
    this->top_offset = offset;
}

// Getters
double ParallelepipedShape::getLenght() {
    return this->length;
}
double ParallelepipedShape::getWidth() {
    return this->width;
}
double ParallelepipedShape::getHeight() {
    return this->height;
}
Vector2DXZ ParallelepipedShape::getTopOffset() {
    return this->top_offset;
}


double ParallelepipedShape::getSurfaceArea() {
    // TODO: Добавить тело функции
}

double ParallelepipedShape::getVolume() {
    // TODO: Добавить тело функции
}

std::vector<Face> ParallelepipedShape::getFaces() {
    // TODO: Добавить тело функции
}
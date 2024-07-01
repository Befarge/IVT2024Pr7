#include <geomath/ParallelepipedShape.hpp>
#include <cmath>

ParallelepipedShape::ParallelepipedShape(
    double length, double width, double height, double alpha, Vector2DXZ top_offset
) {
    this->setLength(length);
    this->setWidth(width);
    this->setHeight(height);
    this->setTopOffset(top_offset);
    this->setAlpha(alpha);
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
void ParallelepipedShape::setAlpha(double alpha){
    this->alpha = alpha;
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
double ParallelepipedShape::getAlpha(){
    return alpha;
}
Vector2DXZ ParallelepipedShape::getTopOffset() {
    return this->top_offset;
}


double ParallelepipedShape::getSurfaceArea() {
    Face base = this->getFaces()[0];
    return height * base.getPerimetr() + 2 * base.getArea();
}

double ParallelepipedShape::getVolume() {
    Face base = this->getFaces()[0];
    return base.getArea() * height;
}

std::vector<Face> ParallelepipedShape::getFaces() {
    // TODO: Добавить тело функции
    // TODO: Генерация как на кубе (ручками)
    double x = this->length / 2;
    double z = this->width / 2;
    double move = 1/tan(alpha) * width; 

    
}
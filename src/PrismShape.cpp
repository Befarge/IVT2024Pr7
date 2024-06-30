#include <geomath/PrismShape.hpp>
#include <vector>
#include <iostream>

PrismShape::PrismShape(
    uint32_t segment_n, double radius,
    double height, Vector2DXZ offset
) {
    this->setSegmentNumber(segment_n);
    this->setRadius(radius);
    this->setHeight(height);
    this->setOffset(offset);
    this->is_custom_vertices = false;
}

PrismShape::PrismShape(
    std::vector<Vector2DXZ> vertices, 
    double height, Vector2DXZ offset
) {
    this->setBaseVertices(vertices);
    this->setHeight(height);
    this->setOffset(offset);
    this->is_custom_vertices = true;
}
  

void PrismShape::setSegmentNumber(uint32_t segment_n){
    this->segment_n = segment_n;
}

void PrismShape::setBaseVertices(std::vector<Vector2DXZ> vertices) {
    if (!this->is_custom_vertices) {
        std::cout << "Основание пирамиды задано радиусом";
        abort();
    }
    this->custom_vertices = std::move(vertices);
}

void PrismShape::setRadius(double radius) {
    if (this->is_custom_vertices) {
        std::cout << "Основание пирамиды задано набором вершин";
        abort();
    }
    this->radius = radius;
}

void PrismShape::setHeight(double height){
    this->height = height;
}

void PrismShape::setOffset(Vector2DXZ offset){
    this->offset = offset;
}

// Getters
uint32_t PrismShape::getSegmentNumber(){
    return this->segment_n;
}

std::vector<Vector2DXZ> PrismShape::getBaseVertices() {
    return this->custom_vertices;
}

double PrismShape::getRadius(){
    return this->radius;
}

double PrismShape::getHeight(){
    return this->height;
}

Vector2DXZ PrismShape::getOffset(){   
    return this->offset;
}


double PrismShape::getSurfaceArea() {
    // TODO: Добавить тело функции
    double perimetr;
    double area;

    if (this->is_custom_vertices)
        Face base = Face(custom_vertices);
    else //Radius mode
        Face face(this->getFaces()[0]);

    return 2 * area +  perimetr * height;
}

double PrismShape::getVolume() {
    // TODO: Добавить тело функции
    if (this->is_custom_vertices) {
        
    }
    else {
        // Radius mode
    }
}

std::vector<Face> PrismShape::getFaces() {
    // TODO: Добавить тело функции
    if (this->is_custom_vertices) {
        
    }
    else {
        // Radius mode
    }
}
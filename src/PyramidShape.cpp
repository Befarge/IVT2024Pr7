#include <geomath/PyramidShape.hpp>
#include <vector>
#include <iostream>

PyramidShape::PyramidShape(
    uint32_t segment_n, double radius,
    double height, Vector2DXZ offset
) {
    this->setSegmentNumber(segment_n);
    this->setRadius(radius);
    this->setHeight(height);
    this->setOffset(offset);
    this->is_custom_vertices = false;
}

PyramidShape::PyramidShape(
    std::vector<Vector2DXZ> vertices, 
    double height, Vector2DXZ offset
) {
    this->setBaseVertices(std::move(vertices));
    this->setHeight(height);
    this->setOffset(offset);
    this->is_custom_vertices = true;
}
  

void PyramidShape::setSegmentNumber(uint32_t segment_n){
    this->segment_n = segment_n;
}

void PyramidShape::setBaseVertices(std::vector<Vector2DXZ> vertices) {
    if (!this->is_custom_vertices) {
        std::cout << "Основание пирамиды задано радиусом";
        abort();
    }
    this->custom_vertices = std::move(vertices);
}

void PyramidShape::setRadius(double radius) {
    if (this->is_custom_vertices) {
        std::cout << "Основание пирамиды задано набором вершин";
        abort();
    }
    this->radius = radius;
}

void PyramidShape::setHeight(double height){
    this->height = height;
}

void PyramidShape::setOffset(Vector2DXZ offset){
    this->offset = offset;
}

// Getters
uint32_t PyramidShape::getSegmentNumber(){
    return this->segment_n;
}

std::vector<Vector2DXZ> PyramidShape::getBaseVertices() {
    return this->custom_vertices;
}

double PyramidShape::getRadius(){
    return this->radius;
}

double PyramidShape::getHeight(){
    return this->height;
}

Vector2DXZ PyramidShape::getOffset(){   
    return this->offset;
}


double PyramidShape::getSurfaceArea() {
    // TODO: Добавить тело функции
    if (this->is_custom_vertices) {
        
    }
    else {
        // Radius mode
    }
}

double PyramidShape::getVolume() {
    // TODO: Добавить тело функции
    if (this->is_custom_vertices) {
        
    }
    else {
        // Radius mode
    }
}

std::vector<Face> PyramidShape::getFaces() {
    // TODO: Добавить тело функции
    if (this->is_custom_vertices) {
        
    }
    else {
        // Radius mode
    }
}
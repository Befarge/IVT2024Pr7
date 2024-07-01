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
    std::vector<Face> kit = this->getFaces();
    double area = 0;

    for(int i = 0; i < kit.size(); i++){
        area += kit[i].getArea();
    }
    return area;
}

double PyramidShape::getVolume() {
    Face base;
    if (this->is_custom_vertices) {
        base = Face(this->custom_vertices);
    }
    else {
        // Radius mode
        base = Face(this->getFaces()[0]);
    }
    return base.getArea() * height;
}

std::vector<Face> PyramidShape::getFaces() {
    std::vector<Face> kit;
    Vector3D up_point = {offset.x, height, offset.z};

    if (this->is_custom_vertices) {
        kit.resize(custom_vertices.size() + 1);
        
        for (
            int i = 0, size = custom_vertices.size(), prev_index = size, next_index = 1;
            i < size; 
            i++, prev_index = 1 + (i + size - 1) % size, next_index = 1 + (i + size) % size)
        { 
            double x = custom_vertices[i].x;
            double z = custom_vertices[i].z;

            Vector3D down_point{x, 0, z};

            kit[0].addVertex(down_point);
            kit[i + 1].addVertex(up_point);
            kit[prev_index].addVertex(down_point);
            kit[next_index].addVertex(down_point);
        } 
    }
    else {
        // Radius mode
        kit.resize(segment_n + 2);
        double alpha = 360./segment_n;
            
        for (
            int i = 0, prev_index = segment_n, next_index = 1;
            i < segment_n;
            i++, prev_index = 1 + (i + segment_n - 1) % segment_n, next_index = 1 + (i + segment_n) % segment_n)
        {
            double x = int(cos((alpha * i + 180) * M_PI/180) * 100) / 100. * radius + radius;
            double z = int(sin((alpha * i + 180) * M_PI/180) * 100) / 100. * radius;

            Vector3D down_point{x, 0, z};

            kit[0].addVertex(down_point);
            kit[i + 1].addVertex(up_point);
            kit[prev_index].addVertex(down_point);
            kit[next_index].addVertex(down_point);
        }
    }
    return kit;
}
#include "Shape.h"
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>

Point2D::Point2D(double x, double y){
    this->x = x;
    this->y = y;
}  

Point3D::Point3D(double x, double y, double z){
    this->x = x;
    this->y = y;
    this->z = z;
}

bool sort_compare(Point2D p1, Point2D p2){
    double move_y = std::min_element(begin(vertex), end(vertex), min_compare)->y;
    return atan2(p1.y + move_y, p1.x) < atan2(p2.y + move_y, p2.x);
}

bool min_compare(Point2D p1, Point2D p2){
    return p1.y < p2.y;
}

std::vector<Point2D> Shape2D::sort(std::vector<Point2D> vertex){
    std::sort(++begin(vertex), end(vertex), sort_compare);
    return vertex;
}

void Shape2D::setPoint(unsigned index, Point2D point){
    vertex.at(index) = point;
}

Point2D Shape2D::getPoint(unsigned index){
    return vertex.at(index);
}

void Shape2D::show_point(){
    for(Point2D point : vertex){
        std::cout << point.x << " " << point.y << std::endl;
    }
}

Polygon::Polygon(std::vector<Point2D> vertex){
    this->vertex = sort(vertex);
}

double Polygon::getP(){
    double P = 0;

    for(int i = 0; i < vertex.size(); i++){
        P += sqrt(pow(vertex[i].x - vertex[(i + 1) % vertex.size()].x, 2) + pow(vertex[i].y - vertex[(i + 1) % vertex.size()].y , 2));
    }
    return P;
}

double Polygon::getS(){
    double S = 0;
    
    for(int i = 0; i < vertex.size(); i++){
        S += 0.5 * (vertex[i].x * vertex[(i+1) % vertex.size()].y - vertex[i].y * vertex[(i+1) % vertex.size()].x);
    }
    return S;
}


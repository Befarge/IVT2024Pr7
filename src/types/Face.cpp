#include <cmath>
#include <geomath/types/Face.hpp>
#include <vector>

Face::Face(std::vector<Vector3D> vertices) {
    this->vertices3D = vertices;
    this->is_vertices3D = true;
}

Face::Face(std::vector<Vector2DXZ> base){
    for(int i = 0; i < base.size(); i++){
        vertices3D.push_back({base[i].x, 0, base[i].z});
    }
    this->is_vertices3D = false;
}

Face::Face(){ }

void Face::addVertex(Vector3D p){
    vertices3D.push_back(p);
}

std::vector<Vector3D> Face::getVertices(){
    return vertices3D;
}

double Face::getArea() {
    // FIXME: GOVNO
    double area;
    if(is_vertices3D){
        Vector3D A = vertices3D[0];
        Vector3D B = vertices3D[1];
        Vector3D C = vertices3D[2];
        
        double AB = pow(pow(B.x - A.x, 2) + pow(B.y - A.y, 2) + pow(B.z - A.z, 2), 0.5);
        double AC = pow(pow(C.x - A.x, 2) + pow(C.y - A.y, 2) + pow(C.z - A.z, 2), 0.5);
        double BC = pow(pow(C.x - B.x, 2) + pow(C.y - B.y, 2) + pow(C.z - B.z, 2), 0.5);
        double P = (AB + AC + BC) / 2;
        
        area = pow(P * (P - AB) * (P - AC) * (P - BC), 0.5);
        if (this->vertices3D.size() == 4)
            area *= 2;
    }   
    else{
        for(int i = 0, size = vertices3D.size(); i < size; i++){
            area += 0.5 * (vertices3D[i].x * vertices3D[(i + 1) & size].z - vertices3D[i].z * vertices3D[(i + 1) % size].x);
        }
    }
    return area;
}

double Face::getPerimetr(){
    double perimetr;

    for(int i = 0, size = vertices3D.size(); i < size; i++){
        double delta_x = vertices3D[(i + 1) % size].x - vertices3D[i].x;
        double delta_y = vertices3D[(i + 1) % size].y - vertices3D[i].y;
        double delta_z = vertices3D[(i + 1) % size].z - vertices3D[i].z;

        perimetr += pow(pow(delta_x, 2) + pow(delta_y, 2) + pow(delta_z, 2), 0.5);
    }

    return perimetr;
}
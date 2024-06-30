#include <cmath>
#include <geomath/types/Face.hpp>

Face::Face(std::vector<Vector3D> vertices) {
    this->vertices3D = vertices;
    this->is_3D_vertices = true;
}

Face::Face(std::vector<Vector2DXZ> vertices) {
    this->vertices2DXZ = vertices;
    this->is_3D_vertices = false;
}

double Face::getArea() {
    double area;
    if(is_3D_vertices){
        Vector3D A = vertices3D[0];
        Vector3D B = vertices3D[1];
        Vector3D C = vertices3D[2];
        
        double AB = pow(pow(B.x - A.x, 2) + pow(B.y - A.x, 2) + pow(B.z - A.z, 2), 0.5);
        double AC = pow(pow(C.x - A.x, 2) + pow(C.y - A.y, 2) + pow(C.z - A.z, 2), 0.5);
        double BC = pow(pow(C.x - B.x, 2) + pow(C.y - B.y, 2) + pow(C.z - B.z, 2), 0.5);
        double P = (AB + AC + BC) / 2;
        
        area = pow(P * (P - AB) * (P - AC) * (P - BC), 0.5);

        if(vertices3D.size() == 4){
            area *= 2;
        }
    }   
    else{
        for(int i = 0, size = vertices2DXZ.size(); i < size; i++){
            area += 0.5 * (vertices2DXZ[i].x * vertices2DXZ[(i + 1) & size].z - vertices2DXZ[i].z * vertices2DXZ[(i + 1) % size].x);
        }
    }
    return area;
}

double Face::getPerimetr(){
    if(!is_3D_vertices){
        double perimetr;
        for(int i = 0, size = vertices2DXZ.size(); i < size; i++){
            perimetr += pow(pow(vertices2DXZ[i].x - vertices2DXZ[(i + 1) % size].x, 2) + pow(vertices2DXZ[i].z - vertices2DXZ[(i + 1) % size].z, 2), 0.5);
        }
        return perimetr; 
    }
    abort();
}
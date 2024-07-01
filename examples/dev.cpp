#include <geomath/CubeShape.hpp>
#include <iostream>

int main() {
    CubeShape cube(10);
    
    std::cout << "Area: " << cube.getSurfaceArea() << "\n";
    std::cout << "Volume: " << cube.getVolume() << "\n";
    
    auto faces = cube.getFaces();
    
    std::cout << "Faces: ";
    for (auto f : faces) {
        std::cout << "\n\t[";
        auto verts = f.getVertices();
        /*for (auto v : verts) {
            std::cout << "{" << v.x << ", " << v.y << ", " << v.z << "}";
        }*/
        std::cout << f.getArea();
        std::cout << "]";
    }
    std::cout << '\n';
}
#include <geomath/CubeShape.hpp>
#include <iostream>

int main() {
    CubeShape cube(10);
    
    std::cout << "Area: " << cube.getSurfaceArea() << "\n";
    std::cout << "Volume: " << cube.getVolume() << "\n";
}
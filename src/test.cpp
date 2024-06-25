#include <vector>
#include <iostream>

class ShapeInterface {
public:
    virtual double getSurfaceArea() = 0;
    virtual double getVolume() = 0;
    
    virtual std::vector<double> getVertices() = 0;
    virtual std::vector<double> getEdges() = 0;
};



class Cube : public ShapeInterface {
    double side = 1.0;

public:
    Cube(double side) {
        this->side = side;
        
    }

    // Setters
    void changeSide(double new_side) {
        this->side = new_side;
    }

    // Getters
    double getSide() {
        return this->side;
    }

    double getSurfaceArea(void) override {
        return 6 * side * side;
    }

    double getVolume(void) override {
        return side * side * side;
    }

    std::vector<double> getVertices() override {
        std::vector<double> vertices = {0, 0, 0, side, 0, 0, 0, side, 0, side, side, 0, 0, 0, side, side, 0, side, side, side, 0, 0, side, side, side};
        return vertices;
    }

    std::vector<double> getEdges() override {
        std::vector<double> edges = {0, 1, 0, 2, 0, 4, 1, 3, 1, 5, 2, 3, 2, 6, 3, 7, 4, 5, 4, 6, 5, 7, 6, 7};
        return edges;
    }

    struct point2d {
        float x, z;
    };

    void n(std::vector<point2d> v, double height);
    void n(double radius, unsigned short n_segments, double hegiht)
};

int main() {
    Cube cube = Cube(1);
    ShapeInterface* _cube = &cube;


    std::cout << "Area: " << _cube->getSurfaceArea() << "\n";
}
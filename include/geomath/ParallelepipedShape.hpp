#include "ShapeInterface.hpp"

class ParallelepipedShape : public ShapeInterface {
    double length;
    double width;
    double height;
    // TODO: Добавить смещение по углу, либо по 2D вектору
public:
    ParallelepipedShape(double length, double width, double height);
    
    // Setters
    void setLength(double side);
    void setWidth(double width);
    void setHeight(double height);
    
    // Getters
    double getLenght();
    double getWidth();
    double getHeight();
    
    // ShapeInterface implementation
    double getSurfaceArea() override;
    double getVolume() override;
    std::vector<Vector3D> getVertices() override;
    std::vector<double> getEdges() override;
};
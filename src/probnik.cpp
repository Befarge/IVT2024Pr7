#include <cmath>
#include <vector>
#include <iostream>

class ShapeInterface {
public:
    struct point3d{
        double x;
        double y;
        double z;

        point3d(double x, double y, double z){
            this->x = x;
            this->y = y;
            this->z = z;
        }
    };
    virtual double getSurfaceArea() = 0;
    virtual double getVolume() = 0;
    virtual std::vector<point3d> getVertices() = 0;
    virtual std::vector< std::vector<point3d> > getEdges() = 0;
};


/*class Cube : public ShapeInterface {
protected:
    double side;
    std::vector<double> vertices;
    std::vector< std::vector<double> > edges;
public:
    Cube(double temp_side) {
        side = temp_side;
    }

    // Setters
    void changeSide(double temp_side) {
        side = temp_side;
    }

    // Getters
    double getSide(void) {
        return side;
    }

    double getSurfaceArea(void) override {
        return 6 * side * side;
    }

    double getVolume(void) override {
        return side * side * side;
    }

    std::vector<double> getVertices() override{
        vertices = {};
        return vertices;
    }
    
    std::vector< std::vector<double> > getEdges() override{
        edges = {};
        return edges;
    }
};*/

class Prisma : public ShapeInterface {
protected:
    std::vector<point3d> vertices;
    std::vector< std::vector<point3d> > edges;
    double radius;
    double height;
    int segment;

public:
    Prisma(double _radius, double _height, int _segment){
        radius = _radius;
        height = _height;
        segment = _segment;
        getVertices();
    }
    
    double getSurfaceArea(void) override{
        return 1.0;
    }

    double getVolume(void) override{
        return 1.0;
    }

    std::vector<point3d> getVertices() override{ //костыль
        if(vertices.empty()){
            edges.resize(segment + 2);
            double alpha = 360./segment;
            

            for(int i = 0; i < segment; i++){
                double x = int(cos(alpha * i * M_PI/180) * 100) / 100. * radius;
                double z = int(sin(alpha * i * M_PI/180) * 100) / 100. * radius;

                vertices.push_back(point3d(x, 0, z));
                vertices.push_back(point3d(x, height, z)); 
                edges[0].push_back(point3d(x, 0, z));
                edges[1].push_back(point3d(x,  height, z));
            }

            for(int i = 0, j = 0; i < vertices.size(); i += 2, j++){
                edges[2 + j].push_back(vertices[i]);
                edges[2 + j].push_back(vertices[i + 1]);
                edges[2 + j].push_back(vertices[(i + 2) % vertices.size()]);
                edges[2 + j].push_back(vertices[(i + 3) % vertices.size()]);

            }
        }
        return vertices;
    }
    
    std::vector< std::vector<point3d> > getEdges() override{
        getVertices();
        return edges;
    }

    void changeHeight(double new_height){
        height = new_height;
        vertices.clear();
        edges.clear();
    }

    void changeRadius(double new_radius){
        radius = new_radius;
        vertices.clear();
        edges.clear();
    }


    void show(){
        for(auto j : edges){
            for(auto i : j){
                std::cout << i.x << " " << i.y << " " << i.z << std::endl;
            }
            std::cout << std::endl;
        }
    }
};



int main(){
    Prisma obj(1,1,6);
    obj.show();
}
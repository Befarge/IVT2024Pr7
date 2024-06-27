#include <vector>


struct Point2D{
    double x;
    double y;

    Point2D(double x, double y);   
};

struct Point3D{
    double x;
    double y;
    double z;

    Point3D(double x, double y, double z);   
};


class Shape2D{
    private:
        bool min_compare(Point2D, Point2D);
        bool sort_compare(Point2D, Point2D, std::vector<Point2D>);
    protected:
        std::vector<Point2D> sort(std::vector<Point2D>);
    public:
        virtual double getP() = 0;
        virtual double getS() = 0;
        void show_point();
        void setPoint(unsigned, Point2D);
        Point2D getPoint(unsigned);
        std::vector<Point2D> vertex;
};

class Polygon : public Shape2D{
    public:
        Polygon(std::vector<Point2D>);
        double getP();
        double getS();
};
#include <iostream>
#include <cmath>
#include <memory>
class Point
{
private:
        Point(float x, float y)
            :m_x(x),
            m_y(y)
        {}

    class PointFactory
    {
    public:
        static std::unique_ptr<Point> makePolarPoint(float r, float t)
        {
            return std::unique_ptr<Point>(new Point(r * std::cos(t), r * std::sin(t)));
        }
        static std::unique_ptr<Point> makeCartesianPoint(float x, float y)
        {
            return std::unique_ptr<Point> ( new Point{x, y});
        }
    };
public:
    static PointFactory pointFactory;
    void print()
    {
        std::cout << "x = " << m_x << "\n";
        std::cout << "y = " << m_y << "\n";
    }
private:
    float m_x;
    float m_y;
};

int main() 
{
    std::unique_ptr<Point> pPolar = Point::pointFactory.makePolarPoint(4, 6.28);
    pPolar->print();
    std::unique_ptr<Point> pCarest = Point::pointFactory.makeCartesianPoint(4, 6.28);
    pCarest->print();

    return 0;
}

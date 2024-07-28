#include <iostream>
#include <cmath> 
using namespace std;

class Point {
    float x, y;
    Point(float x, float y) : x(x), y(y) { }
public:
    static Point rectangular(float x, float y) {
        return Point(x, y);
    }
    
    static Point polar(float radius, float angle) {
        return Point(radius * cos(angle), radius * sin(angle));
    }
    
    void show() const {
        cout << "x = " << x << ", y = " << y << endl;
    }
};

int main() {
    Point p1 = Point::rectangular(3.0, 4.0);
    Point p2 = Point::polar(5.0, 0.927295);  
    p1.show();
    p2.show();
    
    return 0;
}


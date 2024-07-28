#include<iostream>
#include <cmath>
using namespace std;

class Point{
public:
    static Point rectangular(float x, float y);
    static Point polar(float radius, float angle);
    
    void show() const {
        cout << "x = " << i << ", y = " << j << endl;
    }
private:
    Point(float x, float y);
    float i, j;
};

inline Point :: Point(float x, float y) : i(x), j(y){}

inline Point Point :: rectangular(float x, float y){
    return Point(x, y);
}

inline Point Point :: polar(float radius, float angle){
    return Point(radius*cos(angle),radius*sin(angle));
}

int main(){
    Point p1 = Point::rectangular(5.7, 1.2);
    Point p2 = Point::polar(5.7, 1.8);
    
    p1.show();
    p2.show();
    return 0;
}

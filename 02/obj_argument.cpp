#include <iostream>
using namespace std;

class Circle {
private:
    double radius;

public:
    // Constructor to initialize the radius
    Circle(double r) : radius(r) {}

    // Getter for radius
    double getRadius() const {
        return radius;
    }
};

// Function that calculates the area of a Circle object
double calculateArea(const Circle &c) {
    const double PI = 3.14159265358979323846;
    return PI * c.getRadius() * c.getRadius();
}

int main() {
    // Create a Circle object
    Circle circle(5.0);

    // Calculate the area by passing the Circle object to the function
    double area = calculateArea(circle);

    // Display the area
    cout << "The area of the circle with radius " << circle.getRadius() << " is: " << area << endl;

    return 0;
}


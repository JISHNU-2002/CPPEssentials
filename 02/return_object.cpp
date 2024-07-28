#include <iostream>
using namespace std;

class Rectangle {
private:
    double length, width;

public:
    // Constructor to initialize the rectangle dimensions
    Rectangle(double l, double w) : length(l), width(w) {}

    // Method to display rectangle dimensions
    void display() const {
        cout << "Length: " << length << ", Width: " << width << endl;
    }

    // Static method to create a square
    static Rectangle createSquare(double sideLength) {
        return Rectangle(sideLength, sideLength);
    }
};

int main() {
    // Using the static method to create a square
    Rectangle square = Rectangle::createSquare(7.0);
    cout << "Square dimensions :" << endl;
    square.display();

    return 0;
}


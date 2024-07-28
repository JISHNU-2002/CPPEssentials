#include <iostream>
using namespace std;

class FLOAT {
    float no;
public:
    // Default constructor
    FLOAT() : no(0.0) {}

    // Parameterized constructor
    FLOAT(float value) : no(value) {}

    // Method to get data
    void getdata() {
        cout << "\nENTER A FLOATING NUMBER: ";
        cin >> no;
    }

    // Method to display data
    void putdata() const {
        cout << "\nANSWER IS: " << no;
    }

    // Operator overloading for +
    FLOAT operator+(FLOAT f) {
        return FLOAT(no + f.no);
    }

    // Operator overloading for *
    FLOAT operator*(FLOAT f) {
        return FLOAT(no * f.no);
    }

    // Operator overloading for -
    FLOAT operator-(FLOAT f) {
        return FLOAT(no - f.no);
    }

    // Operator overloading for /
    FLOAT operator/(FLOAT f) {
        if (f.no != 0)
            return FLOAT(no / f.no);
        else {
            cout << "Error: Division by zero!";
            return FLOAT();
        }
    }
};

int main() {
    FLOAT f1, f2, f3;
    
    // Get data for f1 and f2
    f1.getdata();
    f2.getdata();
    
    // Addition
    f3 = f1 + f2;
    cout << "\nAfter addition:";
    f3.putdata();
    
    // Subtraction
    f3 = f1 - f2;
    cout << "\nAfter subtraction:";
    f3.putdata();
    
    // Multiplication
    f3 = f1 * f2;
    cout << "\nAfter multiplication:";
    f3.putdata();
    
    // Division
    f3 = f1 / f2;
    cout << "\nAfter division:";
    f3.putdata();

    return 0;
}


#include <iostream>
using namespace std;

class X {
    int a;
    float f;
public:
    X(int j, float x) : a(j), f(x) { }
    
    void show() {
        cout << a << " " << f << endl;
    }
};

int main() {
    X ob(99, 99.99);
    ob.show(); 
    return 0;
}


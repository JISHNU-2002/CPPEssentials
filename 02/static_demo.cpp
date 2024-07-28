#include<iostream>
using namespace std;

class static_demo{
private:
    static int a;
    int b;
public:
    void set ( int i, int j){
        a = i; 
        b = j; 
    }
    void showValues();
};

int static_demo :: a = 20; 

void static_demo :: showValues(){
    cout << "static a : " << a << " non-static b : " << b << '\n';
}

int main( ){
    static_demo x, y;
    x.set(1, 1); 
    x.showValues(); //ca = 1 & b = 1
    y.set(2, 2);
    y.showValues(); // a = 2 & b = 2
    x.showValues(); // a = 2 & b = 1
    return 0;
}

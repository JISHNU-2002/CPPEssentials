#include<iostream>
using namespace std;

class Box{
private:
    double width;
public:
    Box() : width(0) {}
    
    friend void setW(Box &obj, double w); // friend function declaration
    
    void display(){
        cout << "width of box : " << width << endl;
    }
};

void setW(Box &obj, double w){
    obj.width = w;
}

int main(){
    Box obj;
    setW(obj,3.4);
    obj.display();
    return 0;
}

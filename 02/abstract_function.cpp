#include<iostream>
using namespace std;

class Shape{
public:
    virtual void draw() = 0;
    virtual ~Shape(){}
};

class Circle : public Shape{
public:
    void draw() override{
        cout << "circle" << endl;
    }
};

class Rectangle : public Shape{
public:
    void draw() override{
        cout << "rectangle" << endl;
    }
};

int main(){
    Shape *c = new Circle();
    Shape *r = new Rectangle();
    
    c->draw();
    r->draw();
    
    delete c;
    delete r;
    return 0;
}

#include <iostream>
using namespace std;

class Base{
public:
    virtual void display(){
        cout << "base" << endl;
    }
};

class Derived1 : public Base{
public:
    void display() override{
        cout << "derived override" << endl;
    }
};

class Derived2 : public Base{
public:
    void display(){
        cout << "derived" << endl;
    }
};

int main(){
    Base *ptr;
    Base base;
    ptr = &base;
    ptr->display();
    
    Derived1 obj1;
    obj1.display();
    ptr = &obj1;
    ptr->display();
    
    Derived2 obj2;
    obj2.display();
    return 0;
}

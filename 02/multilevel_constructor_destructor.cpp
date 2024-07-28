#include<iostream>
using namespace std;

class base{
public:
    base(){
        cout << "constructing base\n";
    }
    ~base(){ 
        cout << "destructing base\n";
    }
};

class derived1 : public base{
public:
    derived1(){
        cout << "constructing derived1\n";
    }
    ~derived1(){
        cout << "destructing derived1\n";
    }
};

class derived2 : public base{
public:
    derived2(){
        cout << "constructing derived2\n";
    }
    ~derived2(){
        cout << "destructing derived2\n";
    }
};

int main(){
    derived1 obj1;
    derived2 obj2;
    return 0;
}



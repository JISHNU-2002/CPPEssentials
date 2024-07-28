#include<iostream>
using namespace std;

class base1{
public:
    base1(){
        cout << "constructing base1\n";
    }
    ~base1(){ 
        cout << "destructing base1\n";
    }
};

class base2{
public:
    base2(){
        cout << "constructing base2\n";
    }
    ~base2(){ 
        cout << "destructing base2\n";
    }
};


class derived : public base2, public base1{
public:
    derived(){
        cout << "constructing derived\n";
    }
    ~derived(){
        cout << "destructing derived\n";
    }
};

int main(){
    derived ob;
    return 0;
}



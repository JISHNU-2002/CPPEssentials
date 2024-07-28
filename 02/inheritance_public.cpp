#include<iostream>
using namespace std;

class A{
protected: // public / private / protected
    int i,j;
public:
    void set(int a,int b){
        i = a;
        j = b;
        cout << i+j << endl;
    }
    void display(){
        cout << "parent - A" << endl;
    }
};

class B : public A{ // public
public:
    void display(){
        cout << "derived - B" << endl;
    }
};

int main(){
    B obj;
    obj.display();
    obj.set(1,2);
    return 0;
}

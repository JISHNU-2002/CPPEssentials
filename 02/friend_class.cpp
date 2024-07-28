#include<iostream>
using namespace std;

class B; // forward declaration

class A{
private:
    int data;
public:
    A() : data(0) {}
    friend class B;
};

class B{
public:
    void setData(A &obj, int value){
        obj.data = value;
        cout << "Data in class A : " << obj.data << endl;
    }
};

int main(){
    A aobj;
    B bobj;
    bobj.setData(aobj,100);
    return 0;
}

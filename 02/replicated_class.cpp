#include<iostream>
using namespace std;

class base{
    public: int i; 
};

class derived1 : public base{ 
    public: int j; 
};

class derived2 : public base{ 
    public: int k; 
};

class derived3 : public derived1, public derived2{
public:
    int sum;
};

int main(){
    derived3 ob;
    ob.derived1::i = 50;
    ob.j=90;
    ob.k=80;
    int sum = ob.derived1::i + ob.j + ob.k;
    cout << sum << endl;
}

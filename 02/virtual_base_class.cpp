#include<iostream>
using namespace std;

class base{
    public: int i;
};

class derived1 : virtual public base{
    public:int j;
};

class derived2 : virtual public base{
    public:int k;
};

class derived3 : public derived1, public derived2{ 
    public: int sum; 
};

int main(){
    derived3 ob;
    ob.i = 50; ob.j = 20; ob.k = 30;
    int sum = ob.i + ob.j + ob.k;
    cout << sum << endl;
    return 0;
}

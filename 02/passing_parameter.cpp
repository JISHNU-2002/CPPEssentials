#include<iostream>
using namespace std;

class base1{
public: int x;
    base1(int a){
        x = a; 
        cout << "constructing base1\n";
    }
    ~base1(){
        cout << "destructing base1\n";
    }
};

class derived: public base1{
    int y;
public:
    derived(int i, int j) : base1(j){
        y = i; 
        cout << "constructing derived\n";
    }
    ~derived() { 
        cout << "destructing derived\n";
    }
    void show(){ 
        cout << x << y << endl;
    }
};

int main(){
    derived ob(1,2); 
    ob.show(); 
    return 0;
}

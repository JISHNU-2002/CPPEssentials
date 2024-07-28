#include <iostream>
using namespace std;

template<typename T>
class MyClass{
private:
    T value;
public:
    MyClass(T val) : value(val) {}
    
    void display(){
        cout << "value : " << value << endl;
    }
};

int main(){
    MyClass<int> intObj(10);
    MyClass<double> doubleObj(10.24);
    MyClass<string> strObj("hello world");
    
    intObj.display();
    doubleObj.display();
    strObj.display();
    return 0;
}

#include<iostream>
using namespace std;

class CMF {
    mutable int value;
public:
    CMF(int v = 0) { // constructor
        value = v;
    }

    int getValue() const{ 
        value = 100; // We get compiler error if we add a line like "value = 100;" without mutable keyword
        return value; 
    }
};

int main(){
    CMF t(20);
    cout<<t.getValue()<<endl;
    return 0;
}

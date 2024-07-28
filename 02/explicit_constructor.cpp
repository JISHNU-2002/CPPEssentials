#include <iostream>
using namespace std;

class test {
    int i , j;
public:
    test() { i=100; j=200;}
    explicit test(int x) { i=x; j=x+10; }
    test(int x , int y){ i = x; j = y; }
    
    void disp() { 
        cout<<"I="<<i<<endl; 
        cout<<"J="<<j<<endl; 
    }
};

int main() {
    test m2(10); 
    m2.disp();
}

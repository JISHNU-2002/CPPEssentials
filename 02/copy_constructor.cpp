#include <iostream>
#include <cmath> 
using namespace std;

class mycl{
    int x;
public:
    mycl(){
        x = 10;
    }

    void changex(int i) {
        x = i;
    }

    void printx(){
        cout << x << endl;
    }
};

int main(){
    mycl a;
    a.printx();

    mycl b(a);
    b.printx();
    
    a.changex(55);
    b.printx();
    a.printx();
    
    return 0;
}

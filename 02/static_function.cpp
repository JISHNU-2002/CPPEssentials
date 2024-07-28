#include<iostream>
using namespace std;

class Demo_static{
private:
    static int i;
public:
    static void init ( int x){ 
        i = x; 
    }
    void show( ){
        cout << i << endl;
    }
};

int Demo_static::i ; // define i

int main(){
    // initialize static data before object creation
    Demo_static :: init(100);
    Demo_static x;
    x.show(); // displays
    return 0;
}

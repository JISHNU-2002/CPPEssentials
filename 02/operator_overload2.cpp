#include<iostream>
using namespace std;

class loc{
    int x, y;
public:
    loc() {}
    loc(int lg, int lt) {
        x = lg; y = lt;
    }
    void show() {
        cout << x << y;
    }
    
    loc operator+(loc op2);
    loc operator-(loc op2);
    loc operator&&(loc op2);
};

loc loc :: operator+(loc op2){
    loc temp;
    temp.x = op2.x + x;
    temp.y = op2.y + y;
    return temp;
}

loc loc :: operator-(loc op2){
    loc temp;
    temp.x = op2.x - x;
    temp.y = op2.y - y;
    return temp;
}

loc loc :: operator&&(loc op2){
    loc temp;
    temp.x = op2.x && x;
    temp.y = op2.y && y;
    return temp;
}

int main(){
    loc ob1(10, 20), ob2( 5, 30);loc ob3;
    ob1.show();
    ob2.show();
    ob3 = ob1 + ob2;
    ob3.show();
    ob3 = ob1 - ob2;
    ob3.show();
    ob3 = ob1 && ob2;
    ob3.show();
    return 0;
}

loc loc :: operator=(loc op2){
    x = op2.x;
    y = op2.y;
    return *this;
}

loc loc :: operator++(){
    x++;
    y++;
    return *this;
}

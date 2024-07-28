#include <iostream>
using namespace std;

template <typename T>
void mySwap(T &a, T &b) {  // Pass parameters by reference
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int i = 1, j = 2;
    float x = 1.2f, y = 3.4f;
    string str1 = "hello", str2 = "world";
    
    mySwap(i, j);
    mySwap(x, y);
    mySwap(str1, str2);
    
    cout << i << " " << j << endl;       // Output: 2 1
    cout << x << " " << y << endl;       // Output: 3.4 1.2
    cout << str1 << " " << str2 << endl; // Output: world hello

    return 0;
}


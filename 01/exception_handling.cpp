#include <iostream>
using namespace std;

int main() {
    try {
        int num1, num2;
        cout << "Enter two numbers: ";
        cin >> num1 >> num2;

        if (num2 == 0) {
            throw "Division by zero!"; // Throwing an exception
        }

        cout << "Result: " << num1 / num2 << endl;
    }
    catch (const char* e) {
        cout << "Error : " << e << endl; // Handling the exception
    }

    return 0;
}


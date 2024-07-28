#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
using namespace std;

class MyException : public exception {
public:
    const char* what() const noexcept override {
        return "User-Defined Exception";
    }
};

int main() {
    try {
        int a, b, n, c;
        string name;
        bool custom = true;

        cout << "Enter two numbers: ";
        cin >> a >> b;
        cout << "Enter the name: ";
        cin >> name;
        cout << "Enter array length: ";
        cin >> n;

        if (n <= 0) {
            throw out_of_range("Array length must be positive");
        }

        int* array = new int[n]; // dynamically allocate the array

        try {
            cout << "Enter array elements: ";
            for (int i = 0; i < n; i++) {
                cin >> array[i];
            }

            cout << "Enter array index to access: ";
            cin >> c;

            try {
                if (b == 0) {
                    throw runtime_error("Divide by Zero Exception");
                }
                cout << "Division result: " << a / b << endl;

                if (name.length() > 5) {
                    throw string("String is too long");
                }
                cout << "Name: " << name << endl;

                if (c < 0 || c >= n) {
                    throw out_of_range("Array out of bounds Exception");
                }
                cout << "Array element at index " << c << ": " << array[c] << endl;

                if (custom) {
                    throw MyException();
                }
            } catch (const runtime_error& e) {
                cout << "Error: " << e.what() << endl;
            } catch (const string& e) {
                cout << "Error: " << e << endl;
            } catch (const out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            } catch (const MyException& e) {
                cout << "Error: " << e.what() << endl;
            } catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            } catch (...) {
                cout << "Unknown error occurred" << endl;
            }
        } catch (const out_of_range& e) {
            cout << "Error: " << e.what() << endl;
        }

        delete[] array; // free the dynamically allocated memory
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    } catch (...) {
        cout << "Unknown error occurred" << endl;
    }

    return 0;
}


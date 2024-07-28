#include <iostream>
using namespace std;

class Vector {
private:
    int *arr;
    int size;

public:
    Vector() : arr(nullptr), size(0) {}

    void alloc(int s) {
        size = s;
        arr = new int[size];
    }

    void read() {
        cout << "Enter " << size << " elements: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    void showsum() {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }
        cout << "Sum of elements: " << sum << endl;
    }

    ~Vector() {
        delete[] arr;
    }
};

int main() {
    Vector *v1;
    cout << "\nHow many Vector objects?\n";
    int count;
    cin >> count;

    v1 = new Vector[count];

    // Assuming we are allocating, reading, and displaying for each Vector object
    for (int i = 0; i < count; ++i) {
        (v1 + i)->alloc(5);  // Allocating memory for 5 elements in each Vector
        (v1 + i)->read();    // Reading elements into each Vector
        (v1 + i)->showsum(); // Displaying the sum of elements in each Vector
    }

    delete[] v1; // Deallocating the array of Vector objects

    return 0;
}


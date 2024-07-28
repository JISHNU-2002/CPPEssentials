#include <iostream>
using namespace std;

class Student {
    string name;
    int age;
public:
    // Constructor
    Student(string n, int a) : name(n), age(a) {}
    
    // Method to display student details
    void display() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    // Create an array of Student objects
    Student students[3] = {
        Student("Alice", 20),
        Student("Bob", 22),
        Student("Charlie", 21)
    };
    
    // Access and display the details of each student
    for (int i = 0; i < 3; ++i) {
        students[i].display();
    }
    
    return 0;
}


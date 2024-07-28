#include<iostream>
using namespace std;

class Student{
private:
    int num;
    string name;
public:
    Student() : num(0), name("") {}
    Student(int n, string s) : num(n), name(s) {}
    
    void setData(int n, string s){
        num = n;
        name = s;
        cout << "roll number : " << num << " name : " << name << endl;
    }
};

int main(){
    Student *ptr;
    int i,j,num;
    string name;
    cout << "No of many students : ";
    cin >> j;
    
    ptr = new Student[j];  // dynamic allocation of array of j student objects	
    for(i=0; i<j; i++){
        cout << "enter student details : ";
        cin >> num >> name;
        ptr[i].setData(num,name);
    }
    
    delete[] ptr;         // deallocate memory
    return 0;
}

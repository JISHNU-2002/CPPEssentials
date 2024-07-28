# Let's C++
### Object Oriented Programming
- 5 Pillars of OOP
	1. Class & Object
		- Class defines the nature of an object, containing data and functions
		- Object is an instance of a class
	1. Abstraction
		- Simplifying complex real-world objects
		- Well-defined public interfaces for interaction
	2. Encapsulation
		-  Hiding implementation details
		- Attributes and behaviors kept together
	1. Inheritance
		- Derived class inherits from base class
		- Adds unique attributes and behaviors
	2. Polymorphism
		-  Ability to exist in multiple forms
		- Overridden behaviors across subclasses

### Access Specifiers
- **private**
	- to encapsulate or hide the member data in the class
- **public** 
	- to expose the member functions to the outside world,\that is, to outside functions as interfaces to the class
### this pointer
- Created automatically by the compiler
- Contains the address of the object through which the function is invoked

```C++
class Simple {
private:
	int id;
public:
	void setID(int id) { 
		this->id = id; 
	}
	int getID() { 
		return this->id; 
	}
};
```

### Scope Resolution Operator ::
- Allows the body of the member functions to be separated from the body of the class
- To define the function outside the class
- To access the global Variables 
- To define the static variables
- To invoke the static functions

```C++
return_type class_name :: function_name () {}

data_type class_name :: variable_name = value ;
```

### Static Class Members – Static Data Members
- Only one copy of that variable will exist
- All objects of that class will share that variable
- Not stored in objects
  
```C++
#include <iostream>
using namespace std;

class static_demo{
private:
    static int a;
    int b;
public:
    void set ( int i, int j){
        a = i; 
        b = j; 
    }
    void showValues();
};

int static_demo :: a = 20; 

void static_demo :: showValues(){
    cout << "static a : " << a << " non-static b : " << b << '\n';
}

int main(){
    static_demo x, y;
    x.set(1, 1); 
    x.showValues(); // a = 1 & b = 1
    y.set(2, 2);
    y.showValues(); // a = 2 & b = 2
    x.showValues(); // a = 2 & b = 1
    return 0;
}
```

### A mutable Object Member
- A const member function cannot modify the state of its object
- A mutable member is never const, even if its object is const ; therefore, it can be modified by a const member function
```C++
#include <iostream>
using namespace std;

class CMF {
    mutable int value;
public:
    CMF(int v = 0) { // constructor
        value = v;
    }

    int getValue() const{ 
        value = 100; /* if mutable keyword was not used, we get compiler error */
        return value;
    }
};

int main(){
    CMF t(50); // calling constructor + object creation
    cout << "value : " << t.getValue() << endl; // value : 100
    return 0;
}
```

### Function Overloading
- Process of using the same name for two or more functions
- Functions either have different types of parameters or a different number of parameters or different return types

### Constructors
- Invoked automatically when an object is created
- Declared in the public section
- Does not have return types
```C++
class_name()
```

#### Constructor - Initializing using initializer list
- Initialization list executes more faster than normal constructor
- Assignment within constructor cannot be used if try-throw-catch statements have to be included
```C++
class X{
	int a;
	float f;
public:
	X(int j, float x) : a(j) , f(x) , b(a) {} /* this->a = j, this->f = x,      b = this->a */
```

#### Named constructors
---
- Declare all the constructors in the private section and you provide public static methods to return an object
- These static methods are called the Named Constructors

```C++
inline class_name :: constructor ( ) {}

inline class_name constructor :: function_name ( ) {}
```
- `inline` suggests that the compiler should replace the function call with the function code to reduce overhead
- object initialization is efficient, especially since it's a simple assignment operation


```C++
#include <iostream>
#include <cmath>  
using namespace std;

class Point {
    float x, y;
    Point(float x, float y) : x(x), y(y) { }
public:
    static Point rectangular(float x, float y) {
        return Point(x, y);
    }
    
    static Point polar(float radius, float angle) {
        return Point(radius * cos(angle), radius * sin(angle));
    }
    
    void show() const {
        cout << "x = " << x << ", y = " << y << endl;
    }
};

int main() {
    Point p1 = Point :: rectangular(3.0, 4.0);
    Point p2 = Point :: polar(5.0, 0.927295);
    p1.show();
    p2.show();
    return 0;
}
```

#### Copy constructors
---
- Constructor function with the same name as the class and used to make deep copy of objects
- if a class has a pointer variable, a copy constructor has to be defined

- When an object is created from another object of the same type
- When an object is passed by value as a parameter to a function
- When an object is returned from a function

```C++
constructor a;
constructor b(a);
```

#### Explicit constructors
---
- Constructor with only one required parameter is considered an implicit conversion function
- It converts the parameter type to the class type
- Not depends on the semantics of the constructor
```C++
test() { i=100; j=200; }
explicit test(int x) { i=x; j=x+10; }
test(int x , int y){ i = x; j = y; }
```

#### Array of objects
```C++
class Array{
	int i, j;
public:
	Array(int x, int y) : x(i), y(j) { }
};

int main() {
	Array obj[3] = { Array(1,2), Array(3,4), Array(5,6) };
	// Array obj[3] = { (1,2), (3,4), (5,6) };
	return 0;
}
```

### Destructors
- Invoked implicitly when the object is destroyed
- Clean up and release resources
- Never call a destructor
- Does not take any parameter and does not return any value
```bash
~class_name(){
	delete variable;
}
```

### Static Member Functions
- Static member functions can only access static data members
- They do not have a `this` pointer
- Cannot be virtual or const/volatile
- Useful for initializing static data before any object is created

```C++
#include <iostream>
using namespace std;

class DemoStatic {
private:
    static int i;  // Static data member

public:
    static void init(int x) {
        i = x;  // Static member function
    }

    void show() const {
        cout << i << endl;  // Non-static member function
    }
};

int DemoStatic::i = 0; // Define the static member variable

int main() {
    DemoStatic::init(100); // Initialize static data before object creation
    DemoStatic obj1;
    obj1.show();  // Displays : 100

    // Modify the static member through another object
    DemoStatic obj2;
    obj2.init(200);
    obj1.show();  // Displays : 200

    return 0;
}
```

#### Initialization of const static Data Members
- Integral types can be initialized inside the class
- Non-integral types must be defined outside the class

```C++
#include <iostream>
#include <string>
using namespace std;

class Buff {
private:
    static const int MAX = 512;  // Initialization & definition inside the class
    static const char FLAG = 'a';// Initialization & definition inside the class
    static const string MSG;// Declaration inside the class - non-intergral type

public:
    void show() const {
        cout << "MAX: " << MAX << endl;
        cout << "FLAG: " << FLAG << endl;
        cout << "MSG: " << MSG << endl;
    }
};

// Definition outside the class for non-integral types
const string Buff :: MSG = "Hello, World!";

int main() {
    Buff b;
    b.show();  // Displays MAX, FLAG, and MSG values
    return 0;
}
```

#### Call by Reference
- Copies the reference of an argument into the formal parameter
- Changes made to the parameter affect the actual argument

```C++
void swap(int &x, int &y) { 
	int temp = x; 
	x = y; 
	y = temp; 
} // swap(a,b);
```

### Inline Functions
- Declared with the `inline` keyword or defined inside a class
- Can be used instead of macros for small functions to improve performance

```C++
#include <iostream>
using namespace std;

class Math {
public:
    inline int add(int a, int b) {
        return a + b;
    }

    inline int subtract(int a, int b);
};

inline int Math :: subtract(int a, int b) {
    return a - b;
}

int main() {
    Math math;
    int x = 10;
    int y = 5;
    cout << x << "+" << y << "=" << math.add(x, y) << endl;
    cout << x << "-" << y << "=" << math.subtract(x, y) << endl;
    return 0;
}
```

#### Default Function Arguments
- Default values must be specified once in the function declaration
- Parameters with default values must appear to the right of non-default parameters
#### Constant Arguments
- Parameters passed as constant cannot be changed inside the function
#### Objects as Arguments
- Objects can be passed as arguments to initialize data members of another object

```C++
#include <iostream>
using namespace std;

class Circle {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    
    double getRadius() const {
        return radius;
    }
};

// Function that calculates the area of a Circle object
double calculateArea(const Circle &c) {
    const double PI = 3.14159265358979323846;
    return (PI * c.getRadius() * c.getRadius());
}

int main() {
    Circle circle(5.0);
    // Calculate the area by passing the Circle object to the function
    double area = calculateArea(circle);
    
    cout << "The area of the circle " <<  " = " << area << endl;
    return 0;
}
```

- Functions can return objects

```C++
#include <iostream>
using namespace std;

class Rectangle {
private:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    void display() const {
        cout << "Length: " << length << " Width: " << width << endl;
    }

    // Static method to create a square
    static Rectangle createSquare(double sideLength) {
        return Rectangle(sideLength, sideLength);
    }
};

int main() {
    // Using the static method to create a square
    Rectangle square = Rectangle :: createSquare(7.0);
    cout << "Square dimensions : " << endl;
    square.display();
    return 0;
}
```

#### Function Overloading and Ambiguity
- Ambiguity occurs when the compiler cannot decide between overloaded functions
- Main cause of ambiguity involves C++'s automatic type conversions
- Ambiguity can be caused by using default arguments in overloaded functions
- Two functions cannot be overloaded when the only difference is that call-by-reference & call-by-value parameter

```C++
#include <iostream>
using namespace std;

void f(int x) {
    cout << "In f(int)" << endl;
}

void f(int &x) {
    cout << "In f(int &)" << endl;
}

int main() {
    int a = 10;
    f(a); // This will call f(int &)
    f(10); // This will call f(int)
    return 0;
}
```


### Dynamic memory Concepts using new and delete
- `new` : Allocates memory dynamically and returns a pointer to the allocated memory
- `delete` : Deallocates memory that was previously allocated by `new`

```C++
int number = 88;
int *p1 = &number;  // Static allocation

int *p2 = nullptr;  // Dynamic allocation
p2 = new int;       // Allocates memory dynamically
*p2 = 99;

delete p2;          // Deallocates memory
p2 = nullptr;
```

#### `new[]` and `delete[]` Operators
- Dynamic Arrays : Allocated at runtime using `new[]`
- Deallocating Arrays : Use `delete[]` instead of `delete`

```C++
int *Array = new int[5];
delete[] Array;
```

### Dynamic Memory Allocation and Initialization
- Initializing allocated memory using initializers or constructors

```C++
int *p1 = new int(88);
double *p2 = new double(1.23);

Date *date1 = new Date(1999, 1, 1);
Time *time1 = new Time(12, 34, 56);
```

### Pointers to Classes & Objects
- Objects can be dynamically allocated and pointed to by pointers
- Used for dynamic creation and deallocation of objects

```C++
#include<iostream>
using namespace std;

class Rectangle{
private:
    int width,height;
public:
    Rectangle(int w, int h){
        width = w;
        height = h;
    }
    
    int area(){
        return width*height;
    }
    
    void display(){
        cout << " area : " << area() << endl;
    }
};

int main(){
    Rectangle obj(3,4);
    obj.display();                    // area : 12
    
    Rectangle *rect1,*rect2,*rect3;
    rect1 = &obj;
    rect1->display();                 // area : 12
    
    rect2 = new Rectangle(5,6);
    rect2->display();                 // area : 30
    
    rect3 = new Rectangle[2]{{7,8}, {9,10}};
    rect3[0].display();               // area : 56
    rect3[1].display();               // area : 90
    
    delete rect2;                     // Deallocate memory 
    delete[] rect3;
    return 0;
}
```

```C++
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
```

### Memory Leaks
- Memory leaks occur when dynamically allocated memory is not deallocated

### Dangling Pointers and Wild Pointers
- Pointers that do not point to a valid object of the appropriate type
- **Dangling Pointers** : Pointers that point to memory that has been deallocated
- **Wild Pointers** : Pointers that have not been initialized and point to arbitrary memory locations

```C++
char *dp = nullptr;
{
  char c;
  dp = &c;
}
// dp is now a dangling pointer

char *wp;  // wp is a wild pointer
static char *scp; /* scp is not a wild pointer:
```

### Creation and Using References
- A reference acts as an alias to another object or value
- Can be used as function parameters, return values, or stand-alone references

```C++
int a = 5;
int &ref = a;  // ref is a reference to a
ref = 10;      // a is now 10
```

### Call-by-Value and Call-by-Reference
- **Call-by-Value** : Passing a copy of the argument to the function
- **Call-by-Reference** : Passing the address of the argument to the function

```C++
void fnnegate(int ival) { ival = -ival; } // call-by-value
void fnnegate(int *ival) { *ival = -*ival; } // call-by-reference using pointer
void fnnegate(int &ival) { ival = -ival; } // call-by-reference using reference parameter
```

**Pointers** 
- Can be initialized anytime
- Can be reinitialized any number of time
- Can be null
- Require `*` to dereference

### References
- Must be initialized when created
- Cannot reinitialize a reference
- Cannot be null 
- Automatically dereferenced
- Passing object by reference - no copy of obj is made

#### Independent References
- References that are variables, must be initialized, cannot change the object they refer to

```C++
int a;
int &ref = a;
a = 10;     // a is now 10
ref = 100;  // a is now 100
```

#### Return by Reference
- `dataType& functionName(parameters)`
- Functions can return references, making code easier to read and maintain

```C++
#include <iostream>
using namespace std;

int x;

int& retByRef() {
    return x;
}

int main() {
    retByRef() = 10;
    cout << x;  // Output will be 10
    return 0;
}
```

### Inheritance Basics
- Inheritance is a mechanism where a new class (derived class) is created from an existing class (base class), inheriting its properties and behaviors
- Reuse existing code and create a hierarchical relationship between classes
- `class derived-class-name : access base-class-name`

#### Access Specifiers
- **Public** : Members of the base class are accessible by the derived class and other parts of the program
- **Private** : Members of the base class are not accessible by the derived class (default)
- **Protected** : Members of the base class are accessible by derived classes but not by other parts of the program

#### Types of Inheritance
- **Single Inheritance** : A class inherits from one base class
- **Multiple Inheritance** : A class inherits from more than one base class
- **Multilevel Inheritance** : A class inherits from a derived class, forming a chain
- **Hierarchical Inheritance** : Multiple classes inherit from a single base class
- **Hybrid Inheritance** : A combination of two or more types of inheritance

![Inheritance types](images/inheritance.png)

#### Constructors and Destructors in Inheritance
- Constructors of the base class are executed before the derived class
- Destructors of the derived class are executed before the base class
- In multiple inheritance, constructors are executed in the order of derivation and destructors in the reverse order

**Single Inheritance** : Constructor & Destructor
```C++
#include<iostream>
using namespace std;

class base{
public:
    base(){
        cout << "constructing base\n";
    }
    ~base(){ 
        cout << "destructing base\n";
    }
};

class derived : public base{
public:
    derived(){
        cout << "constructing derived\n";
    }
    ~derived(){
        cout << "destructing derived\n";
    }
};

int main(){
    derived ob;
    return 0;
}
```

**Multi-Level Inheritance** : Constructor & Destructor
```C++
#include<iostream>
using namespace std;

class base{
public:
    base(){
        cout << "constructing base\n";
    }
    ~base(){ 
        cout << "destructing base\n";
    }
};

class derived1 : public base{
public:
    derived1(){
        cout << "constructing derived1\n";
    }
    ~derived1(){
        cout << "destructing derived1\n";
    }
};

class derived2 : public base{
public:
    derived2(){
        cout << "constructing derived2\n";
    }
    ~derived2(){
        cout << "destructing derived2\n";
    }
};

int main(){
    derived1 obj1;
    derived2 obj2;
    return 0;
}
```

**Multiple Inheritance** : Constructor & Destructor
```C++
#include<iostream>
using namespace std;

class base1{
public:
    base1(){
        cout << "constructing base1\n";
    }
    ~base1(){ 
        cout << "destructing base1\n";
    }
};

class base2{
public:
    base2(){
        cout << "constructing base2\n";
    }
    ~base2(){ 
        cout << "destructing base2\n";
    }
};


class derived : public base1, public base2{
public:
    derived(){
        cout << "constructing derived\n";
    }
    ~derived(){
        cout << "destructing derived\n";
    }
};

int main(){
    derived ob;
    return 0;
}
```

#### Replicated base classes
- Derived classes will have duplicate sets of members inherited from the base 
- More than one copy of the base is visible
- This creates ambiguity
- If the base class has a public member i, they can be accessed by specifying derived1::i, derived2::i

```C++
#include<iostream>
using namespace std;

class base{
    public: int i; 
};

class derived1 : public base{ 
    public: int j; 
};

class derived2 : public base{ 
    public: int k; 
};

class derived3 : public derived1, public derived2{
public:
    int sum;
};

int main(){
    derived3 ob;
    ob.derived1::i = 50;
    ob.j=90;
    ob.k=80;
    int sum = ob.derived1::i + ob.j + ob.k;
    cout << sum << endl;
}
```

#### Virtual base classes
- Duplication of inherited members due to these multiple paths can be avoided
- When a class is made a virtual base class, only one copy of the class is inherited

```C++
#include<iostream>
using namespace std;

class base{
    public: int i;
};

class derived1 : virtual public base{
    public:int j;
};

class derived2 : virtual public base{
    public:int k;
};

class derived3 : public derived1, public derived2{ 
    public: int sum; 
};

int main(){
    derived3 ob;
    ob.i = 50; ob.j = 20; ob.k = 30;
    int sum = ob.i + ob.j + ob.k;
    cout << sum << endl;
    return 0;
}
```

### Virtual Functions (Polymorphism)
- `virtual return_type function`
- Declared in a base class and can be overridden by derived classes.
- Virtual Functions are Hierarchical : If not overridden in a derived class, the base class’s function is used

```C++
#include <iostream>
using namespace std;

class Base {
public:
    virtual void display() {
        cout << "Display Base class" << endl;
    }
};

class Derived : public Base {
public:
    void display() override { // Overriding the base class method
        cout << "Display Derived class" << endl;
    }
};

int main() {
    Base *ptr;          // Base class pointer
    Base base;
    Derived obj;
    
    ptr = &base;        // Pointing to Base class object
    ptr->display();     // Display Base class

    ptr = &obj;         // Pointing to Derived class object
    ptr->display();     // Display Derived class
    
    return 0;
}
```
### Pure Virtual Functions(Abstract Class)
- `virtual type func_name (parameter_list) = 0`
- A pure virtual function is a virtual function that has no definition in the base class
- Derived class must provide its own definition of the virtual function
- We cannot create an object or cannot be instantiated for an abstract class
- We can create a pointer variable for abstract class which can refer to any of its derived class

```C++
#include<iostream>
using namespace std;

class Shape{
public:
    virtual void draw() = 0;
    virtual ~Shape(){}
};

class Circle : public Shape{
public:
    void draw() override{
        cout << "circle" << endl;
    }
};

class Rectangle : public Shape{
public:
    void draw() override{
        cout << "rectangle" << endl;
    }
};

int main(){
    Shape *c = new Circle();
    Shape *r = new Rectangle();
    
    c->draw();  // circle
    r->draw();  // rectangle
    
    delete c;
    delete r;
    return 0;
}
```

#### Virtual Function Mechanics – The Virtual Table
- Late binding : The table contains pointers to virtual functions of a class
- The compiler places the addresses of the virtual functions for that particular class in the VTABLE

#### Virtual Destructor
- call the inherited class destructor as well, thus properly disposing the class instances
- Ensure proper cleanup of derived class objects when deleting a pointer to a base class

### Friend functions
- Can access private and protected members of a class.
- The function can be invoked without the use of an object
- The friend function can have its argument as objects

```C++
#include<iostream>
using namespace std;

class Box{
private:
    double width;
public:
    Box() : width(0) {}
    
    friend void setW(Box &obj, double w); // friend function declaration
    
    void display(){
        cout << "width of box : " << width << endl;
    }
};

void setW(Box &obj, double w){
    obj.width = w;
}

int main(){
    Box obj;
    setW(obj,3.4);
    obj.display();
    return 0;
}
```

### Friend Classes
- One class can be a friend of another, gaining access to its private members

```C++
#include<iostream>
using namespace std;

class B; // forward declaration

class A{
private:
    int data;
public:
    A() : data(0) {}
    friend class B;
};

class B{
public:
    void setData(A &obj, int value){
        obj.data = value;
        cout << "Data in class A : " << obj.data << endl;
    }
};

int main(){
    A aobj;
    B bobj;
    bobj.setData(aobj,100);  // Data in class A : 100
    return 0;
}
```
### Namespaces
- Group classes, objects, and functions under a single name to avoid name conflicts
- `namespace identifier { entities }`


### Operator Overloading
- It is a type of polymorphism in which an operator is overloaded to give user defined meaning to it
- These below operators can be overloaded
	- new delete
	- +-*/%^&|~
	- ! = < > += -= *= /= %=
	- ^= &= |= << >> >>= <<= == !=
	- <= >= && || ++ -- , ->* ->
	- () []
- Operator that are not overloaded are
	- scope operator - ::
	- sizeof
	- Period - .
	- ternary operator - ?:
	- typeid() operator

```C++
#include <iostream>
using namespace std;

class FLOAT {
    float no;
public:
    FLOAT() : no(0.0) {}  // Default constructor initializing no to 0.0
    FLOAT(float n) : no(n) {}  // Parameterized constructor

    void getdata() {
        cout << "Enter a float number : ";
        cin >> no;
    }

    void putdata() const {
        cout << "Result : " << no << endl;
    }

    FLOAT operator+(FLOAT f) {
        return FLOAT(no + f.no);
    }

    FLOAT operator*(FLOAT f) {
        return FLOAT(no * f.no);
    }

    FLOAT operator-(FLOAT f) {
        return FLOAT(no - f.no);
    }

    FLOAT operator/(FLOAT f) {
        if (f.no != 0) {
            return FLOAT(no / f.no);
        } else {
            cout << "\nDivision by zero error!";
            return FLOAT(0);  // Return zero if division by zero
        }
    }
};

int main() {
    FLOAT f1, f2, result;

    f1.getdata();
    f2.getdata();

    result = f1 + f2;
    cout << "\nAddition";
    result.putdata();

    result = f1 - f2;
    cout << "\nSubtraction";
    result.putdata();

    result = f1 * f2;
    cout << "\nMultiplication";
    result.putdata();

    result = f1 / f2;
    cout << "\nDivision";
    result.putdata();

    return 0;
}
```
## Exception Handling
### try – throw - catch block
- **try block** : This block contains the code that may generate an exception
- **throw statement** : This is used to signal the occurrence of an exception
- **catch block** : This block handles the exception. It's declared with an exception parameter

```C++
try {
    // Code that may throw an exception
    if (condition) {
        throw exception; // Throw an exception
    }
}
catch (type exception) {
    // Code to handle the exception
}
```

```C++
try {
    // Code that may throw an exception
}
catch (int e) {
    // Handle integer exceptions
}
catch (const char* e) {
    // Handle string exceptions
}
catch (...) {
    // Handle any type of exception - ellipsis
}
```

**Exception Handling - eg**
```C++
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
using namespace std;

// Custom exception class
class MyException : public exception {
public:
    const char* what(){
        return "My custom exception";
    }
};

int main() {
	int num1,num2;
    cout << "enter two numbers : ";
    cin >> num1 >> num2;
	
	string str;
	cout << "enter a string : ";
	cin >> str;

	int arr[5] = {1, 2, 3, 4, 5};
    int index = 10;
    
    bool customError = true;
    
    try {
        // Integer exception
        if (num2 == 0) {
            throw runtime_error("Division by zero");
        }
        cout << "Division result: " << num1 / num2 << endl;

        // String exception
        if (str.length() > 5) {
            throw string("String too long");
        }
        cout << "String: " << str << endl;

        // Array out-of-bounds exception
        if (index >= 5) {
            throw out_of_range("Array index out of bounds");
        }
        cout << "Array element: " << arr[index] << endl;

        // Custom exception
        if (customError) {
            throw MyException();
        }
    }
    catch (const runtime_error& e) {
        cout << "Runtime error : " << e.what() << endl;
    }
    catch (const string& e) {
        cout << "String exception : " << e << endl;
    }
    catch (const out_of_range& e) {
        cout << "Out_of_range exception : " << e.what() << endl;
    }
    catch (const MyException& e) {
        cout << "Custom exception: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "Caught an exception"<< endl;
    }

    return 0;
}
```

### Templates in C++
- Templates allow writing generic and reusable code
- They enable functions and classes to operate with generic types, reducing code duplication
- Fall under the category of "meta-programming" and auto code generation

#### Function Templates
- Function templates define a pattern for functions that can operate on different data types
- The compiler generates the specific function code based on the types used

```C++
template <typename T>
T maximum(T a, T b, T c) {
    T max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    return max;
}

int main() {
    int i1 = 1, i2 = 2, i3 = 3;
    double d1 = 1.1, d2 = 2.2, d3 = 3.3;

    cout << "Max int: " << maximum(i1, i2, i3) << endl;
    cout << "Max double: " << maximum(d1, d2, d3) << endl;

    return 0;
}
```

#### Class Templates
- Class templates define a blueprint for a class that can handle different data types, allowing for the creation of type-specific instances

```C++
template <typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;
    Pair(T1 f, T2 s) : first(f), second(s) {}
};

int main() {
    Pair<int, double> p1(1, 2.2);
    Pair<string, string> p2("Hello", "World");

    cout << "Pair 1: " << p1.first << ", " << p1.second << endl;
    cout << "Pair 2: " << p2.first << ", " << p2.second << endl;

    return 0;
}
```

#### Template with Multiple Generic Types
- This allows a function or a class to accept parameters of different types while still maintaining type safety and flexibility

```C++
#include <iostream>
using namespace std;

template<class T, class U, class V>
void tempfun(T a, U b, V c) {
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
}

int main() {
    int i = 10;
    float j = 3.14f;
    char k = 'T';
    tempfun(i, j, k);  // Calls tempfun with int, float, and char
    return 0;
}
```

#### Template Function Overloading
- Define several template functions with the same name but with different type parameters or different numbers of parameters

```C++
template <typename T> 
T add(T a, T b) {      // Template function to add two integers 
	return a + b; 
} 

template <typename T> 
T add(T a, T b, T c) { // Template function to add three integers 
	return a + b + c; 
} 

template <> 
string add<string>(string a, string b) { // Template function to add two strings 
	return a + " " + b; 
}
```

#### Explicitly Overloading a Generic Function
- If you overload a generic function, that overloaded function overrides (or hides) the generic function relative to that specific version
---

## Standard Template Library
- STL is a library in C++ that provides a set of common classes and interfaces for DSA
#### 1 Containers
- Data structures like arrays, lists, and queues
- Functions shared by all containers
	- Default constructor, copy constructor, destructor
	- = < <= > >= == !=
	- size queries (`size()`, `empty()`, etc.)

1. **Sequence Containers**
	- Store data in a linear sequence
	- eg : `vector`, `deque`, `list`
2. **Associative Containers** 
	- Store data in key-value pairs for quick access
	- eg : `set`, `map`, `multimap`
3. **Container Adapters** 
	- Provide different interface for existing sequence containers
	- eg : `stack`, `queue`, `priority_queue`

#### 2 Algorithms
- Functions for data manipulation like searching and sorting
#### 3 Iterators
- Objects that allow traversing elements in a container, similar to pointers
- `*` : Dereferences the iterator to access the element
- `++` : Moves the iterator to the next element
- `begin()` : Returns an iterator to the first element
- `end()` : Returns an iterator to the past-the-end element


#### Sequence Containers : Vector Container
- Have to include the following header file `<vector>`
- Data structure with contiguous memory locations

- `push_back(value)` : Adds an element to the end
- `size()` : Returns the number of elements
- `capacity()` : Returns the size of the allocated storage
- `insert(iterator, value)` : Inserts an element before the specified position
- `erase(iterator)` : Removes the element at the specified position
- `clear()` : Removes all elements
- `begin()`, `end()` : Returns iterators to the beginning and end of the vector

```C++
#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>v;
    
    v.push_back(100);
    v.push_back(1000);    
    v.push_back(10000);
    v.insert(v.begin(), 10);  
    v.insert(v.end(),100000);
    v.erase(v.begin() + 3);  
    
    for(int i : v){
        cout << i << endl;  // 10 100 1000 100000 
    }
    return 0;
}
```

#### Associative Container : Map
```C++
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> myMap;
    myMap[1] = "One";
    myMap[2] = "Two";
    myMap[3] = "Three";
    for(const auto &pair : myMap) {
        cout << pair.first << ": " << pair.second << endl;
    }

	/*for (const auto &[key, value] : myMap) { 
		cout << key << ": " << value << endl; 
	}*/
	
    // 1: One
    // 2: Two
    // 3: Three
    return 0;
}
```

#### Container Adapter : Stack
```C++
#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int>s;
    for(int i=0;i<5;i++){
        s.push(i);
    }
    
    while(!s.empty()){
        cout << " " << s.top(); // 4 3 2 1 0 
        s.pop();
    }
    return 0;
}
```

#### Algorithm
```C++
#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

int main(){
    vector<int>v(5);
    bool found;
    
    for(int i=0;i<5;i++){
        v[i]=i; // v.push_back(i)
    }
    
    found = binary_search(v.begin(), v.end(), 3);
    cout << found << endl;
    
    found = binary_search(v.begin(), v.end(), 9);
    cout << found << endl;
    
    sort(v.begin(), v.end());
    for(int i : v){
        cout << i << "->";
    }
    return 0;
}
```

#### Iterator
```C++
#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>v;
    
    v.push_back(100);
    v.push_back(1000);    
    v.push_back(10000);
    v.insert(v.begin(), 10);  
    v.insert(v.end(),100000);
    v.erase(v.begin() + 3);  
    
    for(auto i = v.begin(); i != v.end(); i++) {
        cout << *i << " ";  // 10 100 1000 100000 
    }
    return 0;
}
```
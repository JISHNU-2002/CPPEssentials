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
    obj.display();
    
    Rectangle *rect1,*rect2,*rect3;
    rect1 = &obj;
    rect1->display();
    
    rect2 = new Rectangle(5,6);
    rect2->display();
    
    rect3 = new Rectangle[2]{{7,8}, {9,10}};
    rect3[0].display();
    rect3[1].display();
    return 0;
}

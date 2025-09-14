#include <iostream>
using namespace std;
/*

class base
{
private:
    int z;
public:
int x;

protected:
int y;
};

class public Derived: public base //syntax for inheritance
{
    // x is public
    // y is protected
    // z is not accessible from public Derived
};
class protected Derived: protected base //syntax for inheritance
{
    // x is protected
    // y is protected
    // z is not accessible from protected Derived
};
class private Derived: private base //syntax for inheritance
{
    // x is private
    // y is private
    // z is not accessible private public Derived
};


*/
//Base class
class shape
{
protected:
int width;
int height;

public:
void setWidth (int w)
{
    width = w;
}
void setHeight (int h)
{
    height = h;
}
};
//Derived class
class Rectangle: public shape
{
public:
int getArea(){
    return (width * height);
}
};

int main(){
Rectangle Rect; //declare object rect
Rect.setWidth(5);
Rect.setHeight(7);
//print the area of the object
cout <<"Total Area: " <<Rect.getArea() <<endl;
return 0;
}

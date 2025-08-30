#include <iostream>
using namespace std;
//function overloading
/*
class king
{
    public: //access specifier
    void pro (int a, int b) // 2 parameters
    {
        cout << a * b <<endl;
    }
    void pre (int a, int b, int c, int d, int e)
    {
        cout << (a + b + c + d + e);
    }
};

int main(){
    king k;
    k.pro(10, 20);
    k.pre(12,23,35,43,17);
    return 0;
}
*/

//operator overloading


class overload {
    private:
    int n1;
    int n2;

    public: 
    int Overload(int num1, int num2)
    {
        int res;
        n1 = num1;
        n2 = num2;
        res = n1 - n2;
        cout << "Result: " <<res <<endl;

    }
    void operator_() //syntax for operator overloading
    {
        n1 = -n1;
        n2 = -n2;

    }
    void display()
    {
        cout << "n1 = " <<n1 <<" n2= " <<n2 <<endl;

    }
};

int main ()
{
    overload a;
    a.Overload(6, 8);
    a.operator_();
    a.display();
    return 0;
}


// Function Overiding
/*
class Parent 
{
public:
void print (){
cout <<"This is the function of the base class" <<endl;

}
};

class child : public Parent
{
    public:
    void print ()
    {
cout <<"This is the function of the child class" <<endl;
    }
};

int main (){
    child obj;
    obj.print();
    return 0;
}
*/

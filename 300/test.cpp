#include <iostream>
using namespace std;

class Triangle {
    private:
        int a;
        int b;
        int c;
    public:
        Triangle(int a, int b, int c) : a(a), b(b), c(c) {}
        int is_equilateral() {
            return (a == b && b == c);
        }
        int is_isoceles() {
            return (a == b || b == c || a == c);
        }
        int is_scalene() {
            return (a != b && b != c && a != c);
        }
};

int main() {
    Triangle t1(3, 4, 5);
    cout << "Is Equilateral: " << t1.is_equilateral() << endl;
    cout << "Is Isosceles: " << t1.is_isoceles() << endl;
    cout << "Is Scalene: " << t1.is_scalene() << endl;

    //Second Question
    int a[3] = {1,2 ,3};
    int b[3] = {4,5,6};
    int mul[3];
    int add[3];
    int sub[3];

    for (int i =0; i < 3; i++) {
        mul[i] = a[i] * b[i];
        add[i] = a[i] + b[i];
        sub[i] = a[i] - b[i];
    }

    //rinting out

    for (int i =0; i < 3; i++) {
        cout << a[i] << " * " << b[i] << " is: " << mul[i] << endl;
        cout << a[i] << " + " << b[i] << " is: " << add[i] << endl;
        cout << a[i] << " - " << b[i] << " is: " << sub[i] << endl;
    }
    return 0;

}

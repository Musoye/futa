#include <iostream>
#include <string>

using namespace std;


class Car {
    public:
      
    string name;

      void displayName() {
        cout << "The name of this car is " << name << endl << endl;
      };
};

class Toyota: public Car {
    public:
     string color;

     void displayName() {
        cout  << "The name of this Toyota is  " << name << " " << color  << endl;
     }
};

int main (void){

    Car car1;
    car1.name = "Musoye";
    car1.displayName();

    Toyota toy;
    toy.name = "Musoye2";
    toy.color ="blue";
    toy.displayName();

    return 0;
}
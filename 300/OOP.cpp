#include <iostream>
#include <string>
using namespace std;

//FOP
/*
void main()
{
char Company_name[50];
char model_name[50];
char fuel_type[50];
float mileage;
double price;
}
*/

//OOP
/*
class car
{
char Company_name[50];
char model_name[50];
char fuel_type[50];
float mileage;
double price;

Function displayDetails();

};

void main(){
    car object1;
    car object3;
    car object2;

}

*/

class cars
{
private:
//member variables or data members
string company_name;
string model_name;
string fuel_type;
float mileage;
double price;

public:
//member functions

void setData(string cname, string mname, string ftype, float m, double p){
company_name = cname;
model_name = mname;
fuel_type = ftype;
mileage = m;
price = p;
}

void displayData (){
    //not processing any data
    cout <<"Car Properties: " <<endl;
    cout <<"Car company name: " <<company_name <<endl;
    cout <<"Car model name: " <<model_name <<endl;
    cout <<"Car fuel type: " <<fuel_type <<endl;
    cout <<"Car mileage: " <<mileage <<endl;
    cout <<"Car price:$ " <<price <<endl;

}
};

int main (){

cars car1; //objects are nothing but variables of type class
car1.setData("Mercedes", "Cadillac", "Gasoline", 15, 150000 );
car1.displayData();

}

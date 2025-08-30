#include <iostream>
using namespace std;

int main(){

/*
//multiplication
    int x;
    cout << "What multiplication table do you want? : "<<endl;
    cin >> x;
    for (int i = 1; i <= 12; i++)
    {
    cout << x <<  " * " <<i<< " = " << (x * i) <<endl;
    }
    return 0;
*/

/*
//program to repeat an output until a specific character is entered
char mychar;
cout<< "Enter a character: "<<endl;
cin>> mychar;

while (mychar != 'x')
{
cout<< "I'm a programmer"<<endl <<"Enter a character again: ";
cin>> mychar;
}
return 0;
*/


//Program to perform an operation on 2 numbers based on a menu of 5 arithmetic operations
cout << "Arithmetic Operations program" <<endl;
cout << "1. Addition" <<endl << "2. Subtraction" <<endl<< "3. Multiplication" <<endl<< "4. Division" <<endl << "5. Modulos" <<endl;

cout <<"Enter the operation number to perform the appropriate operation"<<endl;

int option_no;
cin >> option_no;
int x,y;

switch (option_no)
{
case 1:
    cout << "Addition operation"<<endl <<"Enter two numbers" <<endl;
    cin >>x>>y;
    cout << "The addtion of "<<x<<" and "<<y<<" is: " << (x + y);
    break;

    case 2:
    cout << "Subtraction operation"<<endl <<"Enter two numbers" <<endl;
    cin >>x>>y;
    cout << "The Subtraction of "<<x<<" and "<<y<<" is: " << (x - y);
    break;

    case 3:
    cout << "Multiplication operation"<<endl <<"Enter two numbers" <<endl;
    cin >>x>>y;
    cout << "The Multiplication of "<<x<<" and "<<y<<" is: " << (x * y);
    break;

    case 4:
    cout << "Division operation"<<endl <<"Enter two numbers" <<endl;
    cin >>x>>y;
    cout << "The Division of "<<x<<" and "<<y<<" is: " << (x / y);
    break;

    case 5:
    cout << " Modulus operation"<<endl <<"Enter two numbers" <<endl;
    cin >>x>>y;
    cout << "The Modulus of "<<x<<" and "<<y<<" is: " << (x % y);
    break;

default:
    cout << "Invalid option, Pick between 1 to 5";
}


/*
//Program to check if a number is even or odd
int x;
cout << "Enter a number: " <<endl;
cin >> x;

if (x % 2 == 0)
{
    cout << "The number "<<x<<" is even"<<endl;
}
else{
    
    cout << "The number "<<x<<" is odd"<<endl;
}
return 0;
*/


}
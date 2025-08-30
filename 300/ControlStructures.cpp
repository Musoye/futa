#include <iostream>
using namespace std;

int main ()
{
/* 
    //WAP to check the largest of 3 numbers using nested if
int x,y,z;

    cout <<"Enter 3 numbers" <<endl;
    cin >>x >>y >>z;

    if (x > y)
    {
        //x is greater than y
        if (x > z){
//x is grater than z - Largest Number
cout <<x <<" is the greatest number" <<endl;

        }
        else {
            cout <<"Z is the greatest number";
        }
    }

    else if (y > x)
    {
        if (y > z)
        {
           cout <<y <<" is the greatest number" <<endl;

        }
        else {
            cout <<z <<" is the greatest number" <<endl;

        }
        
    }
    return 0;    
    */
/*
//Same program using compound expressions
   int x,y,z;

    cout <<"Enter 3 numbers" <<endl;
    cin >>x >>y >>z;

    if ((x > y) && (x > z))
    {
        cout <<x <<" is the largest number" <<endl;
    }
    else if ((y > x) && (y > z))
    {
        cout <<y <<" is the largest number" <<endl;
    }
    else {
        cout <<z <<" is the largest number" <<endl;
    }

*/
/*
//Factorial of a number
int x, y, factorial;
cout <<"Enter a number to calculate its factorial" <<endl;
cin >>y;
x = y;
factorial = x;
 if (y == 0)
 {
 cout <<"The factorial of " <<y <<" is 1" <<endl;
}
else
{

while (x > 1)
{
    x--;
    factorial = factorial * x;

}

cout <<"The factorial of " <<y <<" is " <<factorial <<endl;
 
}    

*/

/*
//BASICS of Array/ Array initialization/ Array traversing/ Taking inputs into Arrays/ printing array outputs

//datatype array_name[size]
int arr[3] = {1,2,3};
double arr1[5];
arr1[0] = 1.456;
arr1[1] = 3.432;

char mychar[2];
mychar[0] = 'a';

int temp_arr[5];
cout <<"Enter 5 numbers" <<endl;

for (int i = 0; i < 5; i++)
{
    cin >> temp_arr[i];
}
cout << "The values you entered are: " <<endl;
for (int i = 0; i < 5; i++)
{
    cout << temp_arr[i] <<endl;
}

*/

//Array Operations
int A[3], B[3], add[3], sub[3], mul[3];
cout <<"Enter 3 integers for array A: " <<endl;
for (int i = 0; i < 3; i++)
{
    cin >> A[i];
}

cout <<"Enter 3 integers for array B: " <<endl;
for (int i = 0; i < 3; i++)
{
    cin >> B[i];
}
cout <<endl <<"The Addition of A & B is: " <<endl;
for (int i = 0; i < 3; i++)
{
    add[i] = A[i] + B[i];
    cout << add[i] <<" ";
}
cout <<endl <<"The Subtraction of A & B is: " <<endl;
for (int i = 0; i < 3; i++)
{
    sub[i] = A[i] - B[i];
    cout << sub[i] <<" ";
}

cout <<endl <<"The Multiplication of A & B is: " <<endl;
for (int i = 0; i < 3; i++)
{
    mul[i] = A[i] * B[i];
    cout << mul[i] <<" ";
}


}
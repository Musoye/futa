#include <iostream>
using namespace std;

int main()
{
/*
//2-D array initialization, take input, display output, addition and subtraction
//datatype arrayname [rows][columns]
int arr[5][5];
int arr1[2][2];
int arr2[3][3] = {{1,1,1}, {2,2,2}, {3,3,3}};

for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        cout <<arr2[i][j] <<" ";
    }
    cout <<endl;
}

cout <<"Type in values for a 2x2 matrix" <<endl;
for (int i = 0; i < 2; i++)
{
    for (int j = 0; j < 2; j++)
    {
        cin >>arr1[i][j];
    }
    cout <<endl; 
    
}
cout <<endl <<"Values for the 2x2 matrix: " <<endl;
for (int i = 0; i < 2; i++)
{
    for (int j = 0; j < 2; j++)
    {
        cout <<arr1[i][j] <<" ";
    }
    cout <<endl;
}

*/ 

int A[2][2], B[2][2], addition[2][2], subtraction[2][2];
cout <<"Enter values for the 2-D array A: "<<endl;

for (int i = 0; i < 2; i++)
{
    for (int j = 0; j < 2; j++)
    {
        cin >>A[i][j];
    }
    cout<< endl;
}

cout <<"Enter values for the 2-D array B: "<<endl;

for (int i = 0; i < 2; i++)
{
    for (int j = 0; j < 2; j++)
    {
        cin >>B[i][j];
    }
    cout<< endl;
}

for (int i = 0; i < 2; i++)
{
    for (int j = 0; j < 2; j++)
    {
 addition[i][j] = A[i][j] + B[i][j];
    }
}

for (int i = 0; i < 2; i++)
{
    for (int j = 0; j < 2; j++)
    {
 subtraction[i][j] = A[i][j] - B[i][j];
    }
}

cout <<"The values for the Addition 2-D array is: "<<endl;

for (int i = 0; i < 2; i++)
{
    for (int j = 0; j < 2; j++)
    {
        cout <<addition[i][j]<< " ";
    }
    cout<< endl;
}
cout <<"The values for the Subtraction 2-D array is: "<<endl;

for (int i = 0; i < 2; i++)
{
    for (int j = 0; j < 2; j++)
    {
        cout <<subtraction[i][j]<< " ";
    }
    cout<< endl;
}
}
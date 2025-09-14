#include <iostream>
#include <string>
using namespace std;

int main(){
/*
cout<<"Multiplication of two 3x3 matrices: "<<endl; 
int arr1[3][3], arr2[3][3], arr3[3][3];

cout<<"Enter the values for matrix 1: "<<endl; 
for (int i = 0; i < 3; i++)
{
  for (int j = 0; j < 3; j++)
  {
 cout<<"arr1[" <<i+1 <<"][" <<j+1 <<"]: "; 
 cin>>arr1[i][j];
}
  
}

cout<<"Enter the values for matrix 2: "<<endl; 
for (int i = 0; i < 3; i++)
{
  for (int j = 0; j < 3; j++)
  {
 cout<<"arr2[" <<i+1 <<"][" <<j+1 <<"]: "; 
 cin>>arr2[i][j];
  }
  
}
 
for (int i = 0; i < 3; i++)
{
  for (int j = 0; j < 3; j++)
  
  {
arr3[i][j] = 0;
    for (int k = 0; k < 3; k++)
{

  arr3[i][j] += arr1[i][k] * arr2[k][j];
}

  }
  
}

cout<<"The results: "<<endl;

for (int i = 0; i < 3; i++)
{
  for (int j = 0; j < 3; j++)
  {
 
    cout<<arr3[i][j]<<endl;
  }
  
}

*/
int x = 10;
int *pointer = &x;

cout<<"value of x: "<<x <<endl;
cout<<"Address of x: "<<&x <<endl;
cout<<"Address of x: "<<pointer <<endl;
cout<<"value of x via the pointer: "<<*pointer <<endl;

}
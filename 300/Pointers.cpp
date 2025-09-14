#include <iostream>
using namespace std;

int main()
{

int var = 5;
//datatype *pointername 



//Dynamic memory allocation

int size;
int *ptr;
cout <<"Enter number of values you want to store (size of array): " <<endl;
cin >> size;

ptr = new int [size];
cout << "Enter the values to be stored in the array" <<endl;

for (int i = 0; i < size; i++)
{
    cin >> ptr[i];
}

cout << "Values in the array are: "<<endl;
for (int i = 0; i < size; i++)
{
    cout << ptr[i] <<endl;
}




}
#include <iostream>
using namespace std;

int main() {

    //single element
    int *ptr = new int(5);
    cout << *ptr << endl;

    //For multiple element
    int *arr = new int [5];

    for (int i = 0; i < 5; i++){
        cin >> arr[i];
    }

    //printing out
    for (int i =0; i < 5; i++){
        cout << arr[i] << " ";
    }

    //  Releasing the reserve space as this is dynamic memory allocation
    delete ptr;
    delete arr;
}



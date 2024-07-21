#include <iostream>

using namespace std;

int main() {
    int x, y;
    cout << "Enter the value of x and y: \n";
    cin >> x >> y;
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
    cout << " The exchange value of x and y: " << x << " ";
    cout << y << endl;
    return 0;
}
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int a, b;

    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;

    if (gcd(a, b) == 1)
        cout << "\nThe numbers are relatively prime.";
    else
        cout << "\nThe numbers are not relatively prime.";

    return 0;
}
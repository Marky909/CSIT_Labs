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
    int n, count = 0;

    cout << "Enter number: ";
    cin >> n;

    for (int i = 1; i < n; i++) {
        if (gcd(i, n) == 1)
            count++;
    }

    cout << "\nEuler Totient Function phi(" << n << ") = " << count;

    return 0;
}
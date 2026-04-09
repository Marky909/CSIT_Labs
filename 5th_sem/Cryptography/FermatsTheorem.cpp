#include <iostream>
using namespace std;

long long powerMod(long long a, long long b, long long mod) {
    long long result = 1;
    while (b > 0) {
        if (b % 2 == 1) result = (result * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return result;
}

int main() {
    long long p, a;

    cout << "Enter number to test: ";
    cin >> p;
    cout << "Enter base value: ";
    cin >> a;

    if (powerMod(a, p - 1, p) == 1)
        cout << "\n" << p << " may be prime.";
    else
        cout << "\n" << p << " is not prime.";

    return 0;
}
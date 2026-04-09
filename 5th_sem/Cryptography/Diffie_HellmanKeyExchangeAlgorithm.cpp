#include <iostream>
#include <cmath>
using namespace std;

long long modPower(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    long long p, g, a, b;

    cout << "Enter prime number (p): ";
    cin >> p;
    cout << "Enter primitive root (g): ";
    cin >> g;
    cout << "Enter private key of user A: ";
    cin >> a;
    cout << "Enter private key of user B: ";
    cin >> b;

    long long A = modPower(g, a, p);
    long long B = modPower(g, b, p);

    long long keyA = modPower(B, a, p);
    long long keyB = modPower(A, b, p);

    cout << "\nPublic key of A: " << A;
    cout << "\nPublic key of B: " << B;
    cout << "\nShared key for A: " << keyA;
    cout << "\nShared key for B: " << keyB;

    return 0;
}
#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long modPower(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

long long modInverse(long long e, long long phi) {
    for (long long d = 1; d < phi; d++) {
        if ((d * e) % phi == 1)
            return d;
    }
    return -1;
}

int main() {
    long long p, q, e, message;

    cout << "Enter first prime number: ";
    cin >> p;
    cout << "Enter second prime number: ";
    cin >> q;
    cout << "Enter public exponent e: ";
    cin >> e;
    cout << "Enter message as number: ";
    cin >> message;

    long long n = p * q;
    long long phi = (p - 1) * (q - 1);

    if (gcd(e, phi) != 1) {
        cout << "\ne must be relatively prime to phi(n).";
        return 0;
    }

    long long d = modInverse(e, phi);
    long long cipher = modPower(message, e, n);
    long long plain = modPower(cipher, d, n);

    cout << "\nPublic Key (e, n): (" << e << ", " << n << ")";
    cout << "\nPrivate Key (d, n): (" << d << ", " << n << ")";
    cout << "\nEncrypted Message: " << cipher;
    cout << "\nDecrypted Message: " << plain;

    return 0;
}
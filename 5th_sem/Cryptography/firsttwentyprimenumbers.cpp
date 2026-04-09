#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int count = 0, num = 2;

    cout << "First 20 Prime Numbers are:\n";
    while (count < 20) {
        if (isPrime(num)) {
            cout << num << " ";
            count++;
        }
        num++;
    }

    return 0;
}
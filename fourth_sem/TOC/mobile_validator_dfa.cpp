// A DFA to validate a string against a specific mobile number pattern (9844...).
#include <iostream>
using namespace std;
int main() {
    string num = "9844451355";
    if(num.length() != 10) {
        cout << "Invalid: Must be 10 digits";
        return 0;
    }
    int state = 0;
    const int final = 4, dead = 5;
    for(char d : num) {
        if (state == 0 && d == '9') state = 1;
        else if (state == 1 && d == '8') state = 2;
        else if (state == 2 && d == '4') state = 3;
        else if (state == 3 && d == '1') state = 4;
        else if (state == 4 && d >= '0' && d <= '9') state = 4;
        else state = dead;
    }
    cout << (state == final ? "Valid" : "Invalid") << " mobile number";
    return 0;
}
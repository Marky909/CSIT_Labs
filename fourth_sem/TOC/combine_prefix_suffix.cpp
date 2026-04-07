//Creating a new string by combining a prefix from one string and a suffix from another.
#include <iostream>
using namespace std;
int main() {
    string a = "apple", b = "cider";
    int l = 3;
    string result = a.substr(0, l) + b.substr(b.length() - l);
    cout << result; // Output: "appder"
    return 0;
}
// Generating all suffixes of a given string.
#include <iostream>
using namespace std;
int main() {
    string s = "computer";
    for (int i=s.length()-1; i>=0; i--)
        cout << s.substr(i) << endl;
    return 0;
}
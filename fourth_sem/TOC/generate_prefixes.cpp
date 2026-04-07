//Generating all prefixes of a given string.
#include <iostream>
using namespace std;
int main() {
    string s = "computer";
    for (int i=1; i<=s.length(); i++)
        cout << s.substr(0, i) << endl;
    return 0;
}
//Generating all possible substrings of a given string.
#include <iostream>
using namespace std;
int main() {
    string s = "apple";
    int n = s.length();
    for (int len=1; len<=n; len++)
        for (int start=0; start<=n-len; start++)
            cout << s.substr(start, len) << endl;
    return 0;
}
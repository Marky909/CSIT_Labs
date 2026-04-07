//Simulating a DFA that processes an input string and checks for acceptance.
#include <iostream>
using namespace std;

int main() {
    int tt[3][2] = {{2, 1}, {2, 1}, {2, 1}};
    int state = 0;
    const int accept = 2;
    string w = "011111111";

    cout << "Initial State: S" << state << "\n\n";
    cout << "Current State\tSymbol\tNext State\n";
    cout << "================================\n";

    for(char c : w) {
        int input = c - '0';
        int prev = state;
        state = tt[state][input];
        cout << "S" << prev << "\t\t" << input << "\tS" << state << endl;
    }

    cout << "\nFinal State: S" << state << endl;
    cout << "String '" << w << "' is " << (state == accept ? "Accepted" : "Rejected");
    return 0;
}
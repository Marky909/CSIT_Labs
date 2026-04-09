#include <iostream>
#include <vector>
#include <string>
using namespace std;

string encryptRailFence(string text, int key) {
    vector<string> rail(key);
    int row = 0, dir = 1;

    for (char ch : text) {
        rail[row] += ch;
        row += dir;
        if (row == 0 || row == key - 1) dir = -dir;
    }

    string result = "";
    for (string r : rail) result += r;
    return result;
}

int main() {
    string text;
    int key;

    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter key: ";
    cin >> key;

    string encrypted = encryptRailFence(text, key);

    cout << "\nEncrypted Text: " << encrypted;

    return 0;
}
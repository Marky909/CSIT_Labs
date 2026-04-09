#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string normal = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string keyMap = "QWERTYUIOPASDFGHJKLZXCVBNM";

string encryptMono(string text) {
    string result = "";
    for (char ch : text) {
        if (isalpha(ch)) {
            ch = toupper(ch);
            result += keyMap[ch - 'A'];
        } else {
            result += ch;
        }
    }
    return result;
}

string decryptMono(string text) {
    string result = "";
    for (char ch : text) {
        if (isalpha(ch)) {
            int pos = keyMap.find(ch);
            result += normal[pos];
        } else {
            result += ch;
        }
    }
    return result;
}

int main() {
    string text;

    cout << "Enter text: ";
    getline(cin, text);

    string encrypted = encryptMono(text);
    string decrypted = decryptMono(encrypted);

    cout << "\nEncrypted Text: " << encrypted;
    cout << "\nDecrypted Text: " << decrypted;

    return 0;
}
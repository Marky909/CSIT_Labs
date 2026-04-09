#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string encryptCaesar(string text, int key) {
    string result = "";
    for (char ch : text) {
        if (isalpha(ch)) {
            ch = toupper(ch);
            result += char((ch - 'A' + key) % 26 + 'A');
        } else {
            result += ch;
        }
    }
    return result;
}

string decryptCaesar(string text, int key) {
    string result = "";
    for (char ch : text) {
        if (isalpha(ch)) {
            result += char((ch - 'A' - key + 26) % 26 + 'A');
        } else {
            result += ch;
        }
    }
    return result;
}

int main() {
    string text;
    string keyStr;
    int key;

    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter key: ";
    getline(cin, keyStr);
    key = stoi(keyStr);  // Convert string to int

    string encrypted = encryptCaesar(text, key);
    string decrypted = decryptCaesar(encrypted, key);

    cout << "\nEncrypted Text: " << encrypted;
    cout << "\nDecrypted Text: " << decrypted;

    return 0;
}
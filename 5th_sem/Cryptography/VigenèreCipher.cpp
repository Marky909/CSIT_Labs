#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string generateKey(string text, string key) {
    string newKey = "";
    int j = 0;
    for (int i = 0; i < text.length(); i++) {
        if (isalpha(text[i])) {
            newKey += toupper(key[j % key.length()]);
            j++;
        } else {
            newKey += text[i];
        }
    }
    return newKey;
}

string encryptVigenere(string text, string key) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        if (isalpha(text[i])) {
            char p = toupper(text[i]);
            char k = key[i];
            result += char((p - 'A' + k - 'A') % 26 + 'A');
        } else {
            result += text[i];
        }
    }
    return result;
}

string decryptVigenere(string text, string key) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        if (isalpha(text[i])) {
            result += char((text[i] - 'A' - (key[i] - 'A') + 26) % 26 + 'A');
        } else {
            result += text[i];
        }
    }
    return result;
}

int main() {
    string text, key;

    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter key: ";
    getline(cin, key);

    string fullKey = generateKey(text, key);
    string encrypted = encryptVigenere(text, fullKey);
    string decrypted = decryptVigenere(encrypted, fullKey);

    cout << "\nEncrypted Text: " << encrypted;
    cout << "\nDecrypted Text: " << decrypted;

    return 0;
}
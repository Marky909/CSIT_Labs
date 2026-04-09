#include <iostream>
#include <string>
using namespace std;

string vernamCipher(string text, string key) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        result += char(text[i] ^ key[i]);
    }
    return result;
}

int main() {
    string text, key;

    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter key (same length): ";
    getline(cin, key);

    if (text.length() != key.length()) {
        cout << "Key length must be equal to text length.";
        return 0;
    }

    string encrypted = vernamCipher(text, key);
    string decrypted = vernamCipher(encrypted, key);

    cout << "\nEncrypted Text (ASCII values): ";
    for (char ch : encrypted) cout << int((unsigned char)ch) << " ";

    cout << "\nDecrypted Text: " << decrypted;

    return 0;
}
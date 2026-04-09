#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string text;
    int key[2][2];

    cout << "Enter text (even length): ";
    getline(cin, text);

    cout << "Enter 2x2 key matrix:\n";
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cin >> key[i][j];

    for (char &ch : text) ch = toupper(ch);
    if (text.length() % 2 != 0) text += 'X';

    string result = "";

    for (int i = 0; i < text.length(); i += 2) {
        int p1 = text[i] - 'A';
        int p2 = text[i + 1] - 'A';

        int c1 = (key[0][0] * p1 + key[0][1] * p2) % 26;
        int c2 = (key[1][0] * p1 + key[1][1] * p2) % 26;

        result += char(c1 + 'A');
        result += char(c2 + 'A');
    }

    cout << "\nEncrypted Text: " << result;

    return 0;
}
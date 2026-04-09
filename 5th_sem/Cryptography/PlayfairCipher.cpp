#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

char matrix5[5][5];

string prepareText(string text) {
    string result = "";
    for (char ch : text) {
        if (isalpha(ch)) {
            ch = toupper(ch);
            if (ch == 'J') ch = 'I';
            result += ch;
        }
    }
    for (int i = 0; i < result.length(); i += 2) {
        if (i + 1 < result.length() && result[i] == result[i + 1]) {
            result.insert(i + 1, "X");
        }
    }
    if (result.length() % 2 != 0) result += 'X';
    return result;
}

void generateMatrix(string key) {
    string temp = "";
    for (char ch : key) {
        if (isalpha(ch)) {
            ch = toupper(ch);
            if (ch == 'J') ch = 'I';
            if (temp.find(ch) == string::npos) temp += ch;
        }
    }
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (ch == 'J') continue;
        if (temp.find(ch) == string::npos) temp += ch;
    }
    int k = 0;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            matrix5[i][j] = temp[k++];
}

void findPos(char ch, int &row, int &col) {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (matrix5[i][j] == ch) {
                row = i; col = j; return;
            }
}

string encryptPlayfair(string text) {
    string result = "";
    for (int i = 0; i < text.length(); i += 2) {
        int r1, c1, r2, c2;
        findPos(text[i], r1, c1);
        findPos(text[i + 1], r2, c2);

        if (r1 == r2) {
            result += matrix5[r1][(c1 + 1) % 5];
            result += matrix5[r2][(c2 + 1) % 5];
        } else if (c1 == c2) {
            result += matrix5[(r1 + 1) % 5][c1];
            result += matrix5[(r2 + 1) % 5][c2];
        } else {
            result += matrix5[r1][c2];
            result += matrix5[r2][c1];
        }
    }
    return result;
}

int main() {
    string key, text;

    cout << "Enter key: ";
    getline(cin, key);
    cout << "Enter text: ";
    getline(cin, text);

    generateMatrix(key);
    string prepared = prepareText(text);
    string encrypted = encryptPlayfair(prepared);

    cout << "\nPrepared Text: " << prepared;
    cout << "\nEncrypted Text: " << encrypted;

    return 0;
}
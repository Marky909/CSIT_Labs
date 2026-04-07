// DFA implementation for the regular expression (a+aa*b)* (compact version).
#include<stdio.h>
#include<string.h>
int main() {
    char s[100];
    int table[2][2] = {{1, -1}, {1, 0}}, state=0, i=0;
    printf("Enter a string (a & b only): ");
    scanf("%s", s);
    while(s[i]) {
        if(s[i]=='a') state = table[state][0];
        else if(s[i]=='b') state = table[state][1];
        else { printf("Invalid input\n"); return 0; }
        if(state == -1) break;
        i++;
    }
    printf(state == 0 ? "Accepted\n" : "Rejected\n");
    return 0;
}
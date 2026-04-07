// A DFA that recognizes strings based on specific patterns (a, a*b+, abb).
#include <stdio.h>
#include <string.h>
int main() {
    char s[20];
    int state = 0;
    printf("Enter a string: ");
    scanf("%s", s);

    for(int i=0; s[i]; i++) {
        char c = s[i];
        if (state == 0) {
            if (c == 'a') state = 1;
            else if (c == 'b') state = 2;
            else state = 6;
        } else if (state == 1) {
            if (c == 'a') state = 3;
            else if (c == 'b') state = 4;
            else state = 6;
        } else if (state == 2) {
            if (c == 'b') state = 2;
            else state = 6;
        } else if (state == 3) {
            if (c == 'a') state = 3;
            else if (c == 'b') state = 2;
            else state = 6;
        } else if (state == 4) {
            if (c == 'b') state = 5;
            else state = 6;
        } else if (state == 5) {
            if (c == 'b') state = 2;
            else state = 6;
        } else break;
    }

    if (state == 1) printf("Accepted under rule 'a'\n");
    else if (state == 2 || state == 4) printf("Accepted under rule 'a*b+'\n");
    else if (state == 5) printf("Accepted under rule 'abb'\n");
    else printf("Not accepted\n");
    return 0;
}
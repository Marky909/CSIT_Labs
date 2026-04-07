//DFA implementation for the regular expression
#include <stdio.h>
#include <string.h>
int main() {
    char s[100];
    printf("Enter a string (a & b only): ");
    scanf("%s", s);
    int state_a = 0, state_b = 0;

    for(int i=0; s[i]; i++) {
        if(s[i] == 'a') {
            state_a = 1;
            state_b = 0;
        } else if(s[i] == 'b') {
            if(state_b || !state_a) {
                printf("Rejected\n");
                return 0;
            }
            state_b = 1;
            state_a = 0;
        } else {
            printf("Invalid input '%c'\n", s[i]);
            return 0;
        }
    }
    printf("Accepted\n");
    return 0;
}
#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int stack = 0;  // just a counter

    printf("Enter string: ");
    scanf("%s", s);

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '0') stack++;
        else if (s[i] == '1') stack--;
        else {
            printf("Invalid symbol\n");
            return 0;
        }
    }

    if (stack == 0)
        printf("Accepted: equal number of 0s and 1s\n");
    else
        printf("Rejected: not equal\n");

    return 0;
}

#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int stack = 0;
    int stage = 0; // 0 = reading 0s, 1 = reading 1s

    printf("Enter string: ");
    scanf("%s", s);

    for (int i = 0; i < strlen(s); i++) {
        if (stage == 0 && s[i] == '0') {
            stack++;  // push
        }
        else if (s[i] == '1') {
            stage = 1;
            stack--;  // pop
            if (stack < 0) {
                printf("Rejected\n");
                return 0;
            }
        }
        else {
            printf("Rejected\n");
            return 0;
        }
    }

    if (stack == 0 && stage == 1)
        printf("Accepted: 0^n1^n\n");
    else
        printf("Rejected\n");

    return 0;
}

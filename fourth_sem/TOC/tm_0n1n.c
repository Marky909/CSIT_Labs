#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int n, i, j, ok;

    printf("Enter string: ");
    scanf("%s", s);
    n = strlen(s);

    // Check form: all 0s first, then all 1s
    int seen1 = 0;
    for (i = 0; i < n; i++) {
        if (s[i] == '0' && seen1)
            { printf("Rejected\n"); return 0; }
        if (s[i] == '1') seen1 = 1;
        if (s[i] != '0' && s[i] != '1')
            { printf("Rejected\n"); return 0; }
    }

    // TM-style cross-out simulation
    for (i = 0; i < n; i++) {
        if (s[i] == '0') {
            ok = 0;
            for (j = i + 1; j < n; j++) {
                if (s[j] == '1') {
                    s[i] = 'X';  
                    s[j] = 'X';  // cross out
                    ok = 1;
                    break;
                }
            }
            if (!ok) {
                printf("Rejected\n");
                return 0;
            }
        }
    }

    // If all characters crossed → accepted
    for (i = 0; i < n; i++) {
        if (s[i] != 'X') {
            printf("Rejected\n");
            return 0;
        }
    }

    printf("Accepted: TM 0^n1^n\n");
    return 0;
}

#include <stdio.h>
#include <stdbool.h>

void secondChance(int pages[], int n, int f) {
    int frame[f], ptr = 0, faults = 0;
    bool ref[f];
    for (int i = 0; i < f; i++) frame[i] = -1, ref[i] = false;

    for (int i = 0; i < n; i++) {
        int p = pages[i], found = 0;
        for (int j = 0; j < f; j++) {
            if (frame[j] == p) {
                ref[j] = true;
                found = 1;
                break;
            }
        }
        if (!found) {
            while (ref[ptr]) ref[ptr] = false, ptr = (ptr + 1) % f;
            frame[ptr] = p;
            ref[ptr] = true;
            ptr = (ptr + 1) % f;
            faults++;
        }

        printf("Page %2d: ", p);
        for (int j = 0; j < f; j++) frame[j] == -1 ? printf(" - ") : printf("%2d ", frame[j]);
        printf("\n");
    }
    printf("\nTotal Page Faults: %d\n", faults);
}

int main() {
    int pages[] = {1,2,3,4,1,2,5,1,2,3,4,5};
    int n = sizeof(pages) / sizeof(pages[0]);
    int f = 3;

    printf("Second Chance Page Replacement Algorithm\n");
    printf("Page Requests: ");
    for (int i = 0; i < n; i++) printf("%d ", pages[i]);
    printf("\n\n");

    secondChance(pages, n, f);
    return 0;
}

#include <stdio.h>

int main() {
    int pages[50], frames[10], used[10], n, f, i, j, k, pos, fault = 0, time = 0;

    printf("No. of Pages: ");
    scanf("%d", &n);
    printf("Enter Page References:\n");
    for(i = 0; i < n; i++) scanf("%d", &pages[i]);

    printf("No. of Frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++) frames[i] = -1;

    printf("\nPage\tFrames\n");
    for(i = 0; i < n; i++) {
        int found = 0;
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                used[j] = ++time;
                break;
            }
        }

        if(!found) {
            int min = used[0], index = 0;
            for(j = 0; j < f; j++) {
                if(frames[j] == -1) {
                    index = j;
                    break;
                } else if(used[j] < min) {
                    min = used[j];
                    index = j;
                }
            }
            frames[index] = pages[i];
            used[index] = ++time;
            fault++;
        }

        printf("%d\t", pages[i]);
        for(k = 0; k < f; k++) {
            if(frames[k] == -1) printf("- ");
            else printf("%d ", frames[k]);
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", fault);
    return 0;
}

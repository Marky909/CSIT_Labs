// Simulating an NFA whose definition is provided by the user via console input.
#include <stdio.h>
#include <string.h>
#define MAX 100

int main() {
    int states, symbols, symdir[20], final, mark[20] = {0}, mat[20][20][20];
    char str[MAX];
    for(int i=0; i<20; i++) for(int j=0; j<20; j++) for(int k=0; k<20; k++) mat[i][j][k] = -1;

    printf("Enter number of states and symbols: ");
    scanf("%d %d", &states, &symbols);
    printf("Enter symbols (e.g., 0 1): ");
    for(int i=0; i<symbols; i++) scanf("%d", &symdir[i]);
    printf("Enter number of final states: ");
    scanf("%d", &final);
    printf("Enter final state numbers: ");
    for(int i=0; i<final; i++) { int t; scanf("%d", &t); mark[t] = 1; }

    for(int i=0; i<states; i++) {
        for(int j=0; j<symbols; j++) {
            printf("Number of transitions for δ(Q%d, %d): ", i, symdir[j]);
            int n; scanf("%d", &n);
            for(int k=0; k<n; k++) {
                printf("Transition %d: ", k+1);
                scanf("%d", &mat[i][symdir[j]][k]);
            }
        }
    }

    printf("Enter string to test: ");
    scanf("%s", str);
    int curr[MAX] = {0}, ncurr = 1;

    for(int i=0; str[i]; i++) {
        int input = str[i] - '0';
        int next[MAX], nnext = 0;
        for(int s=0; s<ncurr; s++) {
            for(int t=0; mat[curr[s]][input][t] != -1; t++) {
                next[nnext++] = mat[curr[s]][input][t];
            }
        }
        for(int s=0; s<nnext; s++) curr[s] = next[s];
        ncurr = nnext;
    }

    int accepted = 0;
    for(int i=0; i<ncurr; i++) if(mark[curr[i]]) accepted = 1;
    printf(accepted ? "Accepted\n" : "Rejected\n");
    return 0;
}
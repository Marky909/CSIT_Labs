#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Fa[10][10][10], states[2][10];
char str[100];

int nfa(char *str, int state) {
    if (!*str) {
        // check if current state is accepting
        for (int i = 0; states[1][i] != -1; i++)
            if (state == states[1][i])
                return 1;
        return 0;
    }
    int sym = *str - 'a';
    for (int i = 0; Fa[state][sym][i] != -1; i++)
        if (nfa(str + 1, Fa[state][sym][i]))
            return 1;
    return 0;
}

int main() {
    FILE *fp = fopen("Nfa_ip.txt", "r");
    if (!fp) {
        printf("Error opening file!\n");
        return 1;
    }

    int nStates, nSymbols;
    fscanf(fp, "%d %d", &nStates, &nSymbols);

    // initialize
    for (int i=0;i<2;i++) for(int j=0;j<10;j++) states[i][j] = -1;
    for (int i=0;i<10;i++) for(int j=0;j<10;j++) for(int k=0;k<10;k++) Fa[i][j][k] = -1;

    // start state
    fscanf(fp, "%d", &states[0][0]);

    // accepting states
    int acc, idx=0;
    while (fscanf(fp, "%d", &acc) && acc != -1)
        states[1][idx++] = acc;

    // transitions
    int from, to;
    char sym;
    while (fscanf(fp, "%d %c", &from, &sym) != EOF) {
        idx=0;
        while (fscanf(fp, "%d", &to) && to != -1) {
            Fa[from][sym-'a'][idx++] = to;
        }
    }
    fclose(fp);

    printf("Enter the string: ");
    scanf("%s", str);

    if (nfa(str, states[0][0]))
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}

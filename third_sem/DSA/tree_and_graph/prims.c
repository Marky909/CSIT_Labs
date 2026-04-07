#include <stdio.h>
#include <limits.h>

#define MAX 30

int Graph[MAX][MAX], n;

int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void printMST(int parent[]) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++)
        printf("%d - %d \t%d\n", parent[i], i, Graph[i][parent[i]]);
}

void primMST() {
    int parent[n], key[n], mstSet[n];
    
    for (int i = 0; i < n; i++)
        key[i] = INT_MAX, mstSet[i] = 0;
    
    key[0] = 0;
    parent[0] = -1;
    
    for (int count = 0; count < n-1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;
        
        for (int v = 0; v < n; v++)
            if (Graph[u][v] && !mstSet[v] && Graph[u][v] < key[v])
                parent[v] = u, key[v] = Graph[u][v];
    }
    
    printMST(parent);
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &Graph[i][j]);
    
    primMST();
    return 0;
}
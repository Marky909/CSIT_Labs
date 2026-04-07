#include <stdio.h>
#include <limits.h>

#define MAX 30

int Graph[MAX][MAX], n;

int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void printSolution(int dist[]) {
    printf("Vertex \tDistance from Source\n");
    for (int i = 0; i < n; i++)
        printf("%d \t%d\n", i, dist[i]);
}

void dijkstra(int src) {
    int dist[n], sptSet[n];
    
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX, sptSet[i] = 0;
    
    dist[src] = 0;
    
    for (int count = 0; count < n-1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;
        
        for (int v = 0; v < n; v++)
            if (!sptSet[v] && Graph[u][v] && dist[u] != INT_MAX
                && dist[u] + Graph[u][v] < dist[v])
                dist[v] = dist[u] + Graph[u][v];
    }
    
    printSolution(dist);
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &Graph[i][j]);
    
    dijkstra(0);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n;

void createGraph() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
}

void BFS(int start) {
    int queue[MAX], front = -1, rear = -1;
    printf("BFS: ");
    
    visited[start] = 1;
    queue[++rear] = start;
    
    while (front != rear) {
        start = queue[++front];
        printf("%d ", start);
        
        for (int i = 0; i < n; i++) {
            if (adj[start][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

void DFS(int start) {
    printf("%d ", start);
    visited[start] = 1;
    
    for (int i = 0; i < n; i++) {
        if (adj[start][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

void resetVisited() {
    for (int i = 0; i < n; i++) visited[i] = 0;
}

int main() {
    createGraph();
    resetVisited();
    printf("BFS Traversal: "); BFS(0); printf("\n");
    resetVisited();
    printf("DFS Traversal: "); DFS(0); printf("\n");
    return 0;
}
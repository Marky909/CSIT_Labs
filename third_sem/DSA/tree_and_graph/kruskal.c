#include <stdio.h>
#include <stdlib.h>

#define MAX 30

typedef struct edge {
    int u, v, w;
} Edge;

typedef struct edgelist {
    Edge data[MAX];
    int n;
} EdgeList;

EdgeList elist;
EdgeList spanlist;

int Graph[MAX][MAX], n;
int parent[MAX];

int find(int i) {
    while (parent[i] != i) i = parent[i];
    return i;
}

void union1(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void kruskal() {
    int i, j, a, b, u, v;
    elist.n = 0;
    
    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
            if (Graph[i][j] != 0) {
                elist.data[elist.n].u = i;
                elist.data[elist.n].v = j;
                elist.data[elist.n].w = Graph[i][j];
                elist.n++;
            }
    
    // Sort edges by weight
    for (i = 1; i < elist.n; i++)
        for (j = 0; j < elist.n-1; j++)
            if (elist.data[j].w > elist.data[j+1].w) {
                Edge temp = elist.data[j];
                elist.data[j] = elist.data[j+1];
                elist.data[j+1] = temp;
            }
    
    for (i = 0; i < n; i++) parent[i] = i;
    
    spanlist.n = 0;
    
    for (i = 0; i < elist.n; i++) {
        u = elist.data[i].u;
        v = elist.data[i].v;
        a = find(u);
        b = find(v);
        
        if (a != b) {
            spanlist.data[spanlist.n] = elist.data[i];
            spanlist.n++;
            union1(a, b);
        }
    }
}

void print() {
    int i, cost = 0;
    for (i = 0; i < spanlist.n; i++) {
        printf("%d - %d : %d\n", spanlist.data[i].u, spanlist.data[i].v, spanlist.data[i].w);
        cost += spanlist.data[i].w;
    }
    printf("Total cost: %d\n", cost);
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &Graph[i][j]);
    
    kruskal();
    print();
    return 0;
}
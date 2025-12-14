#include <stdio.h>
#define MAX 20
int adj[MAX][MAX];
int visited[MAX] = {0};
void dfs(int vertex, int n) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (int i = 0; i < n; i++) {
        if (adj[vertex][i] != 0 && !visited[i]) {
            dfs(i, n);
        }
    }
}
int main() {
    int n;
    int start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    dfs(start, n);
    printf("\n");
    return 0;
}


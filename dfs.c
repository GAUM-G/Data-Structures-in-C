#include <stdio.h>
#define MAX 10

int adj[MAX][MAX];
int visited[MAX];

void DFS(int v, int n) {
    int stack[MAX], top = -1;
    stack[++top] = v;
    visited[v] = 1;
    printf("DFS Traversal: ");
    while (top != -1) {
        v = stack[top--];
        printf("%d ", v);
        for (int i = 0; i < n; i++) {
            if (adj[v][i] && !visited[i]) {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, v;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &v);
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    DFS(v, n);
    return 0;
}

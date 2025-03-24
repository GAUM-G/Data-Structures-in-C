#include <stdio.h>
#define MAX 10

int adj[MAX][MAX];
int visited[MAX];

void BFS(int v, int n) {
    int queue[MAX], front = 0, rear = 0;
    queue[rear++] = v;
    visited[v] = 1;
    printf("BFS Traversal: ");
    while (front != rear) {
        v = queue[front++];
        printf("%d ", v);
        for (int i = 0; i < n; i++) {
            if (adj[v][i] && !visited[i]) {
                queue[rear++] = i;
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

    BFS(v, n);
    return 0;
}

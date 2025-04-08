#include <stdio.h>

#define INF 999

void dijkstra(int n, int cost[10][10], int src) {
    int dis[10], vis[10] = {0};
    int i, j, u = src, min;

    // Initialize distance array
    for (i = 1; i <= n; i++) {
        dis[i] = cost[src][i];
        vis[i] = 0;
    }
    dis[src] = 0;
    vis[src] = 1;

    for (i = 1; i < n; i++) {
        min = INF;

        // Find the vertex with minimum distance
        for (j = 1; j <= n; j++) {
            if (!vis[j] && dis[j] < min) {
                min = dis[j];
                u = j;
            }
        }

        vis[u] = 1;

        // Update distances
        for (j = 1; j <= n; j++) {
            if (!vis[j] && dis[u] + cost[u][j] < dis[j]) {
                dis[j] = dis[u] + cost[u][j];
            }
        }
    }

    printf("Shortest paths from vertex %d:\n", src);
    for (i = 1; i <= n; i++) {
        if (dis[i] == INF)
            printf("%d -> %d = Unreachable\n", src, i);
        else
            printf("%d -> %d = %d\n", src, i, dis[i]);
    }
}

int main() {
    int n, src, cost[10][10];
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (999 for no direct edge):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &src);

    dijkstra(n, cost, src);

    return 0;
}

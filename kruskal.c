#include <stdio.h>
#include <stdlib.h>

int find(int v, int parent[10]) {
    while (parent[v] != v) {
        v = parent[v];
    }
    return v;
}

void union1(int i, int j, int parent[10]) {
    if (i < j)
        parent[j] = i;
    else
        parent[i] = j;
}

void kruskal(int n, int a[10][10]) {
    int count = 0, k = 0, sum = 0;
    int t[10][3], parent[10];

    for (int i = 0; i < n; i++)
        parent[i] = i;

    while (count < n - 1) {
        int min = 999, u = -1, v = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] < min && a[i][j] != 0) {
                    min = a[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        if (u == -1 || v == -1) {
            printf("Spanning tree does not exist\n");
            return;
        }

        int i = find(u, parent);
        int j = find(v, parent);

        if (i != j) {
            union1(i, j, parent);
            t[k][0] = u;
            t[k][1] = v;
            t[k][2] = min;
            k++;
            count++;
            sum += min;
        }
        a[u][v] = a[v][u] = 999;
    }

    printf("\nSpanning Tree Edges:\n");
    printf("Edge \tWeight\n");
    for (int i = 0; i < n - 1; i++) {
        printf("%d - %d \t%d\n", t[i][0], t[i][1], t[i][2]);
    }
    printf("Total Cost of Spanning Tree = %d\n", sum);
}

int main() {
    int n, m, u, v, weight;
    int a[10][10];

    printf("Enter the number of nodes: ");
    scanf("%d", &n);


    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = (i == j) ? 0 : 999;

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter the edges (u v weight):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &weight);
        a[u][v] = a[v][u] = weight;
    }

    kruskal(n, a);
    return 0;
}

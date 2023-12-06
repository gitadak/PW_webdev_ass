#include <stdio.h>

#define MAX_NODES 100

void addEdge(int u, int v, int adjMatrix[MAX_NODES][MAX_NODES])
{
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1; 
}

void displayMatrix(int nodes, int adjMatrix[MAX_NODES][MAX_NODES])
{
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
            printf("%d ", adjMatrix[i][j]);
        printf("\n");
    }
}

int main()
{
    int i, nodes, edges, u, v;
    static int adjMatrix[MAX_NODES][MAX_NODES];

    printf("Enter number of nodes in the graph: ");
    scanf("%d", &nodes);

    printf("Enter number of edges in the graph: ");
    scanf("%d", &edges);

    printf("Enter the edges (format: from_node to_node):\n");
    for (i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        addEdge(u-1, v-1, adjMatrix);
    }

    displayMatrix(nodes, adjMatrix);

    return 0;
}
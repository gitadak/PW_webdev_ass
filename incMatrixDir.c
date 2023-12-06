#include <stdio.h>

#define MAX_NODES 100
#define MAX_EDGES 100

void addEdge(int edge, int u, int v,int incidenceMatrix[MAX_NODES][MAX_EDGES])
{
    incidenceMatrix[u][edge] = 1;
    incidenceMatrix[v][edge] = -1;
}

void displayMatrix(int nodes, int edges,int incidenceMatrix[MAX_NODES][MAX_EDGES])
{
    printf("Incidence Matrix:\n");
    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < edges; j++)
            printf("%2d ", incidenceMatrix[i][j]);
        printf("\n");
    }
}

int main()
{
    int i, nodes, edges, u, v;
    static int incidenceMatrix[MAX_NODES][MAX_EDGES];

    printf("Enter number of nodes in the graph: ");
    scanf("%d", &nodes);

    printf("Enter number of edges in the graph: ");
    scanf("%d", &edges);

    printf("Enter the edges (format: from_node to_node):\n");
    for (i = 0; i < edges; i++)
    {
        printf("e%d = ",i+1);
        scanf("%d %d", &u, &v);
        addEdge(i, u-1, v-1, incidenceMatrix);
    }

    displayMatrix(nodes, edges, incidenceMatrix);

    return 0;
}

#include <stdio.h>

#define MAX_NODES 100

void addEdge(int u, int v, int adjMatrix[MAX_NODES][MAX_NODES])
{
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
}

void displayMatrix(int nodes, int adjMatrix[MAX_NODES][MAX_NODES])
{
	int i, j;
    printf("Adjacency Matrix:\n");
    for (i = 0; i < nodes; i++)
    {
        for (j = 0; j < nodes; j++)
            printf("%d ", adjMatrix[i][j]);
        printf("\n");
    }
}

void BFS (int startNode, int nodes, int adjMatrix[MAX_NODES][MAX_NODES])
{
	static int visited[MAX_NODES];
	int queue[MAX_NODES], front = 0, rear = 0, i;
	
	visited[startNode] = 1;
	queue[rear++] = startNode;
	
	printf("BFS Traversal starting from node %d: ",startNode+1);
	
	while(front != rear)
	{
		int current = queue[front++];
		printf("%d ",current + 1);
		
		for(i = 0; i < nodes; i++)
		{
			if(adjMatrix[current][i] == 1 && visited[i] == 0)
			{
				visited[i] = 1;
				queue[rear++] = i;
			}
		}
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
    
    printf("Enter the starting node for BFS traversal: ");
    scanf("%d", &u);
    BFS(u-1, nodes, adjMatrix);

    return 0;
}

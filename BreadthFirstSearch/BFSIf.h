#include "LinQueueImpl.h"
#include "LinQueueIf.h"

typedef struct
{
	int count;
	int adj[100][100];
	char city[100][100];
} cityADT;

// Will represent the graph using adjacency matrix
void create(cityADT *C,int n)
{
	int i,j;
	
	C->count = n;
	
	printf("Enter the names of the cities:\n");
	for(i=0;i<n;i++) {
		printf("%d. ",i+1);
		scanf(" %[^\n]",C->city[i]);
	}
		
	printf("\nEnter (1) if there is a connection and (0) if not: \n");
	for(i=0;i<n;i++)
	{
		printf("\nFrom %s to: \n",C->city[i]);
		for(j=0;j<n;j++)
			if(j != i)
			{
				printf("\t%s: ",C->city[j]);
				scanf("%d",&C->adj[i][j]);
			}
			else
				C->adj[i][j] = 0;
	}
}

// Display the graph (Adjacency Matrix)
void display(cityADT *C)
{
	int n = C->count,i,j;
	
	printf("\nAdjacency Matrix:\n\n");
	
	printf("\t\t");
	for(i=0;i<n;i++)
		printf("%-10s",C->city[i]);
	printf("\n");
		
	for(i=0;i<n;i++)
	{
		printf("%-10s",C->city[i]);
		printf("\t");
		for(j=0;j<n;j++)
			printf("%-10d",C->adj[i][j]);
		printf("\n");
	}
}

// Displays the names of the cities in the graph
void displayCities(cityADT *C)
{
	int n = C->count,i;

	printf("\nList of Cities: \n");
	for(i=0;i<n;i++)
		printf("%d. %s\n",i+1,C->city[i]);
}

// Returns the index of the first unvisited node, if all nodes are visited, returns (-1)
int unvisited(int visited[],int n)
{
	for(int i=0;i<n;i++)
		if(visited[i] == 0)
			return(i);

	return(-1);
}

// Provides the output of visiting the cities by following breadth first
void BFS(cityADT *C)
{
	int x,y,z,n = C->count,i;

	// Creating and initializing a linear queue
	queueADT *Q = (queueADT *)malloc(sizeof(queueADT));
	initialize(Q,n);

	// Array of information on whether a city is visited. 1 -> Visited; 0 -> Unvisited.
	// Initializing all values to 0
	int *visited = (int *)malloc(n * sizeof(int));
	for(i=0;i<n;i++)
		visited[i] = 0;

	for(x = unvisited(visited,n); x!= -1 ; x = unvisited(visited,n))
	{
		// x is now considered as visited and is printed
		visited[x] = 1;
		printf("\nVisited: %s",C->city[x]);
		enqueue(Q,x);

		while(!isEmpty(Q))
		{
			z = dequeue(Q);
			for(y=0;y<n;y++)
			{
				// if y is both adjacent to z and not visited
				if(C->adj[z][y] && !(visited[y]))
				{
					// It is now visited and printed
					visited[y] = 1;
					printf("\nVisited: %s",C->city[y]);
					enqueue(Q,y);
				}
			}
		}
	}
	printf("\n");
}
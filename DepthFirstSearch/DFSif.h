#include"stackif.h"
#include"stackimpl.h"
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
	for(i=0;i<n;i++)
	{
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


int unvisited_adj(cityADT *C,int visited[],int z)
{
	int n = C->count;
	for(int y=0;y<n;y++)
	{
		if(C->adj[z][y] && !(visited[y]))
		{
			return y;
		}

	}
	return(-1);
}


void DFS(cityADT *C)
{
	Stack S;
	
	int x,y,z,n = C->count,i;
	
	initialize(&S,n);
	
	int *visited = (int *)malloc(n * sizeof(int));
	for(i=0;i<n;i++)
		visited[i] = 0;

	for(x = unvisited(visited,n); x!= -1 ; x = unvisited(visited,n))
	{
		// x is now considered as visited and is printed
		visited[x] = 1;
		printf("\nVisited: %s",C->city[x]);
		push(&S,x);

		while(!isEmpty(&S))
		{
			z = peek(&S);	
			y = unvisited_adj(C,visited,z);
					
			if(y!=-1)
			{	// It is now visited and printed
				visited[y] = 1;
				printf("\nVisited: %s",C->city[y]);
				push(&S,y);
			}
			else
				z = pop(&S);
		}
	}
	printf("\n");

}

char *pathway(cityADT *C)
{
	int x,y,z,n = C->count,i,src,dest,f=0;
	char *path = (char *)malloc(100);
	displayCities(C);
	printf("\nChoose the Source city form the following:\n");
	scanf("%d",&src);
	printf("\nChoose the Destination city form the following:\n");
	scanf("%d",&dest);

	Stack S;
	initialize(&S,n);
	
	int *visited = (int *)malloc(n * sizeof(int));
	for(i=0;i<n;i++)
		visited[i] = 0;

	for(x = unvisited(visited,n); x!= -1 ; x = unvisited(visited,n))
	{
		// x is now considered as visited and is printed
		visited[x] = 1;
		if((x == src-1)&& (strlen(path) == 0))
		{
			strcpy(path,C->city[x]);
			f = 1;
		}
		push(&S,x);

		while(!isEmpty(&S))
		{
			z = peek(&S);	
			y = unvisited_adj(C,visited,z);
					
			if(y!=-1)
			{	// It is now visited and printed
				visited[y] = 1;
				
				if( y==src-1 && strlen(path)==0)
				{ 
					strcpy(path,C->city[y]);
					f = 1;
				}
				else if(f)
				{
					strcat(path,"->");
					strcat(path,C->city[y]);
				}
				if(y == dest-1 && strlen(path)!=0)
					return(path);
				push(&S,y);
			}
			else
				z = pop(&S);
		}
	}
	return("Path doesn't exist");

}



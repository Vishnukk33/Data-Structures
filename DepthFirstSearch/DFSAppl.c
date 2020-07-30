#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"DFSif.h"

void main()
{
	cityADT *C = (cityADT *)malloc(sizeof(cityADT));
	int n,op,src,dest;
	
	printf("Enter the number of cities: ");
	scanf("%d",&n);
	
	create(C,n);

	do
	{
		printf("\nEnter your choice:\n1. Display the graph (Adjacency Matrix)\n2. Do a complete Breadth First Search\n3. Find a path between two cities\n4. Exit\n>>");
		scanf("%d",&op);

		switch(op)
		{
			case 1: display(C); break;

			case 2: DFS(C); break;

			case 3: printf("Path between the source and destination is %s",pathway(C));
				break;

			case 4: exit(0);
		}
	}while(1);
}

/*OUTPUT:
vishnu@vishnu-G7-7588:~/Desktop/DS$ gcc DFSAppl.c -o k
vishnu@vishnu-G7-7588:~/Desktop/DS$ ./k
Enter the number of cities: 4
Enter the names of the cities:
1. Chennai
2. Mumbai
3. Delhi
4. Riyad

Enter (1) if there is a connection and (0) if not: 

From Chennai to: 
	Mumbai: 1
	Delhi: 1
	Riyad: 0

From Mumbai to: 
	Chennai: 0
	Delhi: 1
	Riyad: 0

From Delhi to: 
	Chennai: 0
	Mumbai: 0
	Riyad: 1

From Riyad to: 
	Chennai: 0
	Mumbai: 0
	Delhi: 0

Enter your choice:
1. Display the graph (Adjacency Matrix)
2. Do a complete Breadth First Search
3. Find a path between two cities
4. Exit
>>1

Adjacency Matrix:

		Chennai   Mumbai    Delhi     Riyad     
Chennai   	0         1         1         0         
Mumbai    	0         0         1         0         
Delhi     	0         0         0         1         
Riyad     	0         0         0         0         

Enter your choice:
1. Display the graph (Adjacency Matrix)
2. Do a complete Breadth First Search
3. Find a path between two cities
4. Exit
>>2

Visited: Chennai
Visited: Mumbai
Visited: Delhi
Visited: Riyad

Enter your choice:
1. Display the graph (Adjacency Matrix)
2. Do a complete Breadth First Search
3. Find a path between two cities
4. Exit
>>3

List of Cities: 
1. Chennai
2. Mumbai
3. Delhi
4. Riyad

Choose the Source city form the following:
1

Choose the Destination city form the following:
4
Path between the source and destination is Chennai->Mumbai->Delhi->Riyad
Enter your choice:
1. Display the graph (Adjacency Matrix)
2. Do a complete Breadth First Search
3. Find a path between two cities
4. Exit
>>3

*/

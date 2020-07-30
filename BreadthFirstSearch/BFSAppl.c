#include<stdlib.h>
#include<stdio.h>
#include"BFSIf.h"

void main()
{
	cityADT *C = (cityADT *)malloc(sizeof(cityADT));
	int n,op,src,dest;
	
	printf("Enter the number of cities: ");
	scanf("%d",&n);
	
	create(C,n);

	do
	{
		printf("\nEnter your choice:\n1. Display the graph (Adjacency Matrix)\n2. Do a complete Breadth First Search\n3. Exit\n>>");
		scanf("%d",&op);

		switch(op)
		{
			case 1: display(C); break;

			case 2: BFS(C); break;

			case 3: exit(0);
		}
	}while(1);
}
/*OUTPUT:
vishnu@vishnu-G7-7588:~/Desktop/DS/BFS$ gcc BFSAppl.c -o k
vishnu@vishnu-G7-7588:~/Desktop/DS/BFS$ ./k
Enter the number of cities: 5
Enter the names of the cities:
1. a
2. b
3. c
4. d
5. e

Enter (1) if there is a connection and (0) if not: 

From a to: 
	b: 1
	c: 1
	d: 0
	e: 0

From b to: 
	a: 9
	c: 1
	d: 1
	e: 1

From c to: 
	a: 1
	b: 0
	d: 0
	e: 1

From d to: 
	a: 1
	b: 1
	c: 1
	e: 1

From e to: 
	a: 0
	b: 0
	c: 0
	d: 0

Enter your choice:
1. Display the graph (Adjacency Matrix)
2. Do a complete Breadth First Search
3. Exit
>>1

Adjacency Matrix:

		a         b         c         d         e         
a         	0         1         1         0         0         
b         	9         0         1         1         1         
c         	1         0         0         0         1         
d         	1         1         1         0         1         
e         	0         0         0         0         0         

Enter your choice:
1. Display the graph (Adjacency Matrix)
2. Do a complete Breadth First Search
3. Exit
>>2

Visited: a
Visited: b
Visited: c
Visited: d
Visited: e

Enter your choice:
1. Display the graph (Adjacency Matrix)
2. Do a complete Breadth First Search
3. Exit
>>3
*/

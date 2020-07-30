#include"digkstraimpl.h"
void main()
{
	char s[100],d[100];
	cityADT *c;
	int ch;
	do
	{
		printf("\nMenu:\n1.Create\n2.Display\n3.Dijkstra output\n4.Check connectivity\n5.exit\nChoice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :c=create(c);
					break;
			case 2 :disp(c);
					break;
			case 3 :printf("Enter Starting Node: ");
					scanf("%s",s);
					DijkstraAlgo(c,s);break;
			case 4 :printf("Enter source and destination cities: \n");
					scanf("%s",s);
					scanf("%s",d);
					shortestPath(c,s,d);
					break;
		}
	}while(ch!=5);
}

/*
Output:
Menu:
1.Create
2.Display
3.Dijkstra output
4.Check connectivity
5.exit
Choice: 1
Enter no of citites : 3
enter the cities
Chennai
Coimbatore
Banglore
Enter Neighbours of Chennai:
Are there any neighbours?y/n : y
Banglore
city found at : 2 
Enter distance between them : 3
Are there any more neighbours?y/n : n
Enter Neighbours of Coimbatore:
Are there any neighbours?y/n : n
Enter Neighbours of Banglore:
Are there any neighbours?y/n : n

Menu:
1.Create
2.Display
3.Dijkstra output
4.Check connectivity
5.exit
Choice: 4
Enter source and destination cities: 
Chennai Banglore


Chennai ->Banglore ->
Menu:
1.Create
2.Display
3.Dijkstra output
4.Check connectivity
5.exit
Choice: 5

*/

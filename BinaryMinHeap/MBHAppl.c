#include<stdio.h>
#include<stdlib.h>
#include "IntArrImpl.h"

void main(){
	PriorityQ *PQ;
	PQ=(PriorityQ *)malloc(sizeof(PriorityQ));
	initPQ(PQ,100);
	
	int opt=1;
	int x;	
		
	while(opt!=0){		
		printf("\n\t\t\tMAIN MENU\n");
		printf("\n\t1 to Insert\n\t2 to Delete\n\t3 to Display\n\t0 to Exit\nEnter Your Choice:\n-> ");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("\nEnter the element: ");
				scanf("%d",&x);
				insert(PQ,x);
				break;
			case 2:
				printf("\nThe deleted element was: %d",deletemin(PQ));
				break;
			case 3:
				display(PQ);
				break;
			case 0:
				printf("\n\t\t\tThank You!");
				break;
			default:
				printf("\n\t\tInvalid Option!");
				break;		
		}
	}

}


/*
OUTPUT:

vishnu@vishnu-G7-7588:~/DSLAB/Priority Queue$ gcc MBHAppl.c -o m
vishnu@vishnu-G7-7588:~/DSLAB/Priority Queue$ ./m

			MAIN MENU

	1 to Insert
	2 to Delete
	3 to Display
	0 to Exit
Enter Your Choice:
-> 1

Enter the element: 6

			MAIN MENU

	1 to Insert
	2 to Delete
	3 to Display
	0 to Exit
Enter Your Choice:
-> 1

Enter the element: 2

			MAIN MENU

	1 to Insert
	2 to Delete
	3 to Display
	0 to Exit
Enter Your Choice:
-> 1

Enter the element: 4

			MAIN MENU

	1 to Insert
	2 to Delete
	3 to Display
	0 to Exit
Enter Your Choice:
-> 1

Enter the element: 3

			MAIN MENU

	1 to Insert
	2 to Delete
	3 to Display
	0 to Exit
Enter Your Choice:
-> 1

Enter the element: 5

			MAIN MENU

	1 to Insert
	2 to Delete
	3 to Display
	0 to Exit
Enter Your Choice:
-> 1

Enter the element: 4

			MAIN MENU

	1 to Insert
	2 to Delete
	3 to Display
	0 to Exit
Enter Your Choice:
-> 1

Enter the element: 7

			MAIN MENU

	1 to Insert
	2 to Delete
	3 to Display
	0 to Exit
Enter Your Choice:
-> 1

Enter the element: 4

			MAIN MENU

	1 to Insert
	2 to Delete
	3 to Display
	0 to Exit
Enter Your Choice:
-> 3

From top to bottom: 
	2
	3
	4
	4
	5
	4
	7
	6
			MAIN MENU

	1 to Insert
	2 to Delete
	3 to Display
	0 to Exit
Enter Your Choice:
-> 2

The deleted element was: 2
			MAIN MENU

	1 to Insert
	2 to Delete
	3 to Display
	0 to Exit
Enter Your Choice:
->            
2

The deleted element was: 3
			MAIN MENU

	1 to Insert
	2 to Delete
	3 to Display
	0 to Exit
Enter Your Choice:
-> 3

From top to bottom: 
	4
	5
	4
	6
	7
	4
			MAIN MENU

	1 to Insert
	2 to Delete
	3 to Display
	0 to Exit
Enter Your Choice:
-> 1

Enter the element: 9

			MAIN MENU

	1 to Insert
	2 to Delete
	3 to Display
	0 to Exit
Enter Your Choice:
-> 3

From top to bottom: 
	4
	5
	4
	6
	7
	4
	9
			MAIN MENU

	1 to Insert
	2 to Delete
	3 to Display
	0 to Exit
Enter Your Choice:
-> 1

Enter the element: 3

			MAIN MENU

	1 to Insert
	2 to Delete
	3 to Display
	0 to Exit
Enter Your Choice:
-> 3

From top to bottom: 
	3
	4
	4
	5
	7
	4
	9
	6
			MAIN MENU

	1 to Insert
	2 to Delete
	3 to Display
	0 to Exit
Enter Your Choice:
-> 2

The deleted element was: 3
			MAIN MENU

	1 to Insert
	2 to Delete
	3 to Display
	0 to Exit
Enter Your Choice:
-> 0


*/

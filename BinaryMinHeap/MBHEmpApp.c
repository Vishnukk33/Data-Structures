#include<stdio.h>
#include<stdlib.h>
#include "MBHIf.h"
#include "MBHImpl.h"

void main(){
	PriorityQ *PQ;
	PQ=(PriorityQ *)malloc(sizeof(PriorityQ));
	
	int opt=1,size;
	empDetails e;	
		
	while(opt!=0){		
		printf("\n\t\t\tEMPLOYEE MANAGEMENT SYSTEM\n");
		printf("\n\t1 to Insert\n\t2 to Delete\n\t3 to Display\n\t4 to Initialize\n\t0 to Exit\nEnter Your Choice:\n-> ");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("\nEnter the Employee Name: ");
				scanf("%s",e.name);
				printf("\nEnter the Employee ID: ");
				scanf("%d",&(e.eid));
				printf("\nEnter the Employee Salary: ");
				scanf("%f",&(e.salary));
				insert(PQ,e);
				break;
			case 2:
				e=deletemin(PQ);
				printf("\nThe Deleted Person's Details are:\nEmployee ID: %d\nEmployee Name: %s\nEmployee Salary: %.2f\n",e.eid,e.name,e.salary);
				break;
			case 3:
				printf("\nThe Priority Queue in Min Binary Heap Hierarchy:\n\n");
				disp(PQ,1,0);
				break;
			case 4:
				printf("\nEnter the Size of Heap: ");
				scanf("%d",&size);
				initPQ(PQ,size);
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

exam62@jtl-16:~/DSLAB/Priority Queue$ gcc MBHEmpApp.c -o e
exam62@jtl-16:~/DSLAB/Priority Queue$ ./e

			EMPLOYEE MANAGEMENT SYSTEM

	1 to Insert
	2 to Delete
	3 to Display
	4 to Initialize
	0 to Exit
Enter Your Choice:
-> 4

Enter the Size of Heap: 8

			EMPLOYEE MANAGEMENT SYSTEM

	1 to Insert
	2 to Delete
	3 to Display
	4 to Initialize
	0 to Exit
Enter Your Choice:
-> 1

Enter the Employee Name: A

Enter the Employee ID: 1

Enter the Employee Salary: 50000

			EMPLOYEE MANAGEMENT SYSTEM

	1 to Insert
	2 to Delete
	3 to Display
	4 to Initialize
	0 to Exit
Enter Your Choice:
-> 1

Enter the Employee Name: B

Enter the Employee ID: 2

Enter the Employee Salary: 43300 

			EMPLOYEE MANAGEMENT SYSTEM

	1 to Insert
	2 to Delete
	3 to Display
	4 to Initialize
	0 to Exit
Enter Your Choice:
-> 1

Enter the Employee Name: C

Enter the Employee ID: 3

Enter the Employee Salary: 54300

			EMPLOYEE MANAGEMENT SYSTEM

	1 to Insert
	2 to Delete
	3 to Display
	4 to Initialize
	0 to Exit
Enter Your Choice:
-> 1

Enter the Employee Name: D

Enter the Employee ID: 43

Enter the Employee Salary: 24000

			EMPLOYEE MANAGEMENT SYSTEM

	1 to Insert
	2 to Delete
	3 to Display
	4 to Initialize
	0 to Exit
Enter Your Choice:
-> 1

Enter the Employee Name: E

Enter the Employee ID: 5 

Enter the Employee Salary: 33830

			EMPLOYEE MANAGEMENT SYSTEM

	1 to Insert
	2 to Delete
	3 to Display
	4 to Initialize
	0 to Exit
Enter Your Choice:
-> 3

The Priority Queue in Min Binary Heap Hierarchy:


D
	E
		A
		B
	C
			EMPLOYEE MANAGEMENT SYSTEM

	1 to Insert
	2 to Delete
	3 to Display
	4 to Initialize
	0 to Exit
Enter Your Choice:
-> 2

The Deleted Person's Details are:
Employee ID: 43
Employee Name: D
Employee Salary: 24000.00

			EMPLOYEE MANAGEMENT SYSTEM

	1 to Insert
	2 to Delete
	3 to Display
	4 to Initialize
	0 to Exit
Enter Your Choice:
-> 3

The Priority Queue in Min Binary Heap Hierarchy:


E
	B
		A
	C
			EMPLOYEE MANAGEMENT SYSTEM

	1 to Insert
	2 to Delete
	3 to Display
	4 to Initialize
	0 to Exit
Enter Your Choice:
-> 0

			Thank You!

*/


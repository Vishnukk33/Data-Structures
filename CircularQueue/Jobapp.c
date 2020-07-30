#include"cqueuev2.h"
void main()
{
	Queue *Q1,*Q2;
	Q1= (Queue*)malloc(sizeof(Queue));
	Q2= (Queue*)malloc(sizeof(Queue));
	int p;
	JOB x;
	init(Q1);
	init(Q2);
	do
	{
		printf("\n\n\nQueue\n1.Enqueue\n2.Display\n3.Exit");
		printf("\nEnter choice: ");
		scanf("%d",&p);
		switch(p)
		{
			case 1:	printf("\nEnter name of job: ");
				scanf(" %c",&x.name);
				printf("\nEnter timetaken by job: ");
				scanf("%d",&x.time);
				if(waitingtime(Q1)>waitingtime(Q2))
					enqueue(Q2, x);
				else 
					enqueue(Q1, x);
				break;
			case 2:	printf("\n\nQueue 1:");
				disp(Q1);
				printf("\nTotal time = %d",waitingtime(Q1));

				printf("\n\nQueue 2:");
				disp(Q2);
				printf("\nTotal time = %d",waitingtime(Q2));
				break;
			case 3:	exit(0);
				break;
			default:printf("\nInvalid input");
		}
	}while(1);
}
/*OUTPUT
exam52@jtl-30:~/DS/Ex5$ gcc Jobapp.c -o l
exam52@jtl-30:~/DS/Ex5$ ./l



Queue
1.Enqueue
2.Display
3.Exit
Enter choice: 1

Enter name of job: R

Enter timetaken by job: 4



Queue
1.Enqueue
2.Display
3.Exit
Enter choice: 1

Enter name of job: W

Enter timetaken by job: 6



Queue
1.Enqueue
2.Display
3.Exit
Enter choice: 2


Queue 1:
Queue elements are:
Job name: R
Job time: 4
Total time = 4

Queue 2:
Queue elements are:
Job name: W
Job time: 6
Total time = 6


Queue
1.Enqueue
2.Display
3.Exit
Enter choice: 1

Enter name of job: D

Enter timetaken by job: 1



Queue
1.Enqueue
2.Display
3.Exit
Enter choice: 2


Queue 1:
Queue elements are:
Job name: R
Job time: 4
Job name: D
Job time: 1
Total time = 5

Queue 2:
Queue elements are:
Job name: W
Job time: 6
Total time = 6


Queue
1.Enqueue
2.Display
3.Exit
Enter choice: 3
*/

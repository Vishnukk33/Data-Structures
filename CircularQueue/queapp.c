//#include"lqueue.h"
#include"cqueuev1.h"
void main()
{
	Queue *Q;
	Q = (Queue*)malloc(sizeof(Queue));
	int p,x;
	init(Q);
	do
	{
		printf("\n\n\nQueue\n1.Enqueue\n2.Dequeue\n3.Display\n4.FULL?\n5.EMPTY?\n6.no of elements\n7.Exit");
		printf("\nEnter choice: ");
		scanf("%d",&p);
		switch(p)
		{
			case 1:	printf("\nEnter element to be added: ");
				scanf("%d",&x);
				enqueue(Q, x);
				break;
			case 2:	x =dequeue(Q);
				if(x!=-999)
				{
					printf("\nElement popped is %d\n",x);
				}	
				break;
			case 3:	disp(Q);
				break;
			case 4:	if(isFull(Q))
					printf("\nQueue is full");
				else 
					printf("\nQueue is not full");
				break;
			case 5:if(isEmpty(Q))
					printf("\nQueue is empty");
				else 
					printf("\nQueue is not empty");
				break;
			case 6:printf("Size:%d",Q->size);
				break;
			case 7:	exit(0);
				break;
			default:printf("\nInvalid input");
		}
	}while(1);
}

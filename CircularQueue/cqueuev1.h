#include<stdio.h>
#include<stdlib.h>

typedef struct Queue
{
	int a[10];
	int f,r;
	int size;
}Queue;

void init(Queue *Q)
{
	Q->f = -1;
	Q->r = -1;
	Q->size = 0;
}

int isFull(Queue *Q)
{
	if(Q->size>=10)
		return 1;
	else return 0;
}
int isEmpty(Queue *Q)
{
	if(Q->size==0)
		return 1;
	else return 0;
}
void enqueue(Queue *Q,int x)
{
	if(isFull(Q))
		printf("\nQueue is Full");
	else
	{
		if(Q->size==0)
		{
			Q->f = 0;
			Q->r = 0;
			Q->a[Q->r] = x;
		}
		else
		{
			
			if(Q->r==9)
			{
				Q->r = 0;
			}
			else
				Q->r+=1;
			Q->a[Q->r] = x;	
		}
		Q->size++;
	}
}
int dequeue(Queue *Q)
{
	int s=-999;
	if(isEmpty(Q))
		printf("\nQueue is empty(underflow)");
	else
	{		
		s= Q->a[Q->f];
		if(Q->f==Q->r)
		{
			printf("hi");
			Q->f = -1;
			Q->r = -1;
			Q->size = 0;
		}
		else
		{
			if(Q->f==9)
				Q->f=0;
			else 
				Q->f+=1;
			Q->size--;
		}
	}
	return s;
}
void disp(Queue *Q)
{
	if(isEmpty(Q))
		printf("\nQueue is empty");
	else 
	{
		int p = Q->f,l=Q->size;
		printf("\nQueue elements are:");
		while(l!=0)
		{
			printf("\nElement: %d",Q->a[p]);
			if(p==9)
				p=0;
			else		
				p++;
			l--;
		}
	}
} 
/*OUTPUT
exam52@jtl-30:~/DS/Ex5$ gcc queapp.c -o l
exam52@jtl-30:~/DS/Ex5$ ./l



Queue
1.Enqueue
2.Dequeue
3.Display
4.FULL?
5.EMPTY?
6.no of elements
7.Exit
Enter choice: 1

Enter element to be added: 6



Queue
1.Enqueue
2.Dequeue
3.Display
4.FULL?
5.EMPTY?
6.no of elements
7.Exit
Enter choice: 1

Enter element to be added: 5



Queue
1.Enqueue
2.Dequeue
3.Display
4.FULL?
5.EMPTY?
6.no of elements
7.Exit
Enter choice: 1

Enter element to be added: 4



Queue
1.Enqueue
2.Dequeue
3.Display
4.FULL?
5.EMPTY?
6.no of elements
7.Exit
Enter choice: 1

Enter element to be added: 3



Queue
1.Enqueue
2.Dequeue
3.Display
4.FULL?
5.EMPTY?
6.no of elements
7.Exit
Enter choice: 1

Enter element to be added: 3



Queue
1.Enqueue
2.Dequeue
3.Display
4.FULL?
5.EMPTY?
6.no of elements
7.Exit
Enter choice: 1

Enter element to be added: 2



Queue
1.Enqueue
2.Dequeue
3.Display
4.FULL?
5.EMPTY?
6.no of elements
7.Exit
Enter choice: 1

Enter element to be added: 1



Queue
1.Enqueue
2.Dequeue
3.Display
4.FULL?
5.EMPTY?
6.no of elements
7.Exit
Enter choice: 1

Enter element to be added: 6



Queue
1.Enqueue
2.Dequeue
3.Display
4.FULL?
5.EMPTY?
6.no of elements
7.Exit
Enter choice: 1

Enter element to be added: 7



Queue
1.Enqueue
2.Dequeue
3.Display
4.FULL?
5.EMPTY?
6.no of elements
7.Exit
Enter choice: 1

Enter element to be added: 8



Queue
1.Enqueue
2.Dequeue
3.Display
4.FULL?
5.EMPTY?
6.no of elements
7.Exit
Enter choice: 1

Enter element to be added: 7

Queue is Full


Queue
1.Enqueue
2.Dequeue
3.Display
4.FULL?
5.EMPTY?
6.no of elements
7.Exit
Enter choice: 3

Queue elements are:
Element: 6
Element: 5
Element: 4
Element: 3
Element: 3
Element: 2
Element: 1
Element: 6
Element: 7
Element: 8


Queue
1.Enqueue
2.Dequeue
3.Display
4.FULL?
5.EMPTY?
6.no of elements
7.Exit
Enter choice: 4

Queue is full


Queue
1.Enqueue
2.Dequeue
3.Display
4.FULL?
5.EMPTY?
6.no of elements
7.Exit
Enter choice: 5

Queue is not empty


Queue
1.Enqueue
2.Dequeue
3.Display
4.FULL?
5.EMPTY?
6.no of elements
7.Exit
Enter choice: 2

Element popped is 6



Queue
1.Enqueue
2.Dequeue
3.Display
4.FULL?
5.EMPTY?
6.no of elements
7.Exit
Enter choice: 1

Enter element to be added: 5



Queue
1.Enqueue
2.Dequeue
3.Display
4.FULL?
5.EMPTY?
6.no of elements
7.Exit
Enter choice: 4

Queue is full


Queue
1.Enqueue
2.Dequeue
3.Display
4.FULL?
5.EMPTY?
6.no of elements
7.Exit
Enter choice: 7
*/

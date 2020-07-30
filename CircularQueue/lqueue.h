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
	if(Q->r>=9)
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
			Q->f = -1;
			Q->r = -1;
			Q->size = 0;
		}
		else
		{
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
		int p = Q->f;
		printf("\nQueue elements are:");
		while(p<=Q->r)
		{
			printf("\nElement: %d",Q->a[p]);
			p++;
		}
	}
} 
/*OUTPUT
Queue
1.Enqueue
2.Dequeue
3.Display
4.FULL?
5.EMPTY?
6.Exit
Enter choice: 1

Enter element to be added: 3



Queue
1.Enqueue
2.Dequeue
3.Display
4.FULL?
5.EMPTY?
6.Exit
Enter choice: 1

Enter element to be added: 5



Queue
1.Enqueue
2.Dequeue
3.Display
4.FULL?
5.EMPTY?
6.Exit
Enter choice: 1

Enter element to be added: 4



Queue
1.Enqueue
2.Dequeue
3.Display
4.FULL?
5.EMPTY?
6.Exit
Enter choice: 1

Enter element to be added: 4



Queue
1.Enqueue
2.Dequeue
3.Display
4.FULL?
5.EMPTY?
6.Exit
Enter choice: 1

Enter element to be added: 5



Queue
1.Enqueue
2.Dequeue
3.Display
4.FULL?
5.EMPTY?
6.Exit
Enter choice: 1

Enter element to be added: 3



Queue
1.Enqueue
2.Dequeue
3.Display
4.FULL?
5.EMPTY?
6.Exit
Enter choice: 1

Enter element to be added: 3



Queue
1.Enqueue
2.Dequeue
3.Display
4.FULL?
5.EMPTY?
6.Exit
Enter choice: 1

Enter element to be added: 5



Queue
1.Enqueue
2.Dequeue
3.Display
4.FULL?
5.EMPTY?
6.Exit
Enter choice: 1

Enter element to be added: 4



Queue
1.Enqueue
2.Dequeue
3.Display
4.FULL?
5.EMPTY?
6.Exit
Enter choice: 1

Enter element to be added: 4



Queue
1.Enqueue
2.Dequeue
3.Display
4.FULL?
5.EMPTY?
6.Exit
Enter choice: 1

Enter element to be added: 5

Queue is Full


Queue
1.Enqueue
2.Dequeue
3.Display
4.FULL?
5.EMPTY?
6.Exit
Enter choice: 1

Enter element to be added: 6

Queue is Full


Queue
1.Enqueue
2.Dequeue
3.Display
4.FULL?
5.EMPTY?
6.Exit
Enter choice: 3

Queue elements are:
Element: 3
Element: 5
Element: 4
Element: 4
Element: 5
Element: 3
Element: 3
Element: 5
Element: 4
Element: 4


Queue
1.Enqueue
2.Dequeue
3.Display
4.FULL?
5.EMPTY?
6.Exit
Enter choice: 2

Element popped is 3



Queue
1.Enqueue
2.Dequeue
3.Display
4.FULL?
5.EMPTY?
6.Exit
Enter choice: 1

Enter element to be added: 4

Queue is Full


Queue
1.Enqueue
2.Dequeue
3.Display
4.FULL?
5.EMPTY?
6.Exit
Enter choice: 3

Queue elements are:
Element: 5
Element: 4
Element: 4
Element: 5
Element: 3
Element: 3
Element: 5
Element: 4
Element: 4


Queue
1.Enqueue
2.Dequeue
3.Display
4.FULL?
5.EMPTY?
6.Exit
Enter choice: 4

Queue is full


Queue
1.Enqueue
2.Dequeue
3.Display
4.FULL?
5.EMPTY?
6.Exit
Enter choice: 5

Queue is not empty


Queue
1.Enqueue
2.Dequeue
3.Display
4.FULL?
5.EMPTY?
6.Exit
Enter choice: 6
*/

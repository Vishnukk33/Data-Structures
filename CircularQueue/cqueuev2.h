#include<stdio.h>
#include<stdlib.h>

typedef struct JOB
{
	char name;
	int time;
}JOB;
typedef struct Queue
{
	struct JOB a[10];
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
void enqueue(Queue *Q,struct JOB x)
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
struct JOB dequeue(Queue *Q)
{
	JOB s;
	s.time =-999;
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
			printf("\nJob name: %c\nJob time: %d",Q->a[p].name,Q->a[p].time);
			if(p==9)
				p=0;
			else		
				p++;
			l--;
		}
	}
} 

int waitingtime(Queue *Q)
{
	if(isEmpty(Q))
		return 0;
	else 
	{
		int p = Q->f,l=Q->size;
		int tot=0;
		while(l!=0)
		{
			tot+=Q->a[p].time;
			if(p==9)
				p=0;
			else		
				p++;
			l--;
		}
		return tot;
	}
}

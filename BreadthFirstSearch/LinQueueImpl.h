typedef struct
{
	int *a;
	int front, rear, cap;
} queueADT;

void initialize(queueADT *Q, int n)
{
	Q->a = (int *)malloc(n * sizeof(int));
	Q->front = Q->rear = -1;
	Q->cap = n;
}

int isFull(queueADT *Q)
{
	if(Q->rear == Q->cap - 1)
		return(1);
	return(0);
}

int isEmpty(queueADT *Q)
{
	if(Q->rear == Q->front)
		return(1);
	return(0);
}

void enqueue(queueADT *Q, int x)
{
	if(isFull(Q))
		printf("\nQueue is full!\n");
	else
		Q->a[++Q->rear] = x;
}

int dequeue(queueADT *Q)
{
	if(isEmpty(Q))
	{
		printf("\nQueue is empty!\n");
		return(-100);
	}
	return(Q->a[++Q->front]);
}

void displayQ(queueADT *Q)
{
	if(isEmpty(Q))
		printf("\nQueue is empty!\n");
	else
	{
		printf("Queue: \n");
		for(int i = Q->front+1; i<=Q->rear ; i++)
			printf("%d ",Q->a[i]);
		printf("\n");
	}
}
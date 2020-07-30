typedef struct{
	int *arr;
	int size;
	int cap;
}PriorityQ;


void initPQ(PriorityQ *PQ, int x){
	PQ->cap=x;
	PQ->size=0;
	PQ->arr=(int *)malloc(sizeof(int)*x);
	PQ->arr[0]=-1000;
}

void insert(PriorityQ *PQ, int x){
	int i;
	for(i=++PQ->size;PQ->arr[i/2]>x;i/=2)
		PQ->arr[i]=PQ->arr[i/2];
	PQ->arr[i]=x;

}

int deletemin(PriorityQ *PQ){
	int i,child;
	int min,last;
	min=PQ->arr[1];
	last=PQ->arr[PQ->size--];

	for(i=1;(2*i)<=PQ->size;i=child){
		child=i*2;
		if(PQ->arr[child+1]<PQ->arr[child])
			child++;
		if(last>PQ->arr[child])
			PQ->arr[i]=PQ->arr[child];
		else
			break;
	}
	PQ->arr[i]=last;
	return min;
}



int display(PriorityQ *PQ){
	printf("\nFrom top to bottom: ");
	int i;
	for(i=1;i<=PQ->size;i++)
		printf("\n\t%d",PQ->arr[i]);
}

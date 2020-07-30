void initPQ(PriorityQ *PQ, int x){
	PQ->cap=x;
	PQ->size=0;
	PQ->e=(empDetails *)malloc(sizeof(empDetails)*x);
	PQ->e[0].salary=-1000;
}

void insert(PriorityQ *PQ, empDetails x){			//– Insertion of the details of a new employee into priority queue
	int i;
	for(i=++PQ->size;PQ->e[i/2].salary>x.salary;i=i/2)	
		PQ->e[i]=PQ->e[i/2];
	PQ->e[i]=x;

} 	

void disp(PriorityQ *PQ,int pos,int spacing){						//– Display the information about the employees (Hierarchically)
	if(pos<=PQ->size){	
		int i=0;
		printf("\n");
		while(i<spacing){
			printf("\t");
			i++;
		}
		printf("%s",PQ->e[pos].name);
		disp(PQ,2*pos,spacing+1);
		disp(PQ,2*pos+1,spacing+1);
	}
}	 			

empDetails deletemin(PriorityQ *PQ){					//– Will remove the employee at the root of the min binary heap from the queue
	int i,child;
	empDetails min,last;
	
	min=PQ->e[1];
	last=PQ->e[PQ->size--];

	for(i=1;(2*i)<=PQ->size;i=child){
		child=i*2;
		if(PQ->e[child+1].salary<PQ->e[child].salary)
			child++;
		if(last.salary>PQ->e[child].salary)
			PQ->e[i]=PQ->e[child];
		else
			break;
	}

	PQ->e[i]=last;
	return min;
} 			

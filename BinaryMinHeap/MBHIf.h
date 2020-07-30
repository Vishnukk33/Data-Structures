typedef struct{
	int eid;
	char name[30];
	float salary;

}empDetails;

typedef struct{
	empDetails *e;
	int cap;
	int size;
}PriorityQ;


void insert(PriorityQ *PQ, empDetails x); 	//– Insertion of the details of a new employee into priority queue
void disp(PriorityQ *PQ, int pos, int spacing);	 			//– Display the information about the employees (Hierarchically)
empDetails deletemin(PriorityQ *PQ); 			//– Will remove the employee at the root of the min binary heap from the queue

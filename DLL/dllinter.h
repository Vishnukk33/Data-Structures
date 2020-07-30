typedef struct person
{	long int pin,mob;
	char name[20],sex,add[20],city[20];
	int age;
}person;

typedef struct perADT
{	person p;
	struct perADT *rptr,*lptr;
}perADT;

void initialise(perADT *l);
person accept();
void insertFront(perADT *l,person x);
void display(perADT *l);
void insertEnd(perADT *l,person x);
void sort(perADT *l);
void insertPIN(perADT *l,person x,long int PIN);
perADT *senior(perADT *l);
perADT *locate(perADT *l,char *s);
void ratio(perADT *l);
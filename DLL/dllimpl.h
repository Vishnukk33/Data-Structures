
void initialise(perADT *l)
{	l->rptr=NULL;
	l->lptr=NULL;
}

person accept()
{	int flag,n,i;
	person x;
	printf("enter name:");
	scanf("%s",x.name);
	printf("enter age:");
	scanf("%d",&x.age);
	printf("enter address:");
	scanf("%s",x.add);
	printf("enter city:");
	scanf("%s",x.city);
	printf("enter sex:");
	scanf(" %c",&x.sex);
	printf("enter mobile:");
	scanf("%li",&x.mob);
	srand(time(0));
	n=1000+rand()%9000;
	x.pin=n;
	return x;
}
	
void insertFront(perADT *l,person x)
{	perADT *temp=malloc(sizeof(perADT));
	temp->p=x;
	if(l->rptr==NULL)
	{	temp->rptr=NULL;
		temp->lptr=l;
		l->rptr=temp;
	}
	else
	{	temp->rptr=l->rptr;
		temp->lptr=l;
		(l->rptr)->lptr=temp;
		l->rptr=temp;
	}
}

void insertEnd(perADT *l,person x)
{	perADT *temp=malloc(sizeof(perADT));
	temp->p=x;
	perADT *m,*n;
	m=l->rptr;
	if(m==NULL)
	{
		temp->lptr = l;
		temp->rptr = NULL;
		l->rptr = temp;
	}
	else
	{
		
		while(m!=NULL)
		{	n=m;
			m=m->rptr;
		}
		temp->lptr=n;
		temp->rptr = NULL;
		n->rptr=temp;
	}

}


void display(perADT *l)
{	perADT *temp=l->rptr;
	perADT *k;
	while(temp!=NULL)
	{	printf("\n\nname:%s \n",temp->p.name);
		printf("pin:%li \n",temp->p.pin);
		printf("sex:%c \n",temp->p.sex);
		printf("address:%s \n",temp->p.add);
		printf("city:%s \n",temp->p.city);
		printf("age:%d \n",temp->p.age);
		printf("Mobile:%li \n",temp->p.mob);
		k=temp;
		temp=temp->rptr;
	}
	while(k!=l)
	{	printf("\n\nname:%s \n",k->p.name);
		printf("pin:%li \n",k->p.pin);
		printf("sex:%c \n",k->p.sex);
		printf("address:%s \n",k->p.add);
		printf("city:%s \n",k->p.city);
		printf("age:%d \n",k->p.age);
		printf("Mobile:%li \n",k->p.mob);
		k=k->lptr;
	}	
}

void insertPIN(perADT *l,person x,long int PIN)
{	
	perADT *temp=malloc(sizeof(perADT));
	temp->p=x;
	perADT *m,*n;
	m=l->rptr;
	while(m->p.pin!=PIN)
	{	m=m->rptr;
	}
	if(m->rptr==NULL)
	{	temp->rptr=NULL;
		temp->lptr=m;
		m->rptr=temp;
	}
	else
	{	temp->rptr=m->rptr;
		temp->lptr=m;
		(m->rptr)->lptr=temp;
		m->rptr=temp;
	}
}

perADT *senior(perADT *l)
{	perADT*l1=malloc(sizeof(perADT));
	initialise(l1);
	perADT*m;
	m=l->rptr;
	while(m!=NULL)
	{	
		if(m->p.age>=60)
			insertEnd(l1,m->p);
		m=m->rptr;
	}
	return l1;
}

perADT *locate(perADT *l,char *s)
{	perADT*l1=malloc(sizeof(perADT));
	initialise(l1);
	perADT*m;
	m=l->rptr;
	while(m!=NULL)
	{	
		if(strcmp(m->p.city,s)==0)
			insertEnd(l1,m->p);
		m=m->rptr;
	}
	return l1;
}

void ratio(perADT *l)
{	perADT *temp;
	temp=l->rptr;
	int m=0,w=0;
	while(temp!=NULL)
	{
		if(temp->p.sex=='M')
			m++;
		else w++;
		temp = temp->rptr;
	}
	printf("Ratio of men to women is:  %d:%d",m,w);
}

		
void sort(perADT *l)
{	perADT *temp=l->rptr;
	perADT *k=l->rptr;
	perADT *y;
	person x;
	char na[20];
	while(temp!=NULL)
	{	strcpy(na,temp->p.name);
		y=temp;
		k=temp->rptr;
		while(k!=NULL)
		{	if(strcmp(k->p.name,na)<0)
			{	y=k;
				strcpy(na,k->p.name);
			}
			k=k->rptr;
		}
		x=y->p;
		y->p=temp->p;
		temp->p=x;
		temp=temp->rptr;
	}
}
				
	








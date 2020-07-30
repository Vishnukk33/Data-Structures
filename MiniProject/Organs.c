#include<stdio.h>
#include<stdlib.h>
#include<string.h>



typedef struct{
	int Pid;
	char Name[30],Gender;
	float TimeLeft;
	int Age;
	char BloodGroup[3];
	char Organ[30];

}PatientDetails;

typedef struct{
	PatientDetails *e;
	int cap;
	int size;
}PriorityQ;


typedef struct{
	char OrganName[30];
	char BloodGroup[3];
}ORGAN;



void dispboth(ORGAN P,PatientDetails A);
int BLcheck(char s1[], char s2[]);


void initPQ(PriorityQ *PQ, int x){
	PQ->cap=x;
	PQ->size=0;
	PQ->e=(PatientDetails *)malloc(sizeof(PatientDetails)*x);
	PQ->e[0].TimeLeft=-1000;
}



void insert(PriorityQ *PQ, PatientDetails x){			//– Insertion of the details of a new employee into priority queue
	int i;
	for(i=++PQ->size;PQ->e[i/2].TimeLeft>x.TimeLeft;i=i/2)	
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
		printf("%s",PQ->e[pos].Name);
		disp(PQ,2*pos,spacing+1);
		disp(PQ,2*pos+1,spacing+1);
	}
}	 			

PatientDetails deletemin(PriorityQ *PQ){					//– Will remove the employee at the root of the min binary heap from the queue
	int i,child;
	PatientDetails min,last;
	
	min=PQ->e[1];
	last=PQ->e[PQ->size--];

	for(i=1;(2*i)<=PQ->size;i=child){
		child=i*2;
		if(PQ->e[child+1].TimeLeft<PQ->e[child].TimeLeft)
			child++;
		if(last.TimeLeft>PQ->e[child].TimeLeft)
			PQ->e[i]=PQ->e[child];
		else
			break;
	}

	PQ->e[i]=last;
	return min;
} 			

PatientDetails Accept()
{
	PatientDetails e;
	printf("\n\nEnter the Patient Name: ");
	scanf(" %[^\n]",e.Name);
	printf("\nEnter the Patient ID: ");
	scanf("%d",&(e.Pid));
	printf("Enter the Patient Gender( M / F ): ");
	scanf(" %c",&(e.Gender));
	printf("Enter the Patient Age: ");
	scanf("%d",&(e.Age));
	printf("Enter the Patient BloodGroup( A / B / O / AB): ");
	scanf(" %[^\n]",e.BloodGroup);
	printf("Enter the Patient's Organ required( Heart / Lungs / Liver / Kidney ): ");
	scanf(" %[^\n]",e.Organ);
	printf("Enter the Patient's Time left(no of hours): ");	
	scanf("%f",&(e.TimeLeft));
	return e;

}




void AddOrgan()
{
	ORGAN a;
	int opt,i;
	FILE *f;
	f = fopen("Organs.dat","ab+");
	printf("\nEnter the number of organs you want to add: ");
	scanf("%d",&opt);
	for( i =0; i<opt;i++)
	{
		printf("\nEnter Organ name: ");
		scanf(" %[^\n]",a.OrganName);
		printf("Enter Blood Groupt of Donor: ");
		scanf(" %[^\n]",a.BloodGroup);
		fwrite(&a,sizeof(a),1,f);
	}
	printf("\nOrgans have been added to the file");
	fclose(f);
}


void DispOrgans()
{	
	printf("\nOrgans Present Available for Transplants: ");
	ORGAN a;
	FILE *f = fopen("Organs.dat","rb+");
	fread(&a,sizeof(a),1,f);
	while(!feof(f))
	{
		printf("\n\nOrgan Name: %s\nBlood Group: %s \n",a.OrganName,a.BloodGroup);
		fread(&a,sizeof(a),1,f);
	}	
	fclose(f);
}
void Transplant(PriorityQ *Liver,PriorityQ *Heart,PriorityQ *Lungs,PriorityQ *Kidney)
{
	
	ORGAN Lun[20];
	PriorityQ *L =(PriorityQ *)malloc(sizeof(PriorityQ));
	initPQ(L,20);
	ORGAN Hea[20];
	ORGAN Liv[20];
	ORGAN Kid[20];
	PatientDetails pat;
	int i=0,j=0,k=0,l=0;
	ORGAN a;
	int q,flag=0;
	int t;
	FILE *f = fopen("Organs.dat","rb+");
	while(fread(&a,sizeof(a),1,f))
	{
		if(strcmp(a.OrganName,"Kidney")==0)
			{
				Kid[i]=a;
				i++;
			}
		else if(strcmp(a.OrganName,"Heart")==0)
			{
				Hea[j]=a;
				j++;
			}
		else if(strcmp(a.OrganName,"Lungs")==0)
			{			
				Lun[k]=a;
				k++;
			}
		else if(strcmp(a.OrganName,"Liver")==0)
			{
				Liv[l]=a;
				l++;
			}
	}
	fclose(f);
	
	while(Liver->size>0)
	{
		flag =0;
		pat = deletemin(Liver);
		for(q=0;q<l;q++)
		{
			if(BLcheck(Liv[q].BloodGroup,pat.BloodGroup)==1)
			{
				dispboth(Liv[q],pat);
				for(t=q;t<l-1;t++)
					Liv[t] = Liv[t+1];
				l--;
				flag = 1;
				break;
			}
		}
		if(flag==0)
		{
			printf("\nNo organ found for Patient: %s\n",pat.Name);
			insert(L,pat);
		}
		if(l<=0)
			break;
	}
	while(L->size>0)
	{
		pat = deletemin(L);
		insert(Liver,pat);
	}





	while(Kidney->size>0)
	{
		flag =0;
		pat = deletemin(Kidney);
		for(q = 0;q<i;q++)
		{
			if(BLcheck(Kid[q].BloodGroup,pat.BloodGroup)==1)
			{
				dispboth(Kid[q],pat);
				for(t=q;t<i-1;t++)
					Kid[t] = Kid[t+1];
				i--;
				flag = 1;
				break;
			}
		}
		if(flag==0)
		{
			printf("\nNo organ found for Patient: %s\n",pat.Name);
			insert(L,pat);
		}
		if(i<=0)
			break;
	}
	while(L->size>0)
	{
		pat = deletemin(L);
		insert(Kidney,pat);
	}



	while(Heart->size>0)
	{
		flag =0;
		pat = deletemin(Heart);

		for(q = 0;q<j;q++)
		{
			if(BLcheck(Hea[q].BloodGroup,pat.BloodGroup)==1)
			{
				dispboth(Hea[q],pat);
				for(t=q;t<j-1;t++)
				{
					Hea[t] = Hea[t+1];
				}
				j--;
				flag = 1;
				break;
			}
		}
		if(flag==0)
		{
			printf("\nNo organ found for Patient: %s\n",pat.Name);
			insert(L,pat);
		}
		if(j<=0)
			break;
	}
	while(L->size>0)
	{
		pat = deletemin(L);
		insert(Heart,pat);
	}



	while(Lungs->size>0)
	{
		flag =0;
		pat = deletemin(Lungs);
		for(q=0;q<k;q++)
		{
			if(BLcheck(Lun[q].BloodGroup,pat.BloodGroup)==1)
			{

				dispboth(Lun[q],pat);
				for(t=q;t<k-1;t++)
				{
					Lun[t] = Lun[t+1];
				}
				k--;
				flag = 1;
				break;
			}
		}
		if(flag==0)
		{
			printf("\nNo organ found for Patient: %s\n",pat.Name);
			insert(L,pat);
		}
		if(k<=0)
			break;
	}
	while(L->size>0)
	{
		pat = deletemin(L);
		insert(Lungs,pat);
	}

	FILE *z = fopen("Organs.dat","wb+"); 
	for(q=0;q<l;q++)
		fwrite(&Liv[q],sizeof(Liv[q]),1,f);
	for(q=0;q<i;q++)
		fwrite(&Kid[q],sizeof(Kid[q]),1,f);
	for(q=0;q<k;q++)
		fwrite(&Lun[q],sizeof(Lun[q]),1,f);
	for(q=0;q<j;q++)
		fwrite(&Hea[q],sizeof(Hea[q]),1,f);
	fclose(z);

}

void dispboth(ORGAN P,PatientDetails A)
{
	printf("\n\nPatient Name:%s\nPatient Blood Group: %s\nOrgan Received:%s\nBloodGroup of donor: %s\n",A.Name,A.BloodGroup,P.OrganName,P.BloodGroup);
}

int BLcheck(char s1[], char s2[])
{
	if(strcmp(s1,s2)==0)
			return 1;
	else if(strcmp(s2,"AB")==0)
			return 1;
	else if(strcmp(s1,"O")==0)
			return 1;
	else
		return 0;
}

void menu(){
	PriorityQ *Liver,*Heart,*Lungs,*Kidney;
	Liver=(PriorityQ *)malloc(sizeof(PriorityQ));
	Heart=(PriorityQ *)malloc(sizeof(PriorityQ));
	Lungs=(PriorityQ *)malloc(sizeof(PriorityQ));
	Kidney=(PriorityQ *)malloc(sizeof(PriorityQ));
		
	initPQ(Liver,20);
	initPQ(Heart,20);
	initPQ(Lungs,20);
	initPQ(Kidney,20);

	int opt,size,n,i;
	PatientDetails e;	
		
	do{		
		printf("\n\t\t\tEMPLOYEE MANAGEMENT SYSTEM\n");
		printf("\n1.Add Patients who need Organs\n2.Donate Organs\n3.Provide Organs to Patients \n4.Display Patient List\n5.Display Organ List\n6.Exit\n\tEnter Your Choice: ");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
					printf("Enter the no of patients you want to add: ");
					scanf("%d",&n);
					for(i = 0; i <n; i++)
					{
						e = Accept();
						if(strcmp(e.Organ,"Liver")==0)
							insert(Liver,e);
						else if(strcmp(e.Organ,"Heart")==0)
							insert(Heart,e);
						else if(strcmp(e.Organ,"Lungs")==0)
							insert(Lungs,e);
						else if(strcmp(e.Organ,"Kidney")==0)
							insert(Kidney,e);
					}
					break;
		
			case 2:	AddOrgan();
					DispOrgans();
					break;

			case 3:	Transplant(Liver,Heart,Lungs,Kidney);
					break;

			case 4:	printf("\n\n\nLiver Patients:\n");
					disp(Liver,1,0);
					printf("\n\n\nHeart Patients:\n");
					disp(Heart,1,0);
					printf("\n\n\nKidney Patients:\n");
					disp(Kidney,1,0);
					printf("\n\n\nLung Patients:\n");
					disp(Lungs,1,0);
					break;

			case 5: DispOrgans();
					break;
			case 6:	exit(0);
					break;
			default:printf("\nInvalid option");
					break;			
		}
	}while(1);
}


void main()
{
	menu();
}



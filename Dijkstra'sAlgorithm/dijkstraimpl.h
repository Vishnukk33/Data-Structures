#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
	int m[100][100];
	int n;
	int vs[100],dist[100];
	char a[100][100],path[100][100];
}cityADT;


int checkpresence(cityADT *c,char s[])
{
	int i;
	for(i=0;i<c->n;i++)
	{
		if(!strcmp(s,c->a[i]))
		return i;
	}
	return -1;
}
cityADT* create(cityADT *c)
{
	int i,j,d;
	char s[100],rep;
	c=(cityADT*)malloc(sizeof(cityADT));
	printf("Enter no of citites : ");
	scanf("%d",&c->n);
	printf("enter the cities\n");
	int n=c->n;
	for(i=0;i<n;i++)
	{	
		scanf(" %s",c->a[i]);
		c->vs[i]=0;
		c->dist[i]=10000;
	}
	for(i=0;i<n;i++)
	{for(j=0;j<n;j++)
	c->m[i][j]=0;}
	for(i=0;i<n;i++)
	{
		printf("Enter Neighbours of %s:\n",c->a[i]);
		printf("Are there any neighbours?y/n : ");
		scanf(" %c",&rep);	
		while(rep=='y')
		{
			scanf("%s",s);
			j=checkpresence(c,s);
			if(j==-1)
			{
				printf("city not recognized\n");
			}
			else
			{	
				printf("city found at : %d \n",j);
				printf("Enter distance between them : ");
				scanf("%d",&d);
				c->m[i][j]=d;
			}
			printf("Are there any more neighbours?y/n : ");	
			scanf(" %c",&rep);
		}
	}	



	return c;
}
void disp(cityADT *c)
{
	int i,j,n=c->n;
	printf("   ");
	for(i=0;i<n;i++)
	{
		printf("\t%d",i);
	}
	printf("\n   ");
	for(i=0;i<n;i++)
	{
		printf("______");
	}
	printf("______\n\n");
	for(i=0;i<n;i++)
	{
		printf("%d |",i);
		for(j=0;j<n;j++)
		{	
			printf("\t");
			printf("%d",c->m[i][j]);
		}printf("   |");
		if(i+1<n)			
		printf("\n\n");
	}
	printf("\n   ");
	for(i=0;i<n;i++)
	{
		printf("______");
	}
	printf("______\n");
}

int unvisited(cityADT *c)
{
	int i,min=10000,pos=-1;

	for(i=0;i<c->n;i++)
	{
		if(c->dist[i]<min&&c->vs[i]==0)
		{
			min=c->dist[i];
			pos=i;
		}
	}
	return pos;
}

int unvisitedNeighbour(cityADT *c,int x)
{
	int i;
	for(i=0;i<c->n;i++)
	{
		if(c->vs[i]==0&&c->m[x][i]>=1)
		return i;
	}
	return -1;
}
void visit(cityADT *c,int x)
{
	c->vs[x]=1;
}
void reset(cityADT *c)
{
	int j;
	for(j=0;j<c->n;j++)
	{
		c->dist[j]=10000;
		c->vs[j]=0;
	}
}

void DijkstraAlgo(cityADT *c,char start[100]) 
{
  	int x, z, y;
  	int i,temp[100];
  	for(x=0;x<c->n;x++)
	{
		if(!strcmp(start,c->a[x]))
		break;
	}
	if(x==c->n)
	{
		printf("no match for source\n");
		return;
	}
	c->dist[x]=0;
  	while(unvisited(c)!=-1) 
	{	
		z=unvisited(c);
		visit(c,z);
		for(i=0;i<c->n;i++)
		{
			temp[i]=c->vs[i];
		}
				
		while(unvisitedNeighbour(c,z)!=-1)
		{	
			y=unvisitedNeighbour(c,z);
			visit(c,y);
			if(c->dist[z]+c->m[z][y] < c->dist[y])
			{
				c->dist[y]=c->dist[z]+c->m[z][y];
				strcpy(c->path[y],c->a[z]);
			}
		}
		for(i=0;i<c->n;i++)
		{
			c->vs[i]=temp[i];
			printf("%-10s \t %d \t %d \t %s \n",c->a[i],c->vs[i],c->dist[i],c->path[i]);
		}
		printf("\n");
	}
}
void dispath(cityADT *c,char s[100],char d[100])
{
	if(!strcmp(s,d))
	{
		printf("%s ->",d);
		return;
	}
	dispath(c,s,c->path[checkpresence(c,d)]);
	printf("%s ->",d);
}
void shortestPath(cityADT *c,char s[100],char d[100]) 
{
	int x, z, y;
  	int i,temp[100];
  	for(x=0;x<c->n;x++)
	{
		if(!strcmp(s,c->a[x]))
		break;
	}
	if(x==c->n)
	{
		printf("no match for source\n");
		return ;
	}
	c->dist[x]=0;
  	while(unvisited(c)!=-1) 
	{	
		z=unvisited(c);
		visit(c,z);
		for(i=0;i<c->n;i++)
		{
			temp[i]=c->vs[i];
		}
				
		while(unvisitedNeighbour(c,z)!=-1)
		{	
			y=unvisitedNeighbour(c,z);
			visit(c,y);
			if(c->dist[z]+c->m[z][y] < c->dist[y])
			{
				c->dist[y]=c->dist[z]+c->m[z][y];
				strcpy(c->path[y],c->a[z]);
			}
		}
		for(i=0;i<c->n;i++)
		{
			c->vs[i]=temp[i];
		}
		printf("\n");
	}
	char q[100];
	strcpy(q,d);
	dispath(c,s,d);
}

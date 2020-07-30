
int isFull(Stack *S)
{
	if((S->top)==S->limit-1)
		return 1;
	else
		return 0;
}

int isEmpty(Stack *S)
{
	if((S->top)==-1)
		return 1;
	else
		return 0;
}

void initialize(Stack *S,int n)
{
	S->top = -1;
	//printf("Enter the limit: ");
	//scanf("%d",&(S->limit));
	S->limit = n;
}

void push(Stack *S, char x)
{
	if(isFull(S))
		printf("\nStack overflow\n");
	else 
	{
		S->top+=1;
		S->a[S->top]=x;
		//printf("\n %d is pushed into the stack\n",x);	
	}
}

char pop(Stack *S)
{

	if(isEmpty(S))
		printf("\nStack undeflow\n");
	else
	{
		S->top-=1;
		return S->a[S->top+1];
	}
	return '0';
}

void disp(Stack *S)
{
	int i;
	if(isEmpty(S))
		printf("\nStack is empty\n");
	else
	{	i = S->top;
		while(i>(-1))
		{
			printf("%c\n",S->a[i]);
			i-=1;
		}
	}
}
int peek(Stack *S)
{
	return S->a[S->top];
}

void size(Stack *S)
{
	printf("\nThe size of the stack is: %d\n",S->top+1);
}



#include"stackif.h"
#include"stackimpl.h"

int prec(Stack *s,char p)
{
	if(s->top==-1)
		return 0;
	else if((p=='^')&&(s->a[s->top]!='^'))
		return 0;
	else if(((p=='*')||(p=='/'))&&((s->a[s->top]=='+')||(s->a[s->top]=='-')))
		return 0;
	else 
		return 1;
}


char *inftopos(char s1[25])
{
	Stack S;
	initialize(&S);
	int x;
	char l;
	char *s2;
	s2 = (char*)malloc(25*sizeof(char));
	int i,j=0;
	for(i=0;s1[i]!='\0';i++)
	{
		if(isdigit(s1[i]))
		{
			s2[j] = s1[i];
			j++;
		}
		else 
		{
			do
			{	
				x = (prec(&S,s1[i]));
				if(x==0)
				{
					push(&S,s1[i]);
				}
				else 
				{
					l=pop(&S);
					s2[j]=l;
					j++;
				}
			}while(x!=0);
		}
	}
	while((S.top)!=-1)
	{
		l=pop(&S);
		s2[j]=l;
		j++;
	}	
	s2[j]='\0';
	return s2;
}

float eval(char y[25])
{
	int i,j=0;
	Stack S;
	initialize(&S);
	float temp[25],l1,l2;
	for(i=0;y[i]!='\0';i++)
	{
		if(isdigit(y[i]))
		{	
			temp[j]=y[i]-'0';
			j++;
		}
		else
		{
			l1 = temp[j-2];
			l2 = temp[j-1];
			j = j-2;
			switch(y[i])
			{
				case '+':
					temp[j] = l1+l2;
					j++;
					break;
				case '-':
					temp[j] = l1-l2;
					j++;
					break;
				case '*':
					temp[j] = l1*l2;
					j++;
					break;
				case '/':
					temp[j] = l1/l2;
					j++;
					break;
				case '^':
					temp[j] = pow(l1,l2);
					j++;
					break;
			}
		}
	}
	return temp[j-1];
}

void main()
{
	char *s1;
	s1 = (char*)malloc(25*sizeof(char));
	char *s2;
	s2 = (char*)malloc(25*sizeof(char));
	printf("Enter the infix expression to be converted and then evaluated: ");
	scanf(" %[^\n]",s1);
	s2 = inftopos(s1);
	printf("\n\nPostfix expression is %s\n",s2);

	printf("The expression is evaluated to  = %.3f\n\n",eval(s2));

}
/*OUTPUT:
cs1200@jtl-30:~/Desktop/C/Infixpostfix$ gcc infixposfixv2.c -o l -lm
cs1200@jtl-30:~/Desktop/C/Infixpostfix$ ./l
Enter the infix expression to be converted and then evaluated: 2*1-1+4-3

 * is pushed into the stack

 - is pushed into the stack

 + is pushed into the stack

 - is pushed into the stack


Postfix expression is 21*1-4+3-
The expression is evaluated to  = 2.000
*/

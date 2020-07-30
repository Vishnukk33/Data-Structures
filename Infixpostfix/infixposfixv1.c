#include"stackif.h"
#include"stackimpl.h"

void main()
{
	Stack S;
	
	initialize(&S);
	while(1)
	{
		int c;
		char x,t;
		printf("\t\tStack program\n\n1.push\n2.pop\n3.disp\n4.size\n5.Check if Full\n6.Check if Empty\n7.exit\n");
		printf("\nChoose your option: ");
		scanf("%d",&c);
		switch(c)
		{
			case 1: 	
				printf("Enter element to be pushed: ");
				scanf(" %c",&x);
				push(&S,x);
				break;

			case 2:	
				t = pop(&S);
				if(t!='0')
					printf("\n%c is popped\n",t);
				break;

			case 3: disp(&S);
					break;

			case 4: size(&S);
					break;

			case 5: if(isFull(&S))
						printf("\nStack is full\n");
					else
						printf("\nStack not full \n");
					break;
			case 6: if(isEmpty(&S))
					printf("\nStack is empty\n");
				else
					printf("\nStack is not empty\n");
				break;
			case 7:exit(0);
			default: 
					
			exit(0);
		}
	}
}	
/*OUTPUT:
cs1200@jtl-30:~/Desktop/C/Infixpostfix$ gcc infixposfixv1.c -o l
cs1200@jtl-30:~/Desktop/C/Infixpostfix$ ./l
Enter the limit: 3
		Stack program

1.push
2.pop
3.disp
4.size
5.Check if Full
6.Check if Empty
7.exit

Choose your option: 1
Enter element to be pushed: g

 g is pushed into the stack
		Stack program

1.push
2.pop
3.disp
4.size
5.Check if Full
6.Check if Empty
7.exit

Choose your option: 1
Enter element to be pushed: 6

 6 is pushed into the stack
		Stack program

1.push
2.pop
3.disp
4.size
5.Check if Full
6.Check if Empty
7.exit

Choose your option: 1
Enter element to be pushed: d

 d is pushed into the stack
		Stack program

1.push
2.pop
3.disp
4.size
5.Check if Full
6.Check if Empty
7.exit

Choose your option: 3
d
6
g
		Stack program

1.push
2.pop
3.disp
4.size
5.Check if Full
6.Check if Empty
7.exit

Choose your option: 2

d is popped
		Stack program

1.push
2.pop
3.disp
4.size
5.Check if Full
6.Check if Empty
7.exit

Choose your option: 3
6
g
		Stack program

1.push
2.pop
3.disp
4.size
5.Check if Full
6.Check if Empty
7.exit

Choose your option: 2

6 is popped
		Stack program

1.push
2.pop
3.disp
4.size
5.Check if Full
6.Check if Empty
7.exit

Choose your option: 3
g
		Stack program

1.push
2.pop
3.disp
4.size
5.Check if Full
6.Check if Empty
7.exit

Choose your option: 4

The size of the stack is: 1
		Stack program

1.push
2.pop
3.disp
4.size
5.Check if Full
6.Check if Empty
7.exit

Choose your option: 5

Stack not full 
		Stack program

1.push
2.pop
3.disp
4.size
5.Check if Full
6.Check if Empty
7.exit

Choose your option: 6

Stack is not empty
		Stack program

1.push
2.pop
3.disp
4.size
5.Check if Full
6.Check if Empty
7.exit

Choose your option: 2

g is popped
		Stack program

1.push
2.pop
3.disp
4.size
5.Check if Full
6.Check if Empty
7.exit

Choose your option: 3

Stack is empty
		Stack program

1.push
2.pop
3.disp
4.size
5.Check if Full
6.Check if Empty
7.exit

Choose your option: 2

Stack undeflow
		Stack program

1.push
2.pop
3.disp
4.size
5.Check if Full
6.Check if Empty
7.exit

Choose your option: 2

Stack undeflow
		Stack program

1.push
2.pop
3.disp
4.size
5.Check if Full
6.Check if Empty
7.exit

Choose your option: 2

Stack undeflow
		Stack program

1.push
2.pop
3.disp
4.size
5.Check if Full
6.Check if Empty
7.exit

Choose your option: 3

Stack is empty
		Stack program

1.push
2.pop
3.disp
4.size
5.Check if Full
6.Check if Empty
7.exit

Choose your option: 7
*/

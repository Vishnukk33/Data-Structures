#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
typedef struct 
{
	char a[100];
	int top;
	int limit;
}Stack;

int isFull(Stack *S);
int isEmpty(Stack *S);
void initialize(Stack *S,int n);
void push(Stack *S, char x);
char pop(Stack *S);
void disp(Stack *S);
void size(Stack *S);

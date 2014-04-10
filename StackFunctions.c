/// ********** This source code is to clarify how the stack works **********//
/// ********** The source code has been prepared for DataStructure course, Biomedical Engineering, Cairo University **********//
/// ********** Author: Ahmed Abdelhadi **********//

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 5
int top=-1;

void push (int* stack, int value);
void StackTraverse (int* stack);
int pop (int* stack);

int main ()
{
	printf("Hello \n");
	
	int stack[MaxSize];
	int data;
	
	push (stack, 4);
	StackTraverse(stack);
	printf("\n\n");
	
	push (stack, 5);
	StackTraverse(stack);
	printf("\n\n");
	
	data= pop(stack);
	StackTraverse(stack);
	printf("\n\n");
	
	data= pop(stack);
	StackTraverse(stack);
	printf("\n\n");
	
}

/// add new element to the stack "add from the top"
void push (int* stack, int value)
{
	if (top+1 >= s)
		printf("Error: stack full \n");
	else
		stack[++top] = value;
}



/// remove element out of the stack "remove from the top"
int pop (int* stack)
{
	if (top<0)
		printf("Error: stack empty \n");
	else
	{
		return stack[top--];
	}
}



/// print all stack elements 
void StackTraverse (int* stack)
{
	int temp=top;
	
	if (top<0)
		printf("Error: stack empty \n");
	else
	{
		while (temp > -1)
		{
			printf("stack[%d]=%d\n", temp, stack[temp]);
			temp--;
		}
	}
}



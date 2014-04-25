/// ********** Check Parentheses using Stack data structure **********//
/// ********** The source code has been prepared for DataStructure course, Biomedical Engineering, Cairo University **********//
/// ********** Author: Ahmed Abdelhadi **********///

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
int top=-1;

void push (char* stack, char value);
char pop (char* stack);

int main ()
{
	printf("Enter the equation, Hint: The maximum elements shouldn't exceed 50\n");

	char stack[MaxSize];
	char data;
	
	char word[50];
	scanf("%s", word);
	
	int i=0;
	while(word[i]!=NULL)
	{
		if (word[i]=='(')
			push(stack, word[i]);
		else if(word[i]==')')
			pop(stack);
		
		i++;
	}
	
	if (top>-1)
		printf("There are opened parentheses that haven't closed\n");
	else if(top==-1)
		printf("the parentheses are OK\n");
}


/// add new element to the stack "add from the top"
void push (char* stack, char value)
{
	if (top+1 >= MaxSize)
		printf("Error: stack full \n");
	else
		stack[++top] = value;
}

/// remove element out of the stack "remove from the top"
char pop (char* stack)
{
	if (top<0)
	{
		printf("There are closed parentheses that haven't opened\n");
		exit(0);
	}
	else
	{
		return stack[top--];
	}
}

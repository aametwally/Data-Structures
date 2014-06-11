///**********************************************************************///
///******     	   			Stack using LinkedList	      	 	   ******///
///******  		  Title: Push, Pop, and Traverse Functions		   ******///
///******                  			                 		 	   ******///
///******  		     	 [DataStructure Course, 2014]  			   ******///
///******		   Biomedical Engineering, Cairo University	 	   ******///
///**********************************************************************///
///*                                                             	    *///
///*   		  	 	Copyright by Ahmed Abdelhadi (C) 2014  	   	  	    *///
///*                                                               		*///
///*              	 Please report bugs & suggestions to              	*///
///*                   <ahmed.abdelhady@eng.cu.edu.eg>               	*///
///**********************************************************************///

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	node* next;
	
};

void push(int value);
int pop();
void StackTraverse(node* head);

node* head=NULL;


int main ()
{	
	int data;
	
	push (4);
	StackTraverse(head);
	printf("\n\n");
	
	push (5);
	StackTraverse(head);
	printf("\n\n");
	
	data= pop();
	StackTraverse(head);
	printf("\n\n");
	
	data= pop();
	StackTraverse(head);
	printf("\n\n");
	
}

/// This method creates a node and prepends it at the beginning of the list 
void push(int value)
{
	node* newNode=(node*)malloc(sizeof(node));
	newNode->next=head;
	head=newNode;
	newNode->data=value;
}



/// This method deletes the first node of the list
int pop()
{
	// test if the list is empty
	if (head==NULL)
	{
		printf("the list is empty\n");
		exit(1);
	}
	
	node* temp=head;
	
	head=temp->next;
	int data=temp->data;
	free(temp);
	 
}


/// This method traverse all nodes of linked list and print their values 
void StackTraverse(node* head)
{
	node* temp=head;
	while (temp!=NULL)
	{
		printf("Value=%d\n",temp->data);
		temp=temp->next;
	}
}


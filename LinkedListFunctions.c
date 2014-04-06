/// ********** This source code is to chow the main functions of Linked list **********//
/// ********** The source code has been prepared for DataStructure course, Biomedical Engineering, Cairo University **********//
/// ********** Author: Ahmed Abdelhadi **********//

#include <stdio.h>
#include <stdlib.h>


struct node
{
	int data;
	node* next;
	
};

void Traverse(node* head);
node* AddNodeFront(node* head, int value);
void AddNodeEnd(node* head, int value);
void AddNodeAfter(node* head, int n, int value);
node* DelNodeFront(node* head);
void DelNodeEnd(node* head);
void DelNodeAfter(node* head, int n);


int main ()
{
	node* head=NULL;
	
	head=AddNodeFront(head,10);
	Traverse(head);
	printf("\n\n");
	
	
	head=AddNodeFront(head,20);
	Traverse(head);
	printf("\n\n");
	
	head=AddNodeFront(head,30);
	Traverse(head);
	printf("\n\n");
	
	AddNodeEnd(head,40);
	Traverse(head);
	printf("\n\n");
	
	AddNodeAfter(head, 10, 50);
	Traverse(head);
	printf("\n\n");
	
	head=DelNodeFront(head);
	Traverse(head);
	printf("\n\n");
	
	
	DelNodeAfter(head, 2);
	Traverse(head);
	printf("\n\n");
	
	DelNodeEnd(head);
	Traverse(head);
	printf("\n\n");
}


/// This method traverse all nodes of linked list and print their values 
void Traverse(node* head)
{
	node* temp=head;
	while (temp!=NULL)
	{
		printf("Value=%d\n",temp->data);
		temp=temp->next;
	}
}


/// This method creates a node and prepends it at the beginning of the list 
node* AddNodeFront(node* head, int value)
{
	node* newNode=(node*)malloc(sizeof(node));
	newNode->next=head;
	head=newNode;
	newNode->data=value;
	return head;
}


/// This method creates a node and prepends it at the end of the list
void AddNodeEnd(node* head, int value)
{
	node* temp=head;
	while (temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=(node*)malloc(sizeof(node));
	temp=temp->next;
	temp->data=value;
}



/// This method creates a node after n nodes of the list
void AddNodeAfter(node* head, int n, int value)
{
	node* temp=head;
	for (int i=0; i< n-1; i++)
	{
		if (temp == NULL)
		{
			printf ("Add new node failed because the list is shorter than %d elements\n", n);
			exit(1);
		}
		temp=temp->next;
	}
	node* newNode=(node*)malloc(sizeof(node));
	newNode->next=temp->next;
	temp->next=newNode;
	newNode->data=value;
}


/// This method deletes the first node of the list
node* DelNodeFront(node* head)
{
	// test if the list is empty
	if (head==NULL)
	{
		printf("the list is empty");
		exit(1);
	}
	
	node* temp=head;
	head=temp->next;
	free(temp);
	return head;
	 
}


/// This method deletes the last node of the list
void DelNodeEnd(node* head)
{
	// test if the list is empty
	if (head==NULL)
	{
		printf("the list is empty");
		exit(1);
	}
	node* temp=head;
	while ((temp->next)->next!=NULL)
	{
		temp=temp->next;
	}
	free(temp->next);
	temp->next=NULL;
}


/// This method deletes the a node after n nodes of the list
void DelNodeAfter(node* head, int n)
{
	node* temp=head;
	for (int i=0; i< n-1; i++)
	{
		if (temp == NULL)
		{
			printf ("Delete node failed because the list is shorter than %d elements\n", n);
			exit(1);
		}
		temp=temp->next;
	}
	
	node* deleteNode=temp->next;
	temp->next=(temp->next)->next;
	free(deleteNode);
}

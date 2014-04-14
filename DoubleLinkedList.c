/// ********** Doubly Linked list Functions **********//
/// ********** The source code has been prepared for DataStructure course, Biomedical Engineering, Cairo University **********//
/// ********** Author: Ahmed Abdelhadi **********//

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	node* next;
	node* previous;
	
};

void ForwardTraverse(node* head);
void ReverseTraverse(node* head);
node* AddNodeFront(node* head, int value);
void AddNodeEnd(node* head, int value);
void AddNodeAfter(node* head, int n, int value);
node* DelNodeFront(node* head);
void DelNodeEnd(node* head);
void DelNodeAfter(node* head, int n);


int main ()
{
	node* head=NULL;
	
	printf("Step #1: Add 10 from Front\n");
	head=AddNodeFront(head,10);
	ForwardTraverse(head);
	printf("\n\n");
	ReverseTraverse(head);
	printf("\n\n");
	
	printf("Step #2: Add 20 from Front\n");
	head=AddNodeFront(head, 20);
	ForwardTraverse(head);
	printf("\n\n");
	ReverseTraverse(head);
	printf("\n\n");
	
	
	printf("Step #3: Add 30 from End\n");
	AddNodeEnd(head,30);
	ForwardTraverse(head);
	printf("\n\n");
	ReverseTraverse(head);
	printf("\n\n");
	
	
	printf("Step #4: Add 40 from End\n");
	AddNodeEnd(head,40);
	ForwardTraverse(head);
	printf("\n\n");
	ReverseTraverse(head);
	printf("\n\n");
	
	
	printf("Step #5: Add 50 after 2 nodes\n");
	AddNodeAfter(head, 2, 50);
	ForwardTraverse(head);
	printf("\n\n");
	ReverseTraverse(head);
	printf("\n\n");
	
	printf("Step #5: Add 60 after 4 nodes\n");
	AddNodeAfter(head, 4, 60);
	ForwardTraverse(head);
	printf("\n\n");
	ReverseTraverse(head);
	printf("\n\n");
	

	printf("Step #6: delete node from Front\n");
	head=DelNodeFront(head);
	ForwardTraverse(head);
	printf("\n\n");
	ReverseTraverse(head);
	printf("\n\n");
	
	printf("Step #7: delete node after 2 nodes\n");
	DelNodeAfter(head, 2);
	ForwardTraverse(head);
	printf("\n\n");
	ReverseTraverse(head);
	printf("\n\n");
	
	
	printf("Step #8: delete node from End\n");
	DelNodeEnd(head);
	ForwardTraverse(head);
	printf("\n\n");
	ReverseTraverse(head);
	printf("\n\n");
}


/// This method traverse all nodes of linked list and print their values 
void ForwardTraverse(node* head)
{
	node* temp=head;
	while (temp!=NULL)
	{
		printf("ForwardTraverse=%d\n",temp->data);
		temp=temp->next;
	}
}

void ReverseTraverse(node* head)
{
	node* temp=head;
	while (temp->next!=NULL)
	{
		temp=temp->next;
	}
	while (temp!=NULL)
	{
		printf("ReverseTraverse=%d\n",temp->data);
		temp=temp->previous;
	}
	
}



/// This method creates a node and prepends it at the beginning of the list 
node* AddNodeFront(node* head, int value)
{
	node* newNode=(node*)malloc(sizeof(node));
	newNode->next=head;
	
	if (head!=NULL)
	head->previous =newNode;
	
	head=newNode;
	newNode->data=value;
	newNode->previous=NULL;
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
	node* newNode=(node*)malloc(sizeof(node));
	temp->next=newNode;
	newNode->previous=temp;
	newNode->data=value;
	newNode->next=NULL;
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
	newNode->previous=temp;
	newNode->data=value;
	(newNode->next)->previous=newNode;
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
	head->previous=NULL;
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
	(temp->next)->previous=temp;
	free(deleteNode);
}



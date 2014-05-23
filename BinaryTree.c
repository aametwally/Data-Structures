/// ********** Binary Tree Functions **********//
/// ********** The source code has been prepared for DataStructure course, Biomedical Engineering, Cairo University **********//
/// ********** Author: Ahmed Abdelhadi **********//

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 20

/// Binary tree node 
struct bt_node
{
	int data;
	struct bt_node *lchild;
	struct bt_node *rchild;
};


int front= -1;
int rear= -1;
bt_node* queue[MaxSize];
struct bt_node *root=NULL;

bt_node* allocateNewNode();
void binaryTreeInsert(int value);
void preOrderTraversal(struct bt_node *node);
void inOrderTraversal(struct bt_node *node);
void postOrderTraversal(struct bt_node *node);
void breadthTraversal(struct bt_node *tree);

bt_node* delQueue ();
void addQueue (bt_node* value);

int main ()
{
	binaryTreeInsert(4);
	binaryTreeInsert(2);
	binaryTreeInsert(7);
	binaryTreeInsert(10);
	binaryTreeInsert(5);
	binaryTreeInsert(0);
	binaryTreeInsert(3);
	binaryTreeInsert(-5);
	binaryTreeInsert(1);
	
	printf(" Preorder Traversal :\n");
	preOrderTraversal(root);
	
	printf("\n Inorder Traversal:\n");
	inOrderTraversal(root);
	
	printf("\n Postorder Traversal:\n");
	postOrderTraversal(root);
	
	printf("\n Breadth Traversal:\n");
	breadthTraversal(root);
}



/// Function to Traverse the Binary tree using Pre-Order Traversal Technique 
void preOrderTraversal(struct bt_node *node)
{
	if (node != NULL)
	{
		printf("%d\n",node->data);
		preOrderTraversal(node->lchild);
		preOrderTraversal(node->rchild);
	}
}
  
/// Function to Traverse the Binary tree using In-Order Traversal Technique 
void inOrderTraversal(struct bt_node *node)
{
	if (node != NULL)
	{
		inOrderTraversal(node->lchild);
		printf("%d\n",node->data);
		inOrderTraversal(node->rchild);
	}
} 
  
/// Function to Traverse the Binary tree using Post-Order Traversal Technique 
void postOrderTraversal(struct bt_node *node)
{
	if (node != NULL)
	{

		postOrderTraversal(node->lchild);
		postOrderTraversal(node->rchild);
		printf("%d\n",node->data);
	}
} 

/// Function to Traverse the Binary tree using Breadth-First Traversal Technique 
void breadthTraversal(struct bt_node *tree)
{
	struct bt_node *t;
	addQueue(tree);
	while ((t=delQueue())!=NULL)
	{
		printf("%d\n",t->data);
		if (t->lchild !=NULL)
			addQueue(t->lchild);
		if (t->rchild !=NULL)
			addQueue(t->rchild);
	}
}

/// Insert New Node in Binary Tree
void binaryTreeInsert(int value)
{
	struct bt_node *p,*q;
	
	if(root==NULL)
	{
		root=allocateNewNode();
		root->data=value;
		return;
	}
	
	p=root;
	while (p!=NULL)
	{
		q=p;
		if (value < (p->data))
			p=p->lchild;
		else
			p=p->rchild;
	}
	
	/* Now, 'q' points to parent of new node */
	
	p=allocateNewNode();
	p->data=value;
	if (value < (q->data))
		q->lchild=p;
	else
		q->rchild=p;
}


/// Allocate new Binary Tree Node
bt_node* allocateNewNode()
{
	struct bt_node *newnode;
	newnode=(struct bt_node *) malloc (sizeof(struct bt_node));
	newnode->lchild= NULL;
	newnode-> rchild=NULL;
	return(newnode);
}



///******************************************************
/// Queue Funtcions: The delQueue and addQueue functions will be used in Breadth First Traversal.

/// add new element to the queue
void addQueue (bt_node* value)
{
	if (rear+1 >= MaxSize)
		printf("Error: queue full \n");
	else
		queue[++rear] = value;
}



/// remove element out of the queue
bt_node* delQueue ()
{
	if (front == rear)
	{
		printf("Error: queue empty \n");
		exit(1);
	}
	else
	{
		return queue[++front];
	}
}

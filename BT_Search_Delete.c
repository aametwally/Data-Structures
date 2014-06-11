///*****************************************************************///
///********    			Binary Tree     	    ********///
///********    	    Title: Search and Delete Functions      ********///
///********                  			            ********///
///********  	       [DataStructure Course, 2014]  	    ********///
///********	Biomedical Engineering, Cairo University    ********///
///*****************************************************************///
///*                                                               *///
///*   		 Copyright by Ahmed Abdelhadi (C) 2014  	   *///
///*                                                               *///
///*              Please report bugs & suggestions to:             *///
///*                <ahmed.abdelhady@eng.cu.edu.eg>                *///
///*****************************************************************///

#include <stdio.h>
#include <stdlib.h>


/// Binary tree node 
struct bt_node
{
	int data;
	struct bt_node *lchild;
	struct bt_node *rchild;
};


/// Structure used to gather the return values of the search function 
struct Parent_Child_Status
{
	struct bt_node* parent; /// the address of the partent of the target node
	struct bt_node* child;  /// the address of the target node
	char status; /// left or right 
};


bt_node* allocateNewNode();
void insertNodeBinaryTree(int value);
Parent_Child_Status* searchNodeBinaryTree (bt_node *root, int key);
int deleteNodeBinaryTree(struct bt_node *parent, struct bt_node *node, char status);
void insertExistingTreeToBinaryTree(bt_node* node);
void inOrderTraversal(struct bt_node *node);

bt_node *root=NULL;


int main ()
{	
	/// Build a binary tree to test the search and delete function
	insertNodeBinaryTree(10);
	insertNodeBinaryTree(100);
	insertNodeBinaryTree(-50);
	insertNodeBinaryTree(3);
	insertNodeBinaryTree(-70);
	insertNodeBinaryTree(1);
	insertNodeBinaryTree(8);
	insertNodeBinaryTree(-80);
	insertNodeBinaryTree(-60);
	insertNodeBinaryTree(16);
	
	
	/// In-Order Traversal
	printf("\nInorder Traversal:\n");
	inOrderTraversal(root);
	printf("\n\n");

	
	Parent_Child_Status* SearchReturnValues;
	int key;
	
	printf("Enter the Value that you want to search for\n");
	scanf("%d",&key);
	
	/// Test Search Function
	SearchReturnValues = searchNodeBinaryTree(root, key);
	if(SearchReturnValues->child != NULL)
	printf("\nSearch Results: (%d) is found in the tree in address=%p, Its Parent in =%p, Orientation=%c\n", key, SearchReturnValues->child, SearchReturnValues->parent, SearchReturnValues->status);
	
	
	/// Test Delete function: delete the same node that we have searched for in the last line 
	deleteNodeBinaryTree(SearchReturnValues->parent, SearchReturnValues->child, SearchReturnValues->status);
	
	
	/// In-Order Traversal
	printf("\nInorder Traversal:\n");
	inOrderTraversal(root);
	printf("\n\n");
	
}


/// *********************************************************************** 
/// Search for a certain node in an existing Binary Tree. 
/// If the target node exists, the function returns the address of the target, the address of its parent, and weather the node is located on right side of left side of the parent
Parent_Child_Status* searchNodeBinaryTree (bt_node *root, int key)
{
	bt_node* temp=root;
	
	/// allocate space for the return value structure which contains the needed info "Paren, Child, Status"
	Parent_Child_Status* ReturnValues=(Parent_Child_Status*)malloc(1*sizeof(Parent_Child_Status));


	/// initialize the Return Values
	ReturnValues->parent = NULL;
	ReturnValues->child = NULL;
	ReturnValues->status = '-';
	
	/// Exit the function if the root points to NULL 
	if (root == NULL)
	{
		printf("There is no tree\n");
		return ReturnValues;
	}
	else
	{
		while (temp != NULL)
		{
			if (key == (temp->data))
			{
				ReturnValues->child = temp;
				return ReturnValues;
				
			}
			else if (key > (temp->data))
			{
				ReturnValues->parent = temp;
				ReturnValues->status = 'r';
				temp = temp->rchild;
				
			}
			else if (key < (temp->data))
			{
				ReturnValues->parent = temp;
				ReturnValues->status = 'l';
				temp = temp->lchild;
			}

		}
		
		if (temp == NULL)
		{
			ReturnValues->child = temp;
			printf("%d is not found in the tree\n", key);
			return ReturnValues;
		}
	}
	
}


/// *********************************************************************** 
/// Delete Node from a Binary Tree
int deleteNodeBinaryTree(bt_node *parent, bt_node *node, char status)
{
	bt_node* child;
	
	
	/// exit the function if there is no tree
	if (node==NULL)
	return 0;
	
	
	/// Case 1: Delete the Leaf
	if ( (node->lchild == NULL) && (node->rchild == NULL) )
	{
		printf("\n Deletion Case 1\n");
		child=NULL; 
	}
	
	/// Case 2: Delete node that its left child is NULL 
	else if (node->lchild == NULL)
	{
		printf("\n Deletion Case 2");
		child=node->rchild;
	}

	/// Case 3: Delete node that its right child is NULL
	else if (node->rchild == NULL)
	{
		printf("\n Deletion Case 3");
		child=node->lchild;
	}
 
	/// Case 4: Delete node that the right child of its left child is NULL
	else if (node->lchild->rchild==NULL)
	{
		printf("\n Deletion Case 4");
		child=node->lchild;
		node->lchild->rchild=node->rchild;
	}

	/// Case 5: Delete node that the left child of its right child is NULL
	else if (node->rchild->lchild==NULL)
	{
		printf("\n Deletion Case 5");
		child=node->rchild;
		node->rchild->lchild=node->lchild;
	}
	
	/// Case 6: Delete the root
	else if (parent == NULL)
	{
		printf("\n Deletion Case 6");
		root = node->rchild;
		child = node->lchild;
		free(node);
		insertExistingTreeToBinaryTree(child);
		return 1;
	}
	
	/// Case 7: Otherwise
	else
	{
		printf("\n Deletion Case 7");
		child = node->rchild;
		if (status == 'l')
			parent->lchild = node->rchild;
		else
			parent->rchild = node->lchild;
		
		free(node);
		insertExistingTreeToBinaryTree(node->lchild);	
		return 1;	
	}
	
	
	/// Adjust the parent pointer and free the deleted node
	if (status == 'l')
		parent->lchild = child;
	else
		parent->rchild = child;
		
	free(node);
	return(1);
	
}



/// *********************************************************************** 
/// Insert an existing Binary Tree to another existing Binary Tree.
/// This function is used for case 6,7 in deleteNodeBinaryTree Function.
void insertExistingTreeToBinaryTree(bt_node* node)
{
	if (node != NULL)
	{
		/// insert nodes using Post Order method
		insertExistingTreeToBinaryTree(node->lchild);
		insertExistingTreeToBinaryTree(node->rchild);
		
		
		/// We can declare p and q globally to reduce memory consumption.
		struct bt_node *p,*q;
	
		
		p=root;
		while (p!=NULL)
		{
			q=p;
			if (node->data < (p->data))
				p=p->lchild;
			else
				p=p->rchild;
		}
		
		/* Now, 'q' points to parent of new node */
		
		if (node->data < (q->data))
			q->lchild=node;
		else
			q->rchild=node;
		
		
		node->lchild=NULL;
		node->rchild=NULL;
	}
}




/// *********************************************************************** 
/// Allocate new Binary Tree Node
bt_node* allocateNewNode()
{
	struct bt_node *newnode;
	newnode=(struct bt_node *) malloc (sizeof(struct bt_node));
	newnode->lchild= NULL;
	newnode-> rchild=NULL;
	return(newnode);
}


/// *********************************************************************** 
/// Insert New Node in Binary Tree
void insertNodeBinaryTree(int value)
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


/// *********************************************************************** 
/// Function to Traverse the Binary tree using In-Order Traversal Technique 
void inOrderTraversal(struct bt_node *node)
{
	if (node != NULL)
	{
		inOrderTraversal(node->lchild);
		printf("%d  ",node->data);
		inOrderTraversal(node->rchild);
	}
} 

///**********************************************************************///
///******     	   		Circular Queue     	 	   ******///
///******  Title: Insert, Traverse, Delete, and GetSize Functions  ******///
///*****			               		 	   ******///
///*****	    	 [DataStructure Course, 2014]  		   ******///
///*****	  Biomedical Engineering, Cairo University	   ******///
///**********************************************************************///
///*                                                            	*///
///*     	   Copyright by Ahmed Abdelhadi (C) 2014  	        *///
///*                                                          		*///
///*                Please report bugs & suggestions to              	*///
///*                  <ahmed.abdelhady@eng.cu.edu.eg>               	*///
///**********************************************************************///

#include <stdio.h>
#include <stdlib.h>


/// here, we increment the needed maximum size to work as needed.
/// here the maximum size is 5, but we put it here equal 6 to work will with this implementation.
#define MaxSize 5+1


/// initialization of front and rear with 0
/// note that the first index to insert in is 1.
int front= 0;
int rear= 0;

void cirAddQueue (int* queue, int value);
void cirQueueTraverse (int* queue);
int cirDelQueue (int* queue);
int cirQueueSize();

int main ()
{
	int queue[MaxSize];
	int data;
	

	cirAddQueue (queue, 4);
	cirQueueTraverse(queue);
	printf("Queue Size=%d \n", cirQueueSize());
	printf("\n\n");


	cirAddQueue (queue, 8);
	cirQueueTraverse(queue);
	printf("Queue Size=%d \n", cirQueueSize());
	printf("\n\n");
	
	cirAddQueue (queue, 9);
	cirQueueTraverse(queue);
	printf("Queue Size=%d \n", cirQueueSize());
	printf("\n\n");
	
	cirAddQueue (queue, 9);
	cirQueueTraverse(queue);
	printf("Queue Size=%d \n", cirQueueSize());
	printf("\n\n");
	
	cirAddQueue (queue, 9);
	cirQueueTraverse(queue);
	printf("Queue Size=%d \n", cirQueueSize());
	printf("\n\n");

	data= cirDelQueue(queue);
	cirQueueTraverse(queue);
	printf("Queue Size=%d \n", cirQueueSize());
	printf("\n\n");
	
	data= cirDelQueue(queue);
	cirQueueTraverse(queue);
	printf("Queue Size=%d \n", cirQueueSize());
	printf("\n\n");

		
	
	data= cirDelQueue(queue);
	cirQueueTraverse(queue);
	printf("Queue Size=%d \n", cirQueueSize());
	printf("\n\n");	
	
	
	cirAddQueue (queue, 4);
	cirQueueTraverse(queue);
	printf("Queue Size=%d \n", cirQueueSize());
	printf("\n\n");


	cirAddQueue (queue, 8);
	cirQueueTraverse(queue);
	printf("Queue Size=%d \n", cirQueueSize());
	printf("\n\n");
	
	
	data= cirDelQueue(queue);
	cirQueueTraverse(queue);
	printf("Queue Size=%d \n", cirQueueSize());
	printf("\n\n");	
	
	data= cirDelQueue(queue);
	cirQueueTraverse(queue);
	printf("Queue Size=%d \n", cirQueueSize());
	printf("\n\n");
	
	data= cirDelQueue(queue);
	cirQueueTraverse(queue);
	printf("Queue Size=%d \n", cirQueueSize());
	printf("\n\n");
}



/// add new element in the circular queue
void cirAddQueue (int* queue, int value)
{
	if ( ((rear+1) % MaxSize) == front)
		printf("Error: queue full \n");
	else
	{
		rear= (rear+1) % MaxSize;
		queue[rear] = value;
	}
}


/// remove element out of the circular queue
int cirDelQueue (int* queue)
{
	if (front == rear)
	{
		printf("Error: queue empty \n");
		exit(1);
	}
	else
	{
		front= (front+1) % MaxSize;
		return queue[front];
	}
}

/// return the occupied size of the circular queue
int cirQueueSize()
{
	int size= ((rear-front) + MaxSize) % MaxSize;
	return size;
}

/// print all circular Queue elements 
void cirQueueTraverse (int* queue)
{

	if (front==rear)
	{
		printf("Error: queue empty \n");
		exit(1);
	}
	else
	{
		int temp= front;
		while (temp != rear)
		{
			temp= (temp+1) % MaxSize;
			printf("queue[%d]=%d\n", temp, queue[temp]);	
		}
	}
}



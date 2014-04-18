/// ********** Queue source code **********//
/// ********** The source code has been prepared for DataStructure course, Biomedical Engineering, Cairo University **********//
/// ********** Author: Ahmed Abdelhadi **********///

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 5

int front= -1;
int rear= -1;

void addQueue (int* queue, int value);
void queueTraverse (int* queue);
int delQueue (int* queue);
int queueSize();

int main ()
{
	int queue[MaxSize];
	int data;
	
	
	
	addQueue (queue, 4);
	queueTraverse(queue);
	printf("Queue Size=%d \n", queueSize());
	printf("\n\n");
	
	
	addQueue (queue, 8);
	queueTraverse(queue);
	printf("Queue Size=%d \n", queueSize());
	printf("\n\n");
	
	addQueue (queue, 9);
	queueTraverse(queue);
	printf("Queue Size=%d \n", queueSize());
	printf("\n\n");
	
	addQueue (queue, 9);
	queueTraverse(queue);
	printf("Queue Size=%d \n", queueSize());
	printf("\n\n");
	
	addQueue (queue, 9);
	queueTraverse(queue);
	printf("Queue Size=%d \n", queueSize());
	printf("\n\n");
	
	
	data= delQueue(queue);
	queueTraverse(queue);
	printf("Queue Size=%d \n", queueSize());
	printf("\n\n");
	
	data= delQueue(queue);
	queueTraverse(queue);
	printf("Queue Size=%d \n", queueSize());
	printf("\n\n");

	data= delQueue(queue);
	queueTraverse(queue);
	printf("Queue Size=%d \n", queueSize());
	printf("\n\n");	
	
	data= delQueue(queue);
	queueTraverse(queue);
	printf("Queue Size=%d \n", queueSize());
	printf("\n\n");	
	
	data= delQueue(queue);
	queueTraverse(queue);
	printf("Queue Size=%d \n", queueSize());
	printf("\n\n");	
}



/// add new element to the queue
void addQueue (int* queue, int value)
{
	if (rear+1 >= MaxSize)
		printf("Error: queue full \n");
	else
		queue[++rear] = value;
}


/// remove element out of the queue
int delQueue (int* queue)
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


int queueSize()
{
	return rear-front;
}

/// print all stack elements 
void queueTraverse (int* queue)
{
	int temp=front+1;
	
	if (front==rear)
	{
		printf("Error: queue empty \n");
		exit(1);
	}
	else
	{
		while (temp <= rear)
		{
			printf("queue[%d]=%d\n", temp, queue[temp]);
			temp++;
		}
	}
}



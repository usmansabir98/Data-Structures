#include<stdlib.h>
#include<process.h>
#include<iostream>
using namespace std;

typedef struct
{
	int array[10];
	int front;
	int size;
} Queue;

void enqueue(Queue *q, int val)
{
	int loc = q->front + q->size;
	if(loc>9)
	{
		loc = loc%10;
	}
	q->array[loc] = val; q->size++;
}

int dequeue(Queue *q)
{
	int value;
	if(q->front>9)
		q->front = q->front%10;
		
	value = q->array[q->front++];
	q->size--;
	return value;
}

int main()
{
	Queue q;
	q.front=0; q.size=0;
	enqueue(&q, 28);
	enqueue(&q, 38);
	enqueue(&q, 48);
	enqueue(&q, 58);
	
	for(int i=0; i<4; i++)
	{
		cout << "\nElement " << i << " is " << dequeue(&q);
	}
	
	enqueue(&q, 68);
	enqueue(&q, 78);
	enqueue(&q, 88);
	enqueue(&q, 98);
	
	for(int i=0; i<4; i++)
	{
		cout << "\nElement " << i << " is " << dequeue(&q);
	}
	
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	enqueue(&q, 4);
	
	for(int i=0; i<4; i++)
	{
		cout << "\nElement " << i << " is " << dequeue(&q);
	}
}

#include<stdlib.h>
#include<process.h>
#include<iostream>
using namespace std;

typedef struct queue
{
	int val;
	struct queue * prev;
	struct queue * next;
} queue;

queue *head, *tail;

queue * Enqueue(queue *tail, int value)
{
	queue *newNode = (queue *)malloc(sizeof(queue));
	
	if(newNode!=NULL)
	{
		newNode->val = value;
		newNode->next = NULL;
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
	return tail;
	
}

int Dequeue(queue *target)
{
	queue *trav = target;
	int value = target->val;
	trav = trav->next;
	free(target);
	head = trav;
	if(head!=NULL)
		head->prev = NULL; //for dequeing last element
	return value;
}

queue * create(int value)
{
	queue * list;
	list = (queue *)malloc(sizeof(queue));
	if(list!=NULL)
	{
		list->val= value;
		list->next=NULL;
		list->prev=NULL;
	}
	return list;
}

int main()
{
	
	
	head = create(0);
	tail = head;
	tail = Enqueue(tail,1);
	tail = Enqueue(tail,2);
	tail = Enqueue(tail,3);
	tail = Enqueue(tail,4);
	queue *ptr = head;

	for(int i=1; i<=5; i++)
	{
		cout << "\nElement " << i << " is " << Dequeue(head); 
	}
}

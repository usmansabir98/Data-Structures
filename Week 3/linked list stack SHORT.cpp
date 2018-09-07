#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<iostream>
using namespace std;

typedef struct stack
{
	int val;
	struct stack * next;
} stack;

stack *myStack;

stack * create(int value)
{
	stack * list;
	list = (stack *)malloc(sizeof(stack));
	if(list!=NULL)
	{
		list->val= value;
		list->next=NULL;
	}
	return list;
}


stack * push(stack *head, int value)
{
	stack * newNode;
	newNode = (stack *)malloc(sizeof(stack));
	if(newNode!=NULL)
	{
		newNode->val= value;
		newNode->next=head;
	}
	return newNode;
}

int pop(stack* head)
{
	myStack = head->next;
	int value = head->val;
	free(head);
	return value;
}

int main()
{
	myStack = create(0);
	myStack = push(myStack, 1);
	myStack = push(myStack, 2);
	myStack = push(myStack, 3);
	myStack = push(myStack, 4);
	
	for(int i=0; i<5; i++)
	{
		cout << "\nElement " << i << " is " << pop(myStack);
	}
}

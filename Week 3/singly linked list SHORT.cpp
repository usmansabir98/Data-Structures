#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<iostream>
using namespace std;

typedef struct node
{
	int val;
	struct node * next;
} node;

node * myList;

node * create(int value)
{
	node * list;
	list = (node *)malloc(sizeof(node));
	if(list!=NULL)
	{
		list->val= value;
		list->next=NULL;
	}
	return list;
}

node * insert(node *head, int value)
{
	node * newNode;
	newNode = (node *)malloc(sizeof(node));
	if(newNode!=NULL)
	{
		newNode->val= value;
		newNode->next=head;
	}
	return newNode;
}


bool find(node *head, int value)
{
	node * ptr = head;
	while(ptr!=NULL)
	{
		if(ptr->val==value)
		{
			return true;
		}
		ptr = ptr->next;
	}
	return false;
}

void destroy(node * head)
{
	node * ptr = head;
	if(ptr==NULL)
		return;
	
	else 
	{
		destroy(ptr->next);
		free(ptr);
	}
	
}

int main()
{
	myList = create(1);
	myList = insert(myList,2);
	myList = insert(myList,3);
	node *ptr = myList;
	for(int i=0; i<3; i++)
	{
		cout << "\nElement " << i << " is " << ptr->val;
		ptr=ptr->next;
	}
	destroy(myList);
	ptr = myList;
	for(int i=0; i<3; i++)
	{
		cout << "\nElement " << i << " is " << ptr->val;
		ptr=ptr->next;
	}
	
	myList = create(0);
	for(int i=1; i<10; i++)
	{
		myList = insert(myList,i*100);
	}
	
	ptr = myList;
	
	for(int i=0; i<10; i++)
	{
		cout << "\nElement " << i << " is " << ptr->val;
		ptr=ptr->next;
	}
	
	destroy(myList);
	ptr = myList;
	for(int i=0; i<10; i++)
	{ //garbage values mostly
		cout << "\nElement " << i << " is " << ptr->val;
		ptr=ptr->next;
	}
}

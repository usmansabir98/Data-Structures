#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<iostream>
using namespace std;

typedef struct node
{
	int val;
	struct node * prev;
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
		list->prev=NULL;
	}
	return list;
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

node * insert(node *head, int value)
{
	node * newNode;
	newNode = (node *)malloc(sizeof(node));
	if(newNode!=NULL)
	{
		newNode->val= value;
		newNode->next=head;
		newNode->prev = NULL;
		head->prev=newNode;
		
	}
	return newNode;
}

void deleteNode(node* target)
{
	node *prev, *next;
	
	if(target->prev==NULL)
	{
		myList = target->next;
		myList->prev = NULL;
	}
	else if(target->next==NULL)
	{
		prev = target->prev;
		prev->next = NULL;
	}
	else
	{
		prev = target->prev;
		next = target->next;
		prev->next = target->next;
		next->prev = target->prev;
	}
	
	
	free(target);
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
	myList = create(0);
	for(int i=1; i<10; i++)
	{
		myList = insert(myList,i*100);
	}
	
	node *ptr = myList;
	
	while(ptr!=NULL)
	{
		static int i=1;
		cout << "\nElement " << i++ << " is " << ptr->val;
		ptr=ptr->next;
	}
	
	
	//ptr = myList;
	deleteNode(myList);
	/*ptr = ptr->next;
	deleteNode(ptr);
	ptr = ptr->next;
	deleteNode(ptr);
	ptr = ptr->next;
	deleteNode(ptr);
	ptr = ptr->next;
	deleteNode(ptr);*/
	
	ptr=myList;
	
	cout << "\n\nNew list\n";
	while(ptr!=NULL)
	{ //garbage values mostly
		static int i=1;
		cout << "\nElement " << i++ << " is " << ptr->val;
		ptr=ptr->next;
	}
}

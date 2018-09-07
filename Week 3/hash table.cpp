#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<iostream>
#include<conio.h>
#include<cstring>
using namespace std;

// My Hash Table for strings

typedef struct node
{
	char val[20];
	struct node * next;
} node;

node *table[100]= {NULL};

node * create(char value[])
{
	node * list;
	list = (node *)malloc(sizeof(node));
	if(list!=NULL)
	{
		strcpy(list->val, value);
		list->next=NULL;
	}
	return list;
}

bool find(node *head, char value[])
{
	node * ptr = head;
	while(ptr!=NULL)
	{
		if(strcmp(ptr->val, value)==0)
		{
			return true;
		}
		ptr = ptr->next;
	}
	return false;
}

node * insert(node *head, char value[])
{
	node * newNode;
	newNode = (node *)malloc(sizeof(node));
	if(newNode!=NULL)
	{
		strcpy(newNode->val, value);
		newNode->next=head;
	}
	return newNode;
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

unsigned long hash(char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

int main()
{
	int x; //for hash code
	char str[20], another;
	do
	{
		cout << "\nEnter a string: "; cin>>str;
		x = hash(str)%100; //modding with 100 as only 100 elements in table
		
		if(table[x]==NULL)
		{
			table[x] = create(str);
		}
		else
		{
			table[x] = insert(table[x], str);
		}
		if(table[x]!=NULL)
				cout << "\nSuccessfully Entered\n";
	
		cout << "Do you want to enter anoher string? (y/n)"; another= getche();
	}
	while(another=='y');
	
	cout << "\nEnter a name to find: "; cin>>str;
	x = hash(str)%100;
	if(find(table[x], str))
		cout << "\nElement Found";
	else
		cout << "\nNot Found";
}

#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<iostream>
using namespace std;

typedef struct node
{
	int data;
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
		list->data= value;
		list->next=NULL;
		list->prev=NULL;
	}
	return list;
}

node * insert(node *head, int value)
{
	node * newNode;
	newNode = (node *)malloc(sizeof(node));
	if(newNode!=NULL)
	{
		newNode->data= value;
		newNode->next=head;
		newNode->prev = NULL;
		head->prev=newNode;
		
	}
	return newNode;
}

void sortedInsert(node** head_ref, node* newNode)
{
    node* current;
 
    if (*head_ref == NULL)
        *head_ref = newNode;
 
    else if ((*head_ref)->data >= newNode->data) {
        newNode->next = *head_ref;
        newNode->next->prev = newNode;
        *head_ref = newNode;
    }
 
    else {
        current = *head_ref;
        while (current->next != NULL && current->next->data < newNode->data)
            current = current->next;
 
        newNode->next = current->next;
 
        if (current->next != NULL)
            newNode->next->prev = newNode;
 
        current->next = newNode;
        newNode->prev = current;
    }
}
 
void insertionSort(node** head_ref)
{
    node* sorted = NULL;
    node* current = *head_ref;
    while (current != NULL) {
 
        node* next = current->next;
        current->prev = current->next = NULL;
        sortedInsert(&sorted, current);
        current = next;
    }
    *head_ref = sorted;
}

void printList(node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}
int main()
{
	myList = create(0);
	myList = insert(myList,11);
	myList = insert(myList,7);
	myList = insert(myList,13);
	myList = insert(myList,10);
	myList = insert(myList,4);
	myList = insert(myList,1);
	
	cout << "\nDoubly Linked List Before Sorting\n";
    printList(myList);
 
    insertionSort(&myList);
 
    cout << "\nDoubly Linked List After Sorting\n";
    printList(myList);
}

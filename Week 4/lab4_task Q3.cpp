#include<iostream>
using namespace std;

class node
{
	public:
	int data;
	node* next;
	node* prev;
	
	node(int d){
		data=d;
	}
};

class queue
{
	private:
		node *head, *tail;
		
	public:
		queue()
		{
			head= NULL; tail=NULL;
		}
		
		void enqueue(int val)
		{
			node *newNode = new node(val);
			newNode->next=NULL;
			if(head==NULL)
			{
				newNode->prev=NULL;
				head = tail = newNode;
			}
			else
			{
				newNode->prev= tail;
				tail->next= newNode;
				tail = newNode;
			}
		}
		
		int dequeue()
		{
			if(head==NULL)
			{
				cout << "\nUnderflow" << endl;
				return 0;
			}
			int val = head->data;
			node *temp = head;
			head = head->next;
			delete temp;
			if(head!=NULL)
				head->prev = NULL;
			return val;
		}
		
		int removeSecond()
		{
			int val;
			int val=0;
			if(head->next!=NULL)
			{
				val = head->next->data;
				node *temp = head->next;
				head->next = temp->next;
				delete temp;
			}
			if(head->next!=NULL)
			{
				head->next->prev = head;
			}
			return val;
		}
};

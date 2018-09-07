#include<iostream>
#include<cstring>
#include<conio.h>
using namespace std;

class node
{
	public:
	char data;
	node* next;
	node* prev;
	
	node(char d){
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
		
		void enqueue(char val)
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
//				cout << "\nUnderflow" << endl;
				return 0;
			}
			char val = head->data;
			node *temp = head;
			head = head->next;
			delete temp;
			if(head!=NULL)
				head->prev = NULL;
			return val;
		}
};

class stack
{
	private:
		node *head;
	
	public:
		stack()
		{
			head = NULL;
		}
		
		void push(char val)
		{
			node *newNode = new node(val);
			newNode->next= head;
			head = newNode; // updating the head pointer
		}
		
		char pop()
		{
			if(head==NULL)
			{
//				cout << "\nUnderflow" << endl;
				return 0;
			}
			char val = head->data;
			node *temp =head;
			head = head->next;
			delete temp;
			return val;
		}
};

int main()
{
	char word1[]="apoopa";
	char word2[]="apoopa";
	
	char *w1 = word1;
	char *w2 = word2;
	
	stack s; queue q;
	while(*w1!='\0' && *w2!='\0')
	{
		s.push(*w1); w1++;
		q.enqueue(*w2); w2++;
	}
	int c1, c2;
	c1 = s.pop(); c2 = q.dequeue();
	while(c1!=0 && c2!=0)
	{
		if(c1!=c2)
		{
			cout << "Not a palindrome";
			return 0;
		}
		c1 = s.pop(); c2 = q.dequeue();
	}
	cout << "Palindrome";
}

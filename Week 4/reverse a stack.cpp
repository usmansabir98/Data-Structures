#include<iostream>
#include<cstring>
#include<string>
#include<iomanip>
#include<math.h>
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

class stack
{
	private:
		node *head;
	
	public:
		stack()
		{
			head = NULL;
		}
		
		bool empty()
		{
			return head==NULL;
		}
		
		char top()
		{
			if(head!=NULL)
				return head->data;
			return 0;
		}
		
		void push(int val)
		{
			node *newNode = new node(val);
			newNode->next= head;
			head = newNode; // updating the head pointer
		}
		
		int pop()
		{
			if(head==NULL)
			{
//				cout << "\nUnderflow" << endl;
				return 0;
			}
			int val = head->data;
			node *temp =head;
			head = head->next;
			delete temp;
			return val;
		}
};



void insertAtBottom(stack *s, int val)
{
	if(s->empty())
	{
		s->push(val); return;
	}
	
	int temp = s->pop();
	insertAtBottom(s, val);
	s->push(temp);	
}

void reverse(stack *s)
{
	if(s->empty())
		return;
	
	else
	{
		int temp = s->pop();
		reverse(s);
		insertAtBottom(s, temp);
	}
}

int main()
{
	stack s1;
	s1.push(4);
	s1.push(3);
	s1.push(2);
	s1.push(1);
	
	reverse(&s1);
	
	cout << s1.pop() << endl;
	cout << s1.pop() << endl;
	cout << s1.pop() << endl;
	cout << s1.pop() << endl;
}

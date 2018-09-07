#include<iostream>
#include<cstring>
#include<string>
#include<conio.h>
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

void transfer(stack *s1, stack *s2)
{
	stack temp;
	while(!s1->empty())
	{
		temp.push(s1->pop());
	}
	while(!temp.empty())
	{
		s2->push(temp.pop());
	}
}


int main()
{
	stack s1, s2;
	s1.push(5);
	s1.push(4);
	s1.push(3);
	s1.push(2);
	s1.push(1);
	
	transfer(&s1, &s2);
	
	cout << s2.pop() << endl;
	cout << s2.pop() << endl;
	cout << s2.pop() << endl;
	cout << s2.pop() << endl;
	cout << s2.pop() << endl;
	
}

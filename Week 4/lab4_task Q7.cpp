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

void interchange(stack *s1, stack *s2)
{
	stack temp;
	while(!s1->empty())
	{
		temp.push(s1->pop());
		temp.push(s2->pop());
	}
	while(!temp.empty())
	{
		s1->push(temp.pop());
		s2->push(temp.pop());
		
	}
}

int main()
{
	stack s1, s2;
	s1.push(7); s1.push(5); s1.push(3); s1.push(1);
	s2.push(8); s2.push(6); s2.push(4); s2.push(2);
	
	interchange(&s1, &s2);
	
	cout << "Interchanged"<< endl;
	cout << "s1" <<setw(10)<< "s2" << endl;
	cout << s1.pop() <<setw(10)<< s2.pop() << endl;
	cout << s1.pop() <<setw(10)<< s2.pop() << endl;
	cout << s1.pop() <<setw(10)<< s2.pop() << endl;
	cout << s1.pop() <<setw(10)<< s2.pop() << endl;
}

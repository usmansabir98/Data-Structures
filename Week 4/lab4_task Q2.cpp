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

void removeDownTo(stack *s, int val)
{
	while(!s->empty() && s->top()!=val)
	{
		if(val==NULL)
		{
			while(!s->empty())
				s->pop();
		}
		s->pop();
	}
}

int main()
{
	stack st;
	st.push(55);
	st.push(44);
	st.push(33);
	st.push(22);
	st.push(11);
	removeDownTo(&st,44);
	cout << st.pop();
}

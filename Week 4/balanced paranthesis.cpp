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

bool IsOpeningParanthesis(char op)
{
	return (op=='(' || op=='{' || op=='[');
}

bool IsClosingParanthesis(char op)
{
	return (op==')' || op=='}' || op==']');
}

int getWeight(char op)
{
	int weight;
	switch(op)
	{
		case '(':
		case ')':
			weight=1; break;
		case '{':
		case '}':
			weight=2; break;
		case '[':
		case ']':
			weight=3; break;
		default:
			weight=-1;
	}
	return weight;
}

bool isPair(char b1, char b2)
{
	int w1 = getWeight(b1);
	int w2 = getWeight(b2);
	return w1==w2;
}

bool CheckBalancedParanthesis(string exp)
{
	stack s;
	int len=exp.length();
	for(int i=0; i< len; i++)
	{
		if(!IsOpeningParanthesis(exp[i]) || !IsClosingParanthesis(exp[i]))
			continue;
			
		if(IsOpeningParanthesis(exp[i]))
		{
			s.push(exp[i]);
		}
		else if(IsClosingParanthesis(exp[i]))
		{
			if(s.empty() || !isPair(s.top(), exp[i]))
				return false;
			else
				s.pop();
		}
	}
	return s.empty();
}

int main()
{
	string exp = "[{e-(a+b)*(c*d)}/2]";
	CheckBalancedParanthesis(exp)? cout << "balanced" : cout << "unbalanced";

}

#include<iostream>
#include<cstring>
#include<string>
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

int getWeight(char op)
{
	int weight;
	switch(op)
	{
		case '+':
		case '-':
			weight=1; break;
		case '*':
		case '/':
			weight=2; break;
		case '^':
			weight=3; break;
		default:
			weight=-1;
	}
	return weight;
}

bool IsRightAssociative(char op)
{
	return op=='^';
}

bool HasHigherPrec(char op_stack, char op_exp)
{
	int weight1 = getWeight(op_stack);
	int weight2 = getWeight(op_exp);
	if(weight1==weight2) 
	{
		if(IsRightAssociative(op_stack))
			return false;
		else
			return true;
	}
	return weight1>weight2;
}

bool IsOpeningParanthesis(char op)
{
	return op=='(';
}

bool IsOperator(char exp)
{
	return(exp=='+' || exp=='-' || exp=='/' || exp=='*' || exp=='^');
		
}

bool IsOperand(char exp)
{
	return
	(
		(exp>='A' && exp<='Z') ||
		(exp>='a' && exp<='z') ||
		(exp>='0' && exp<='9')
	);
	
}

string InfixToPostfix(char *exp)
{
	string res="";
	stack s;
	for(int i=0; i<strlen(exp); i++)
	{
		if(IsOperand(exp[i]))
		{
			res+=exp[i];
		}
		else if(IsOperator(exp[i]))
		{
			while(!s.empty() && !IsOpeningParanthesis(s.top())  && HasHigherPrec(s.top(), exp[i]))
			{
				res+=s.top();
				s.pop();
			}
			s.push(exp[i]);
		}
		else if(IsOpeningParanthesis(exp[i]))
			s.push(exp[i]);
		
		else if(exp[i]==')')
		{
			while(!s.empty() && !IsOpeningParanthesis(s.top()))
			{
				res+=s.top();
				s.pop();
			}
			s.pop();
		}
	}
	while(!s.empty())
	{
		res+=s.top();
		s.pop();
	}
	return res;
}

int main()
{
	char *str = "A*B+C*D-E";
	cout << InfixToPostfix(str);
}

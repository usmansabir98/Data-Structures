#include<iostream>
using namespace std;

class Stack
{
	private:
		enum { MAX = 5 }; //(non-standard syntax)
		int st[MAX]; //stack: array of integers
		int top; //number of top of stack
	public:
		Stack() //constructor
		{ top = -1; }
		
		void push(int var) //put number on stack
		{ 
			if(top>(MAX-2))
				cout << "Exceeding MAX range." << endl;
			
			else
				st[++top] = var; 
		}
		int pop() //take number off stack
		{ 
		
			if(top<0)
				cout << "\nNo elements to pop." << endl;
			else
				return st[top--]; 
		}
};

int main()
{
	Stack s1;
	s1.push(11);
	s1.push(22);
	s1.push(33);
	s1.push(44);
	s1.push(55);
	s1.push(66); //Error	
	s1.push(65000); //Error
	cout << "\n " << s1.pop();
	cout << "\n " << s1.pop();
	cout << "\n " << s1.pop();
	cout << "\n " << s1.pop();
	cout << "\n " << s1.pop();
	cout << "\n " << s1.pop();
}


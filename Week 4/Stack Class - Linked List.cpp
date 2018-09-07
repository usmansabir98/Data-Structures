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

class stack
{
	private:
		node *head;
	
	public:
		stack()
		{
			head = NULL;
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
				cout << "\nUnderflow" << endl;
				return 0;
			}
			int val = head->data;
			node *temp =head;
			head = head->next;
			delete temp;
			return val;
		}
};

/*int main()
{
	stack s;
	s.push('u');
	s.push('s');
	s.push('m');
	s.push('a');
	s.push('n');
	
	cout << static_cast<char>(s.pop());
	cout << static_cast<char>(s.pop());
	cout << static_cast<char>(s.pop());
	cout << static_cast<char>(s.pop());
	cout << static_cast<char>(s.pop());
	cout << static_cast<char>(s.pop());
}*/

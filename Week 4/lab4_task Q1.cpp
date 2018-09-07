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
		
		int removeSecond()
		{
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

int main()
{
	stack s1;
	s1.push(4);
	s1.push(3);
	s1.push(2);
	s1.push(1);
	cout << s1.removeSecond()<< endl;
	cout << s1.pop() << endl;
	cout << s1.pop() << endl;
	cout << s1.removeSecond()<< endl;
	cout << s1.pop() << endl;
}

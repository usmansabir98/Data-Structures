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
		
		bool empty()
		{
			return head==NULL;
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

class queue
{
	private:
		node *head, *tail;
		
	public:
		queue()
		{
			head= NULL; tail=NULL;
		}
		
		bool empty()
		{
			return (head==NULL);
		}
		
		void enqueue(int val)
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
				cout << "\nUnderflow" << endl;
				return 0;
			}
			int val = head->data;
			node *temp = head;
			head = head->next;
			delete temp;
			if(head!=NULL)
				head->prev = NULL;
			return val;
		}
		
		
};

void reverse(queue *q)
{
	stack s;
	while(!q->empty())
	{
		s.push(q->dequeue());
	}
	while(!s.empty())
	{
		q->enqueue(s.pop());
	}
	
}

int main()
{
	queue q;
	q.enqueue(1);q.enqueue(2);q.enqueue(3);q.enqueue(4);q.enqueue(5);
	reverse(&q);
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
}

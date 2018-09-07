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
		
		void removeAfter(int val)
		{
			node *trav=tail;
			if(val==NULL || trav->data==val) return;
			
			while(trav->prev->data!=val && trav!=NULL)
				trav=trav->prev;
			
			tail = trav->prev;
			tail->next=NULL;
			while(trav!=NULL)
			{
				node *temp=trav;
				trav=trav->next;
				delete temp;
			}
		}
};

int main()
{
	queue q;
	q.enqueue(1);q.enqueue(2);q.enqueue(3);q.enqueue(4);q.enqueue(5);
	q.removeAfter(2);
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
}


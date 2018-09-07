#include<iostream>
#include<conio.h>
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

class dequeue
{
	private:
		node *head, *tail;
		
	public:
		dequeue()
		{
			head= NULL; tail=NULL;
		}
		
		void addFirst(int val)
		{
			node *newNode = new node(val);
			newNode->prev=NULL;
			if(head==NULL)
			{
				newNode->next=NULL;
				head = tail = newNode;
			}
			else
			{
				newNode->next=head;
				head->prev=newNode;
				head=newNode;
			}
		}
		
		void addLast(int val)
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
		
		int removeFirst()
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
		
		int removeLast()
		{
			if(tail==NULL)
			{
				cout << "\nUnderflow" << endl;
				return 0;
			}
			int val = tail->data;
			node *temp = tail;
			tail = tail->prev;
			delete temp;
			if(tail!=NULL)
				tail->next = NULL;
			return val;
		}
		
		void printList()
		{
			node* trav=head;
			while(trav!=NULL)
			{
				cout << trav->data << "->";
				trav=trav->next;
			}
				
			cout << "X"<< endl;
		}
};

int main()
{
	dequeue q;
	char ch;int val;
	while(1)
	{
		cout << "\n1. Add First" << endl;
		cout << "2. Add Last" << endl;
		cout << "3. Remove First" << endl;
		cout << "4. Remove Last" << endl;
		cout << "5. Print List" << endl;
		cout << "Select Option: "; ch=getche();
		switch(ch)
		{
			case '1':
				cout << "\nValue: "; cin >> val;
				q.addFirst(val);
				break;
			case '2':
				cout << "\nValue: "; cin >> val;
				q.addLast(val);
				break;
				
			case '3':
				cout << "\nValue: " << q.removeFirst() << endl;
				break; 
			
			case '4':
				cout << "\nValue: " << q.removeLast() << endl;
				break; 
			
			case '5':
				cout << endl;
				q.printList(); break;
			
			case '0':
				exit(0);
			
			default:
				cout << "\nInvalid" << endl;
		}
	}
}

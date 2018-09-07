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

class dll
{
		
	public:
		node *head;
	
		dll()
		{
			head = NULL;
		}
		
		void push(int val)
		{
			node *newNode = new node(val);
			newNode->next= head;
			newNode->prev= NULL;
			
			if(head!=NULL)
				head->prev=newNode; //connecting the old head's prev pointer to new node
			
			head = newNode; // updating the head pointer
		}
		
		void insertAfter(node *prevNode, int val)
		{
			if(prevNode==NULL)
			{
				cout << "\nPrevious Node cannot be NULL" << endl;
				return;
			}
			node *newNode = new node(val);
			
			newNode->next = prevNode->next; // connecting newNode with nextNode
			
			//following two steps connect prevNode with newNode
			prevNode->next = newNode;
			newNode->prev = prevNode; 
			
			if(newNode->next!=NULL)
				newNode->next->prev = newNode; //connecting next node with newNode
			
		}
		
		void append(int val)
		{
			node *newNode = new node(val);
			newNode->next=NULL;
			if(head==NULL) //empty list
			{
				newNode->prev= NULL;
				head = newNode; // updating the head pointer
			}
			
			else
			{
				node *trav= head;
				while(trav->next!=NULL) //stopping when the next ptr points back to the head
				{
					trav = trav->next; //traverse till the last node
				}
				//now trav points to the last node in the list
				//following two steps connect prevNode with newNode
				trav->next = newNode;
				newNode->prev = trav; 
			}
		}
		
		void deleteNode_key(int key)
		{
			if(head==NULL)
			{
				cout << "\nList is empty"; return;
			}
			
			node *temp=head, *prev=NULL;
			
			if(temp!=NULL && temp->data==key)
			{
				head= head->next;
				head->prev=NULL;
				delete temp;
				return;
			}
			
			while(temp!=NULL && temp->data!=key)
			{
				prev = temp;
				temp = temp->next;
			}
			
			if(temp==NULL) return;
			
			prev->next = temp->next;
			delete temp;
		}
		
		void deleteNode_pos(int pos)
		{
			if(head==NULL)
			{
				cout << "\nList is empty"; return;
			}
			
			node *temp=head;
			
			if(pos==0)
			{
				head= head->next;
				head->prev=temp->prev;
				temp->prev->next = head;
				delete temp;
				return;
			}
			
			temp = temp->next;
			for(int i=1; temp!=head && i < pos-1; i++)
			{
				temp = temp->next;
			}
			
			if(temp==NULL || temp->next==NULL)
			{
				cout << "Invalid" << endl; return; 
			}
			
			node *next = temp->next->next;
			delete temp->next;
			temp->next = next;
			
		}
		
		void printList()
		{
			node *trav=head;
			
			cout << "Traversing just once\n";
			while(trav!=NULL)
			{
				cout << trav->data << "->";
				trav=trav->next;
			}
			cout << 'X'<<endl;		
		}
		
		void duplicate()
		{
			int count;
			node *trav= head;
			node *tr;
			while(trav!=NULL)
			{
				count=0;
				tr=head;
				while(tr!=NULL)
				{
					if(tr->data==trav->data && trav!=tr)
					{
						count++;
					}
					tr=tr->next;
					
				}
				if(count > 0)
					cout << "Duplicate of " << trav->data << " : "<< count << endl;
				trav=trav->next;
			}
		}
};

int main()
{
	dll myList;
	myList.append(3);
	myList.append(3);
	myList.push(4);
	myList.push(3);
	myList.push(4);
	myList.push(1);
	myList.append(5);
	myList.append(4);
	myList.append(7);
	myList.append(3);
	myList.append(3);
	myList.append(7);
	myList.insertAfter(myList.head->next, 100);
	myList.deleteNode_key(100);
	myList.printList();
	
	myList.duplicate();
}

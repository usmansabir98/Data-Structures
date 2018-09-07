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

class cll
{
		
	public:
		node *head;
	
		cll()
		{
			head = NULL;
		}
		
		void push(int val)
		{
			node *newNode = new node(val);
			
			if(head==NULL) //empty list
			{
				newNode->next= newNode;
				newNode->prev= newNode;
				// nodes should point to itself
			}
			
			else
			{
				newNode->next=head; 
				newNode->prev= head->prev; //connected new node with the last node
				head->prev->next = newNode; // connecting the last node with the new node
				head->prev=newNode; //connecting the old head's prev pointer to new node
			}
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
			
			newNode->next->prev = newNode; //connecting next node with newNode
			
		}
		
		void append(int val)
		{
			node *newNode = new node(val);
			
			if(head==NULL) //empty list
			{
				newNode->next= newNode;
				newNode->prev= newNode;
				// nodes should point to itself
				
				head = newNode; // updating the head pointer
			}
			
			else
			{
				node *trav= head;
				while(trav->next!=head) //stopping when the next ptr points back to the head
				{
					trav = trav->next; //traverse till the last node
				}
				//now trav points to the last node in the list
				
				newNode->next = head;
				
				//following two steps connect prevNode with newNode
				trav->next = newNode;
				newNode->prev = trav; 
				
				head->prev = newNode; //connecting next node with newNode
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
				head->prev=temp->prev;
				temp->prev->next = head;
				delete temp;
				return;
			}
			
			do
			{
				prev = temp;
				temp = temp->next;
			}
			while(temp!=head && temp->data!=key);
			
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
			
			if(temp==head || temp->next==head)
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
			do
			{
				cout << trav->data << "->";
				trav=trav->next;
			}
			while(trav!=head);
			cout << 'X';
			
			trav=head;
			cout << "\n\nTraversing in circle. \nPress any key to print the next element\n";
			while(1)
			{
				cout << trav->data << "->";
				trav=trav->next;
				getch();
			}
			
			
		}
};

int main()
{
	cll myList;
	myList.push(4);
	myList.push(3);
	myList.push(2);
	myList.push(1);
	myList.append(5);
	myList.append(6);
	myList.append(7);
	myList.append(8);
	

	myList.insertAfter(myList.head->next, 100);
	
	myList.deleteNode_key(1);
	myList.printList();
}


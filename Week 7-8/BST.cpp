#include<iostream>
#include<queue>
#include<conio.h>
using namespace std;

class node
{
	public:
		int data;
		node *left,*right;
		
		node(int val){ data =val; }
};

int larger(int a, int b)
{
	return a>b? a:b; 
}
class BST
{
	private:
		node * root;
		
		node* getNewNode(int val)
		{
			//creating new node
			node *newNode = new node(val);
			newNode->left=newNode->right=NULL;
			return newNode;
		}
		
		node* insertHelper(node *rootPtr, int val)
		{
			//inserting
			if(rootPtr==NULL)
				rootPtr=getNewNode(val);
			
			else if(val<=rootPtr->data)
				rootPtr->left=insertHelper(rootPtr->left, val);
			
			else
				rootPtr->right=insertHelper(rootPtr->right, val);
			
			return rootPtr;
		}
		
		bool searchHelper(node *rootPtr, int key)
		{
			if(rootPtr==NULL) 
				return false;
				
			if(rootPtr->data==key)
				return true;
			else if(key < rootPtr->data)
				return searchHelper(rootPtr->left, key);
			else
				return searchHelper(rootPtr->right, key);
		}
		
		int findHeight(node* rootPtr)
		{
			if(rootPtr==NULL) 
				return -1;
			
			int leftHeight = findHeight(rootPtr->left);
			int rightHeight = findHeight(rootPtr->right);
			return larger(leftHeight, rightHeight) + 1;
		}
		
		void levelOrder()
		{
			if(root==NULL) return;
			
			queue<node*> q;
			q.push(root);
			
			while(!q.empty())
			{
				node *current = q.front();
				cout << current->data << "->";
				if(current->left!=NULL) q.push(current->left);
				if(current->right!=NULL) q.push(current->right);
				q.pop();
			}
			cout << "END"<< endl;
		}
		
		void preorder(node *rootPtr)
		{
			if(rootPtr==NULL)
				return;
			cout << rootPtr->data << "->";
			preorder(rootPtr->left);
			preorder(rootPtr->right);
		}
		
		void inorder(node *rootPtr)
		{
			if(rootPtr==NULL)
				return;
			
			inorder(rootPtr->left);
			cout << rootPtr->data << "->";
			inorder(rootPtr->right);
		}
		
		void postorder(node *rootPtr)
		{
			if(rootPtr==NULL)
				return;
			postorder(rootPtr->left);
			postorder(rootPtr->right);
			cout << rootPtr->data << "->";
		}
		
		bool isBST(node *rootPtr, int min, int max)
		{
			if(rootPtr==NULL) return true;
			
			if(
				rootPtr->data>min && rootPtr->data<max &&
				isBST(rootPtr->left, min, rootPtr->data) &&
				isBST(rootPtr->right, rootPtr->data, max)
				)
				return true;
			
			else 
				return false;
		}
		
		node * deleteHelper(node *rootPtr, int val)
		{
			if(rootPtr==NULL) return rootPtr;
			
			else if(val < rootPtr->data)
				rootPtr->left = deleteHelper(rootPtr->left, val);
			else if(val > rootPtr->data)
				rootPtr->right = deleteHelper(rootPtr->right, val);
			
			else //found
			{
				//case 1: leaf node
				if(rootPtr->left==NULL && rootPtr->right==NULL)
				{
					delete rootPtr;
					rootPtr = NULL;
				}
				
				//case 2: one child (only right)
				else if(rootPtr->left==NULL)
				{
					node *temp = rootPtr;
					rootPtr = rootPtr->right;
					delete temp;
				}
				
				//case 2: one child (only left)
				else if(rootPtr->right==NULL)
				{
					node *temp = rootPtr;
					rootPtr = rootPtr->left;
					delete temp;
				}
				
				//case 3: 2 children
				else
				{
					node* temp = min(root->right);
					rootPtr->data=temp->data;
					rootPtr->right = deleteHelper(root->right, temp->data);
				}
			}
			return rootPtr;
		}
	
	public:
		BST(){root=NULL;}
		
		void insert(int val)
		{
			root = insertHelper(root, val);
		}
		
		bool search(int key)
		{
			return searchHelper(root, key);
		}
		
		node* min(node *trav=root)
		{
			
			while(trav->left!=NULL)
				trav=trav->left;
			return trav;
		}
		
		node* max(node *trav=root)
		{
			
			while(trav->right!=NULL)
				trav=trav->right;
			return trav;
		}
		
		int height()
		{
			return findHeight(root);
		}
		
		void print()
		{
			while(1)
			{
				cout << "\nChoose method: " << endl;
				cout << "1. Level Order Traversal" << endl;
				cout << "2. Pre Order" << endl;
				cout << "3. In Order" << endl;
				cout << "4. Post Order" << endl;
				cout << "Option: "; char ch = getche();
				cout << "\n\nData printed: ";
				switch(ch)
				{
					case '1': levelOrder(); return;
					case '2': preorder(root); cout << "END" << endl; return;
					case '3': inorder(root); cout << "END" << endl; return;
					case '4': postorder(root); cout << "END" << endl; return;
					default: cout << "invalid"<< endl; 
				}
			}
		}
		
		bool isBinarySearchTree()
		{
			return isBST(root, INT_MIN, INT_MAX);
		}
		
		void testing()
		{
			node* newNode = getNewNode(40);
			newNode->left = root->left;
			root->left = newNode;
		}
		
		void deleteNode(int val)
		{
			root = deleteHelper(root, val);
		}
		
};

int main()
{
	BST tree;
	tree.insert(20);
	tree.insert(15);
	tree.insert(25);
	tree.insert(21);
	tree.insert(26);
	tree.insert(14);
	tree.insert(16);
	tree.print();
	if(tree.search(15))
		cout << "\nFound" << endl;
	else
		cout << "\nNot found" << endl;
		
	tree.testing(); //making BST not a BST
	if(tree.isBinarySearchTree())
		cout << "\nThis is binary search tree" << endl;
	else
		cout << "\nNot a BST" << endl;
	
	node* Min = tree.min();
	node* Max = tree.max();
	cout << "Minimum = " << Min->data << endl;
	cout << "Maximum = " << Max->data << endl;
	cout << "Height = " << tree.height();
}

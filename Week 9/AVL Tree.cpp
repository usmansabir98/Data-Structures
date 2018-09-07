#include<iostream>
#include<queue>
#include<stack>
#include<conio.h>
using namespace std;

class node
{
	public:
		int data;
		int height;
		node *left,*right;
		
		node(int val){ data =val; }
};


class AVLTree
{
	private:
		node *root;
		
		node* getNewNode(int val)
		{
			//creating new node
			node *newNode = new node(val);
			newNode->left=newNode->right=NULL;
			newNode->height=1;
			return newNode;
		}
		
		
		int getBalanceFactor(node *N)
		{
			if(N==NULL)
				return 0;
			else
				return height(N->left) - height(N->right);
		}
		
		// A utility function to get height of the tree
		int height(node *N)
		{
		    if (N == NULL)
		        return 0;
		    return N->height;
		}
		
		node* min(node *Node) //general
		{
			node * trav = Node;
			while(trav->left!=NULL)
				trav=trav->left;
			return trav;
		}
			
		
		node * rightRotate(node *y)
		{
			node *x = y->left;
			node *T2 = x->right;
			
			x->right = y;
			y->left = T2;
			
			// order matters
			//find height of y before x because height of x depends on y now
    		y->height = max(height(y->left), height(y->right))+1;
			x->height = max(height(x->left), height(x->right))+1;
			return x;
		}
		
		node * leftRotate(node *x)
		{
			node *y = x->right;
			node *T2 = y->left;
			
			y->left = x;
			x->right = T2;
			
			// order matters
			//find height of x before y because height of y depends on x now
			x->height = max(height(x->left), height(x->right))+1;
    		y->height = max(height(y->left), height(y->right))+1;
			return y;
			
		}
		
		node* insert(node* Node, int key)
		{
		    /* 1.  Perform the normal BST insertion */
		    if (Node == NULL)
		        return getNewNode(key);
		 
		    if (key < Node->data)
		        Node->left  = insert(Node->left, key);
		    else if (key > Node->data)
		        Node->right = insert(Node->right, key);
		    else // Equal keys are not allowed in BST
		        return Node;
		 
		    /* 2. Update height of this ancestor Node */
		    Node->height = 1 + max(height(Node->left),height(Node->right));
		 
		    /* 3. Get the balance factor of this ancestor
		          Node to check whether this Node became
		          unbalanced */
		    int balance = getBalanceFactor(Node);
		 
		    // If this Node becomes unbalanced, then
		    // there are 4 cases
		 
		    // Left Left Case
		    if (balance > 1 && key < Node->left->data)
		        return rightRotate(Node);
	
		    // Right Right Case
		    if (balance < -1 && key > Node->right->data)
		        return leftRotate(Node);
		 
		    // Left Right Case
		    if (balance > 1 && key > Node->left->data)
		    {
		        Node->left =  leftRotate(Node->left);
		        return rightRotate(Node);
		    }
		 
		    // Right Left Case
		    if (balance < -1 && key < Node->right->data)
		    {
		        Node->right = rightRotate(Node->right);
		        return leftRotate(Node);
		    }
		 
		    /* return the (unchanged) Node pointer */
		    return Node;
		}
		
		bool isAVLHelper(node *rootPtr)
		{
			if(rootPtr==NULL)
				return true;
				
			int balance = getBalanceFactor(rootPtr);
			if(balance<-1 || balance >1)
				return false;
				
			return isAVLHelper(rootPtr->left) && isAVLHelper(rootPtr->right);
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
			
			rootPtr->height = 1 + max(height(rootPtr->left), height(rootPtr->right));
			int balance = getBalanceFactor(rootPtr);
			
			if(balance>1) // we are either in left-left or left-right case
			{
				if(getBalanceFactor(rootPtr->left)>=0) //left left case
				{
					return rightRotate(rootPtr);
				}
				else //left-right case
				{
					rootPtr->left = leftRotate(rootPtr->left);
					return rightRotate(rootPtr);
				}
			}
			
			if(balance<-1)
			{
				if(getBalanceFactor(rootPtr->left)<=0) //right-right case
				{
					return leftRotate(rootPtr);
				}
				else //right-left case
				{
					rootPtr->right = rightRotate(rootPtr->right);
					return leftRotate(rootPtr);
				}
			}
			
			return rootPtr;
		}
		
		void preorder(node *rootPtr)
		{
			if(rootPtr==NULL)
				return;
			cout << rootPtr->data << "->";
			preorder(rootPtr->left);
			preorder(rootPtr->right);
		}
		
	public:
		AVLTree()
		{
			root=NULL; 
		}
		
		
		void Insert(int val)
		{
			root = insert(root, val);
		}
		
		bool search(int key)
		{
			return searchHelper(root, key);
		}
		
		void deleteNode(int val)
		{
			root = deleteHelper(root, val);
		}
		
		bool isAVL()
		{
			return isAVLHelper(root);
		}
		
		void preorder_iterative()
		{
			stack<node*> s;
			s.push(root);
			while(!s.empty())
			{
				node* item = s.top();
				cout << item->data << "->";
				s.pop();
				if(item->right)
					s.push(item->right);
					
				if(item->left)
					s.push(item->left);
			}
		}
		
		void Preorder()
		{
			preorder(root);
		}
		
};

int main()
{
	AVLTree tree;
	tree.Insert(9);
    tree.Insert(5);
    tree.Insert(10);
    tree.Insert(0);
    tree.Insert(6);
    tree.Insert(11);
    tree.Insert(-1);
    tree.Insert(1);
    tree.Insert(2);
	tree.preorder_iterative();
	tree.deleteNode(10);
	cout<< endl;
	tree.Preorder();
	cout << "END";
	
	if(tree.isAVL())
		cout << "\nThis is AVL";
	else
		cout << "\nThis is NOT AVL";
}

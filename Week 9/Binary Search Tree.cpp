#include<iostream>
#include<queue>
#include<stack>
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
	protected:
		node * root;
	
	private:
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
		
		int findSize(node *rootPtr) //returns total no of nodes in a tree
		{
			if(rootPtr==NULL)
				return 0;
			else
				return 1 + findSize(rootPtr->left)+ findSize(rootPtr->right);
		}
		node *findNode(node *rootPtr, int key)
		{
			if(rootPtr==NULL) 
				return NULL;
				
			if(rootPtr->data==key)
				return rootPtr;
			else if(key < rootPtr->data)
				return findNode(rootPtr->left, key);
			else
				return findNode(rootPtr->right, key);
		}
		
		int depthHelper(node* rootPtr, node *u)
		{
			if(rootPtr==u)
				return 0;
			else if(u->data < rootPtr->data)
				return 1 + depthHelper(rootPtr->left, u);
			else
				return 1 + depthHelper(rootPtr->right, u);
		}
		
		int fullNodesHelper(node *rootPtr)
		{
			if(rootPtr==NULL)
				return 0;
				
			else if(rootPtr->left!=NULL && rootPtr->right!=NULL)
			{
				return 1 + fullNodesHelper(rootPtr->left) 
								+ fullNodesHelper(rootPtr->right);
			}
			else
			{
				return 0 + fullNodesHelper(rootPtr->left) 
								+ fullNodesHelper(rootPtr->right);
			}		
		}
		
		int leafNodesHelper(node *rootPtr)
		{
			if(rootPtr==NULL)
				return 0;
			else if(rootPtr->left==NULL && rootPtr->right==NULL)
			{
				return 1 + leafNodesHelper(rootPtr->left) 
								+ leafNodesHelper(rootPtr->right);
			}
			else
			{
				return 0 + leafNodesHelper(rootPtr->left) 
								+ leafNodesHelper(rootPtr->right);
			}
		}
		
		int neitherNodesHelper(node *rootPtr)
		{
			if(rootPtr==NULL)
				return 0;
			else if( (rootPtr->left==NULL && rootPtr->right!=NULL) || 
						(rootPtr->left!=NULL && rootPtr->right==NULL)  )
			{
				return 1 + neitherNodesHelper(rootPtr->left) 
								+ neitherNodesHelper(rootPtr->right);
			}
			else
			{
				return 0 + neitherNodesHelper(rootPtr->left) 
								+ neitherNodesHelper(rootPtr->right);
			}
		}
		
		bool isLeafNode(node* u)
		{
			if(u->left==NULL && u->right==NULL)
				return true;
			return false;
		}
		
		bool isFullNode(node* u)
		{
			if(u->left!=NULL && u->right!=NULL)
				return true;
			return false;
		}
		
		bool isFullBTHelper(node *rootPtr)
		{
			if(isLeafNode(rootPtr)) return true;
			
			else if(isFullNode(rootPtr))
				return isFullBTHelper(rootPtr->left) && isFullBTHelper(rootPtr->right);
			else
				return false;
		}
		
		bool isPerfectRec(node* rootPtr, int d, int level = 0)
		{
		    // An empty tree is perfect
		    if (rootPtr == NULL)
		        return true;
		 
		    // If leaf node, then its depth must be same as
		    // depth of all other leaves.
		    if (rootPtr->left == NULL && rootPtr->right == NULL)
		        return (d == level);
		 
		    // If internal node and one child is empty
		    if (rootPtr->left == NULL || rootPtr->right == NULL)
		        return false;
		 
		    // Left and right subtrees must be perfect.
		    return isPerfectRec(rootPtr->left, d, level+1) &&
		           isPerfectRec(rootPtr->right, d, level+1);
		}
		
		bool isCompleteRec(node* rootPtr, int i, int size)
		{
			if(rootPtr==NULL) return true;
			
			// If index assigned to current node is more than
    		// number of nodes in tree, then tree is not complete
			else if(i>=size) return false;
			
			return  isCompleteRec(rootPtr->left, 2*i+1, size) &&
            		isCompleteRec(rootPtr->right, 2*i+2, size);
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
		
		node* min() //starting at root
		{
			node *trav = root;
			while(trav->left!=NULL)
				trav=trav->left;
			return trav;
		}
		
		node* min(node *trav) //general
		{
			while(trav->left!=NULL)
				trav=trav->left;
			return trav;
		}
		
		node* max() //starting at root
		{
			node *trav = root;
			while(trav->right!=NULL)
				trav=trav->right;
			return trav;
		}
		
		node* max(node *trav) //general
		{
			while(trav->right!=NULL)
				trav=trav->right;
			return trav;
		}
		
		int height_iterative()
		{
			queue<node*> q;
			q.push(root);
			int height = -1;
			while(true)
			{
				int nodeCount = q.size();
				if(nodeCount==0)
					return height;
				else
					height++;
					
				while(nodeCount>0)
				{
					node *current = q.front();
					if(current->left!=NULL) q.push(current->left);
					if(current->right!=NULL) q.push(current->right);
					q.pop();
					nodeCount--;
				}
			}
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
					case '2': preorder(root); cout << "END" << endl; 
							  preorder_iterative(); cout << "END" << endl;
							  return;
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
		
		int size() //returns total no of nodes in a tree
		{
			return findSize(root);
		}
		
		int depth(int key)
		{
			node *u=findNode(root, key);
			return depthHelper(root, u);
		}
		
		int fullNodes()
		{
			return fullNodesHelper(root);
		}
		
		int fullNodes_iterative()
		{
			if(root==NULL) return 0;
			
			queue<node*> q;
			q.push(root);
			int count = 0;
			while(!q.empty())
			{
				node *current = q.front();
				if(current->left!=NULL && current->right!=NULL)
					count++;
				if(current->left!=NULL) q.push(current->left);
				if(current->right!=NULL) q.push(current->right);
				q.pop();
			}
			return count;
		}
		
		int leafNodes()
		{
			return leafNodesHelper(root);
		}
		
		int leafNodes_iterative()
		{
			if(root==NULL) return 0;
			
			queue<node*> q;
			q.push(root);
			int count = 0;
			while(!q.empty())
			{
				node *current = q.front();
				if(current->left==NULL && current->right==NULL)
					count++;
				if(current->left!=NULL) q.push(current->left);
				if(current->right!=NULL) q.push(current->right);
				q.pop();
			}
			return count;
		}
		
		int neitherNodes()
		{
			return neitherNodesHelper(root);
		}
		
		int neitherNodes_iterative()
		{
			if(root==NULL) return 0;
			
			queue<node*> q;
			q.push(root);
			int count = 0;
			while(!q.empty())
			{
				node *current = q.front();
				if( (current->left!=NULL && current->right==NULL) ||
						 (current->left==NULL && current->right!=NULL) )
					count++;
				if(current->left!=NULL) q.push(current->left);
				if(current->right!=NULL) q.push(current->right);
				q.pop();
			}
			return count;
		}
		
		bool isFullBT()
		{
			return isFullBTHelper(root);
		}
		 
		// Wrapper over isPerfectRec()
		bool isPerfectBT()
		{
		   int d = findHeight(root);
		   return isPerfectRec(root, d);
		}
		
		bool isCompleteBT()
		{
			int size = findSize(root); //size of tree
			int i=0; //initial index=0
			return isCompleteRec(root, i, size);
		}
};

int main()
{
	BST tree;
	tree.insert(9);
    tree.insert(5);
    tree.insert(10);
    tree.insert(0);
    tree.insert(6);
    tree.insert(11);
    tree.insert(-1);
    tree.insert(1);
    tree.insert(2);
	tree.print();
//	if(tree.search(15))
//		cout << "\nFound" << endl;
//	else
//		cout << "\nNot found" << endl;
//		
//	tree.testing(); //making BST not a BST
//	if(tree.isBinarySearchTree())
//		cout << "\nThis is binary search tree" << endl;
//	else
//		cout << "\nNot a BST" << endl;
//	
//	node* Min = tree.min();
//	node* Max = tree.max();
//	cout << "Minimum = " << Min->data << endl;
//	cout << "Maximum = " << Max->data << endl;
//	cout << "Height = " << tree.height_iterative() << endl;
//	cout << "Size = " << tree.size() << endl;
//	cout << "Depth = " << tree.depth(15) << endl;
//	cout << "No of Full Nodes = " << tree.fullNodes() << endl;
//	cout << "No of Full Nodes = " << tree.fullNodes_iterative() << endl;
//	cout << "No of Leaf Nodes = " << tree.leafNodes() << endl;
//	cout << "No of Leaf Nodes = " << tree.leafNodes_iterative() << endl;
//	cout << "No of Neither Nodes = " << tree.neitherNodes() << endl;
//	cout << "No of Neither Nodes = " << tree.neitherNodes_iterative() << endl;
//
//	cout << "Full Tree = ";if(tree.isFullBT()) cout<<"yes"; else cout<<"no"<<endl;
//	cout << "Full Tree = ";if(tree.isFullBT()) cout<<"yes"; else cout<<"no"<<endl;
//	cout << "Full Tree = ";if(tree.isFullBT()) cout<<"yes"; else cout<<"no"<<endl;
}

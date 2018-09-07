#include<iostream>
#include<queue>
#include<stack>
#include<conio.h>
#include<cstring>
#include<string>
using namespace std;

class node
{
	public:
		int data;
		node *left,*right;
		
		node(int val){ data =val; }
};

class BT
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
		
		node* buildTreeHelper(int* arr, int index=0)
		{
			node *current = NULL;
			
			if(arr[index]!=NULL)
			{
				current = getNewNode(arr[index]);
				current->left = buildTreeHelper(arr, 2*index+1);
				current->right = buildTreeHelper(arr, 2*index+2);
			}
			
			return current;
		}
		
		//build tree from inorder and preorder
		node* buildTreeTrav(string in, string pre, int inStart, int inEnd) 
		{
			static int preIndex=0;
			if(inStart>inEnd)
				return NULL;
				
			/* Pick current node from Preorder traversal */
			node * tNode = getNewNode(pre[preIndex++]);
			
			/* If this node has no children then return */
			if(inStart==inEnd)
				return tNode;
			
			/* Else find the index of this node in Inorder traversal */
			int inIndex = in.find(tNode->data);
			
			/* Using index in Inorder traversal, construct left and
		     right subtress */
			tNode->left = buildTreeTrav(in, pre, inStart, inIndex-1 );
			tNode->right = buildTreeTrav(in, pre, inIndex+1, inEnd);
		
			return tNode;
		}
		
		
		void deleteDeepest(node *deep)
		{
			node* current;
			if(root==NULL) return;
			
			queue<node*> q;
			q.push(root);
			
			while(!q.empty())
			{
				current = q.front();
				q.pop();
				
				if(current->left!=NULL)
				{
					if(current->left==deep)
					{
						current->left=NULL;
						delete deep;
						return;
					}
					else
						q.push(current->left);
				}
				
				if(current->right!=NULL) 
				{
					if(current->right==deep)
					{
						current->right=NULL;
						delete deep;
						return;
					}
					q.push(current->right);
				}
				
			}
		}
		
	public:
		BT(){ root =NULL;}
		
		void buildTree(int *arr) //using array
		{
			root = buildTreeHelper(arr, 0);
		}
			
		void buildTree(string in, string pre) //using traversals
		{
			root = buildTreeTrav(in, pre, 0, in.length()-1);
		}
		
		void levelOrder()
		{
			if(root==NULL) return;
			
			queue<node*> q;
			q.push(root);
			
			while(!q.empty())
			{
				node *current = q.front();
				cout << (char)current->data << "->";
				if(current->left!=NULL) q.push(current->left);
				if(current->right!=NULL) q.push(current->right);
				q.pop();
			}
			cout << "END"<< endl;
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
		
		void inorder_iterative()
		{
			stack<node*> s;
			node* current = root;
//			s.push(current);
			int done=0;
			
			while(!done)
			{
				if(current!=NULL)
				{
					s.push(current);
					current = current->left;
				}
				
				else
				{
					if(!s.empty())
					{
						current = s.top(); 
						s.pop();
						
						cout << current->data << "->";
						current = current->right;
					}
					else
						done=1;	
				}
			}
		}
		void postorder_iterative()
		{
			stack<node*> s1, s2;
			s1.push(root);
			while(!s1.empty())
			{
				node* item = s1.top();
				s2.push(item);
				s1.pop();
					
				if(item->left)
					s1.push(item->left);
				if(item->right)
					s1.push(item->right);
			}
			while(!s2.empty())
			{
				node* item = s2.top();
				cout << item->data << "->";
				s2.pop();
			}
				
		}
		
		void insert(int d)
		{
			if(root==NULL)
			{
				root = getNewNode(d);
				return;
			}
			queue<node*> q;
	    	q.push(root);
	 
	    // Do level order traversal until we find
	    // an empty place. 
	    	while (!q.empty()) 
			{
		        node* temp= q.front();
		        q.pop();
		 
		        if (!temp->left) {
		            temp->left = getNewNode(d);
		            break;
		        } 
				else
					q.push(temp->left);
		 
		        if (!temp->right) {
		            temp->right = getNewNode(d);
		            break;
		        } 
				else
		           q.push(temp->right);
	    	}
		}
		
		void Delete(int key)
		{
			node* keyNode, *current;
			if(root==NULL) return;
			
			queue<node*> q;
			q.push(root);
			
			while(!q.empty())
			{
				current = q.front();
				if(current->data==key)
					keyNode = current;
				if(current->left!=NULL) q.push(current->left);
				if(current->right!=NULL) q.push(current->right);
				q.pop();
			}
			
			keyNode->data = current->data;
			deleteDeepest(current);
		}
		
		
};

int main()
{
	BT tree;
//	int treeArray[]={1,2,3,4,5,6,7, NULL, 8, NULL,NULL, NULL, NULL, NULL, NULL , NULL,
//			NULL, NULL , NULL, NULL, NULL};
//			
//		
//	tree.buildTree(treeArray);
//	cout << "\nInserting " << 22 <<endl;
//	tree.insert(22);
//	cout << "\nInserting " << 33<< endl;
//	tree.insert(33);
//	
//	cout << "\nInserting " << 44 << endl;
//	tree.insert(44);
//	tree.inorder_iterative();
//	cout << endl;
//	tree.Delete(22);
//	tree.inorder_iterative();
//	cout << endl;
//	tree.postorder_iterative();
	string inorder = "DBFEAGCLJHK";
	string preorder = "ABDEFCGHJLK";
	tree.buildTree(inorder, preorder);
	tree.levelOrder();
}

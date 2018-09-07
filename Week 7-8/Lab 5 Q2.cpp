#include<iostream>
#include<queue>
#include<stack>
#include<conio.h>
#include<math.h>
using namespace std;

#include "infix to postfix conversion.cpp"

class node
{
	public:
		char data;
		node *left,*right;
		
		node(char val){ data =val; }
};

class BST
{
	private:
		node * root;
		
		node* getNewNode(char val)
		{
			//creating new node
			node *newNode = new node(val);
			newNode->left=newNode->right=NULL;
			return newNode;
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
			cout << rootPtr->data;
			inorder(rootPtr->right);
		}
		
		void postorder(node *rootPtr)
		{
			if(rootPtr==NULL)
				return;
			postorder(rootPtr->left);
			postorder(rootPtr->right);
			cout << rootPtr->data;
		}
		
		int calculate(int a, int b, char op)
		{
			int res=0;
			switch(op)
			{
				case '+': res= a+b; break;
				case '-': res= a-b; break;
				case '*': res= a*b; break;
				case '/': res= a/b; break;
				case '^': res= pow(a,b); break;
			}
			return res;
		}
		
		bool isLeafNode(node* u)
		{
			if(u->left==NULL && u->right==NULL)
				return true;
			return false;
		}
		
		int evaluateHelper(node* rootPtr)
		{
			if(rootPtr==NULL)
				return 0;
			
			if(IsOperand(rootPtr->data))
			{
				return rootPtr->data -'0';
			}
			int A = evaluateHelper(rootPtr->left);
			int B = evaluateHelper(rootPtr->right);
			return calculate(A,B,rootPtr->data);
			
		}
		
		
		
	public:
		BST(){ root=NULL; }
		
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
					case '3': inorder(root); cout << "." << endl; return;
					case '4': postorder(root); cout << "END" << endl; return;
					default: cout << "invalid"<< endl; 
				}
			}
		}
		
		void constructTree(char *postfix)
		{
			stack<node*> s;
			int len = strlen(postfix);
			for(int i=0; i<len; i++)
			{
				node* newNode = getNewNode(postfix[i]);
				
				if(IsOperand(postfix[i]))	
					s.push(newNode);
				
				else if(IsOperator(postfix[i]))
				{
					node* r = s.top();
					s.pop();
					node* l = s.top();
					s.pop();
					newNode->right = r;
					newNode->left = l;
					s.push(newNode);
				}
			}
			root = s.top(); s.pop();
		}
		
		
		int evaluate()
		{
			return evaluateHelper(root);
		}
		
};

int main()
{
	BST tree;
	tree.constructTree("54+32*2*-");
	tree.print();
	cout << tree.evaluate()<<endl;
}

#include<iostream>
#include<conio.h>
using namespace std;

enum Color {BLACK, RED};

class node
{
	public:
		int data;
		Color color;
		node *left,*right, *parent;
		bool isNullLeaf;
		node(int val){ data =val; left=right=parent=NULL;}
};

class RedBlackTree
{
	private:
		node *root;
		
		node* createBlackNode(int data)
		{
			node *newNode = new node(data);
			newNode->color = BLACK;
			newNode->left= createNullLeafNode(newNode);
			newNode->right= createNullLeafNode(newNode);
			newNode->isNullLeaf=false;
			return newNode;
		}
		
		node* createNullLeafNode(node* parent)
		{
			node *newNode = new node(0);
			newNode->color= BLACK;
			newNode->isNullLeaf=true;
			newNode->parent=parent;
			return newNode;
		}
		
		node* createRedNode(node* parent, int data)
		{
			node *newNode = new node(data);
			newNode->color = RED;
			newNode->left= createNullLeafNode(newNode);
			newNode->right= createNullLeafNode(newNode);
			newNode->parent=parent;
			newNode->isNullLeaf=false;
			return newNode;
		}
		
		void rightRotate(node* Root, bool changeColor)
		// root is child
		{
			node* parent = Root->parent;
			Root->parent = parent->parent;
			
			if(parent->parent!=NULL)
			{
				if(parent->parent->right==parent)
					parent->parent->right=Root;
				else
					parent->parent->left=Root;
			}
			
			node *right = Root->right;
			
			Root->right = parent;
			parent->parent = Root;
			parent->left = right;
			if(right!=NULL)
				right->parent=parent;
			
			if(changeColor)
			{
				Root->color=BLACK;
				parent->color=RED;
			}
		}
		
		void leftRotate(node* Root, bool changeColor)
		{
			node* parent = Root->parent;
			Root->parent = parent->parent;
			
			if(parent->parent!=NULL)
			{
				if(parent->parent->right==parent)
					parent->parent->right=Root;
				else
					parent->parent->left=Root;
			}
			
			node *left = Root->left;
			
			Root->left = parent;
			parent->parent = Root;
			parent->right = left;
			if(left!=NULL)
				left->parent=parent;
			
			if(changeColor)
			{
				Root->color=BLACK;
				parent->color=RED;
			}
		}
			
		
		bool isLeftChild(node* Root) // Root is father 
		{
        	node* parent = Root->parent;
        	return parent->left == Root;     
    	}
		
		node* findSiblingNode(node* Root) {
			// find ta'au jee
			node* parent = Root->parent;
			node* result;
	        if(isLeftChild(Root))
	            result = parent->right;
	            
	        else
	            result = parent->left;
	            
	        return result;
	    }
		
		
		node* insert(node* parent, node* Root, int data)
		{
			if(Root  == NULL ) 
			{
	            //if parent is not NULL means tree is not empty
	            //so create a red leaf node
	            if(parent != NULL)
	                return createRedNode(parent, data);
	            else //otherwise create a black Root node if tree is empty
	                return createBlackNode(data);
	            
	        }
	        
	        //duplicate insertion is not allowed for this tree.
	        if(Root->data == data)
	            cout << "duplicate data " << data << endl;
	        
	        //if we go on left side then isLeft will be true
	        //if we go on right side then isLeft will be false.
	        bool isLeft;
	        if(Root->data > data) 
			{
	            node* left = insert(Root, Root->left, data);
	            //if left becomes Root parent means rotation
	            //happened at lower level. So just return left
	            //so that nodes at upper level can set their
	            //child correctly
	            if(left == Root->parent)
	                return left;
	            
	            //set the left child returned to be left of Root node
	            Root->left = left;
	            //set isLeft to be true
	            isLeft = true;
	        } 
			else 
			{
	            node* right = insert(Root, Root->right, data);
	            //if right becomes Root parent means rotation
	            //happened at lower level. So just return right
	            //so that nodes at upper level can set their
	            //child correctly
	            if(right == Root->parent) {
	                return right;
	            }
	            //set the right child returned to be right of Root node
	            Root->right = right;
	            //set isRight to be true
	            isLeft = false;
	        }

	        if(isLeft) 
			{
	            //if we went to left side check to see Red-Red conflict
	            //between Root and its left child
				if(Root->color == RED && Root->left->color == RED)
				{
	                //get the sibling of Root. It is returning optional means
	                //sibling could be empty
	                node* sibling = findSiblingNode(Root);
	                //if sibling is empty or of BLACK color
	                if(sibling->color ==  BLACK)
					{
	                    //check if Root is left child of its parent
	                    if(isLeftChild(Root)) 
						{
	                        //this creates left left situation. So do one right rotate
	                        rightRotate(Root, true);
	                    } 
						else 
						{
	                        //this creates left-right situation so do one right rotate followed
	                        //by left rotate
	
	                        //do right rotation without change in color. So sending false.
	                        //when right rotation is done Root becomes right child of its left
	                        //child. So make Root = Root.parent because its left child before rotation
	                        //is new Root of this subtree.
	                        rightRotate(Root->left, false);
	                        //after rotation Root should be Root's parent
	                        Root = Root->parent;
	                        //then do left rotate with change of color
	                        leftRotate(Root, true);
	                    }
	                } 
					else 
					{
	                    //we have sibling color as RED. So change color of Root
	                    //and its sibling to Black. And then change color of their
	                    //parent to red if their parent is not a Root.
	                    Root->color =  BLACK;
	                    sibling->color =  BLACK;
	                    //if parent's parent is not NULL means parent is not Root->
	                    //so change its color to RED->
	                    if(Root->parent->parent != NULL)
	                        Root->parent->color = RED;
	                }
	            }
	        } 
			else 
			{
	            //this is mirror case of above. So same comments as above.
	            if(Root->color ==  RED && Root->right->color ==  RED) {
	                node* sibling = findSiblingNode(Root);
	                if(sibling->color ==  BLACK) {
	                    if(!isLeftChild(Root)) {
	                        leftRotate(Root, true);
	                    } else {
	                        leftRotate(Root->right, false);
	                        Root = Root->parent;
	                        rightRotate(Root, true);
	                    }
	                } else {
	                    Root->color =  BLACK;
	                    sibling->color =  BLACK;
	                    if(Root->parent->parent != NULL) {
	                        Root->parent->color =  RED;
	                    }
	                }
	            }
	        }
	        return Root;
		}
		
		void inorder(node *rootPtr)
		{
			if(rootPtr==NULL)
				return;
			
			inorder(rootPtr->left);
			if(!rootPtr->isNullLeaf)
				cout << rootPtr->data << "->";
			inorder(rootPtr->right);
		}
		
		
	public:
		RedBlackTree()
		{
			root = NULL;
		}
		
		void insert(int data)
		{
			root = insert(NULL, root, data);
		}
		
		void inorder()
		{
			inorder(root);
		}
};

int main()
{
	RedBlackTree tree;
	tree.insert(7);
    tree.insert(6);
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);
    
    cout << "Inoder Traversal of Created Tree\n";
    tree.inorder();
}

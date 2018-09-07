#include<iostream>
using namespace std;

class BTreeNode
{
	public:
		int *keys;
		int m; 			// order of the B-tree
		BTreeNode **C	// an array of child pointers
		int n; 			// current no.of trees
		bool leaf		// Is true when node is leaf. Otherwise false
		
		BTreeNode(int M, bool Leaf): m(M), leaf(Leaf)
		{
			keys = new int[m-1];
			C = new BTreeNode*[m];
			n=0;
		}
		
		void traverse()
		{
			// There are n keys and n+1 children, travers through n keys
    		// and first n children
			int i;
			for(i=0; i<n; i++)
			{
				// If this is not leaf, then before printing key[i],
        		// traverse the subtree rooted with child C[i].
				if(!leaf)
					C[i]->traverse();
				cout << " " << keys[i];
			}
			
    		// Print the subtree rooted with last child
			if(!leaf)
				C[i]->traverse();
		}
		
		BTreeNode* search(int k)
		{
			int i=0;
		    // Find the first key greater than or equal to k
			
			while(i<n && keys[i] < k)
				i++;
				
			// If the found key is equal to k, return this node
			if(keys[i]==k)
				return this;
			
			// If key is not found here and this is a leaf node
			if(leaf)
				return NULL;
			
			// Go to the appropriate child
			return C[i]->search();
		}
		
		// A utility function to insert a new key in the subtree rooted with
    	// this node. The assumption is, the node must be non-full when this
    	// function is called
    	void insertNonFull(int k)
    	{}
 
    	// A utility function to split the child y of this node. i is index of y in
    	// child array C[].  The Child y must be full when this function is called
    	void splitChild(int i, BTreeNode *y)
    	{}
};


class BTree
{
    BTreeNode *root; // Pointer to root node
    int m;  // Order of B-tree
	
	public:
	    // Constructor (Initializes tree as empty)
	    BTree(int M)
	    {  root = NULL;  m = M; }
	 
	    // function to traverse the tree
	    void traverse()
	    {  if (root != NULL) root->traverse(); }
	 
	    // function to search a key in this tree
	    BTreeNode* search(int k)
	    {  return (root == NULL)? NULL : root->search(k); }
	    
	    //main insert function
	    void insert(int k)
	    {
	    	
		}
};


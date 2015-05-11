#ifndef BST_H
#define BST_H

#include <iostream>

/** 
 * Assignment 8 for CSE231 Data Structures
 *
 * 2014. 2. 2
 *
 */

//
// Binary tree node
//
class node {
public:
	int value;
	node* parent;
	node* left;
	node* right;	
};

//
// Binary Search Tree class
//

class BST {
public:
	BST();
	~BST();
	
	// Return true if tree is empty
	bool IsEmpty();
		
	// Insert k. If k exists, do nothing.
	void Insert(int k);
	
	// Delete k from tree
	void Delete(int k);
	
	// Return node with k. Return null if not found.
	node* Search(int k);
	
	// Traverse tree in-order and print values
	void PrintInorder();

	void insert(node* a,  int k);
	
	node* Node(int k);

	node* visit(node* a)
	{
	        order[num]=a->value;
	       	num++;
	}

	void Inorder(node* a)
	{
        	node* here=a;
        	if(here)
        	{
                	Inorder(here->left);
                	visit(here);
                	Inorder(here->right);
       		}
	}	


private:
	
	node* root;
	int *order;
	static int num;
};

#endif

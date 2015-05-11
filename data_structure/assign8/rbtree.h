#ifndef RBTREE_H
#define RBTREE_H

#include <iostream>
#include "assert.h"
/** 
 * Assignment 8 for CSE231 Data Structures
 *
 * 2014. 2. 2
 *
 */

//
// Red-Black tree node
//
class rbnode {
public:
	int value;
	bool red; // true if red, false if black
	rbnode* parent;
	rbnode* left;
	rbnode* right;	
};

//
// Red-Black Balanced Search Tree class
//
class RBTREE {
public:
	RBTREE();
	~RBTREE();
	
	// Return true if tree is empty
	bool IsEmpty();
		
	// Insert k. If k exists, do nothing.
	void Insert(int k);
	
	void insert(rbnode* a, int k);
	// Delete k from tree
	void Delete(int k);
	
	// return node with value k. return null if not found.
	rbnode* Search(int k);
	
	// Traverse tree in-order and print values
	void PrintInorder();

        rbnode* visit(rbnode* a)
        {
	assert(a);
                order[num]=a->value;
                num++;
        }

	inline rbnode* gp(rbnode* a)
	{	
		if((a!=NULL) && (a->parent!=NULL))
			return a->parent->parent;
		else
			return NULL;
	}

	inline rbnode* uc(rbnode* a)
	{
		if(gp(a)==NULL)
			return NULL;
		if(a->parent==gp(a)->left)
			return gp(a)->right;
		else
			return gp(a)->left;	
	}

	inline rbnode* sb(rbnode* a)
	{
		if(a==a->parent->left)
			return a->parent->right;
		else
			return a->parent->left;
	}
	
	void Arrange(rbnode* a);
	void PisB(rbnode* a);
	void XYr(rbnode* a);
	void LRb(rbnode* a);
	void LLb(rbnode* a);
	void rotateR(rbnode* a);
	void rotateL(rbnode* a);
	void case0(rbnode* a);
	void case1(rbnode* a);
        void case21(rbnode* a);    
	void case22(rbnode* a); 
	void case3(rbnode* a);
        void case4(rbnode* a);
       
      
        void Inorder(rbnode* a)
        {
                rbnode* here=a;
                if(here)
                {
                        Inorder(here->left);
                        visit(here);
                        Inorder(here->right);
                }
        }

private:
	
	rbnode* root;
	int* order;
	static int num;
};

#endif

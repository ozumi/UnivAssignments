#include "bst.h"

/** 
 * Assignment 8 for CSE231 Data Structures
 *
 * 2014. 2. 2
 *
 */

int BST::num = 0;

BST::BST()
{
	root=NULL;
	order = new int[10000000];
}


BST::~BST()
{
	delete []order;	
}


bool
BST::IsEmpty()
{
	if(root==NULL)
		return 1;
	else
		return 0;
}


void 
BST::Insert(int k)
{
	if(IsEmpty())
	{		
		node* obj = new node;
	        obj->value=k;
	        obj->parent=NULL;
	        obj->left=NULL;
	        obj->right=NULL;
		root=obj;	
	}
	else
	{
		node* here=root;

		insert(here, k);
	}
}

void
BST::insert(node* a,int k){

	if(k< a->value){
		if(a->left==NULL)
		{
	        node* obj = new node;
        	obj->value=k;
	        obj->parent=a;
        	obj->left=NULL;
	        obj->right=NULL;
		a->left=obj;

		}else
			insert(a->left, k);
	}else{
		if(a->right==NULL)
		{

	        node* obj = new node;
        	obj->value=k;
	        obj->parent=a;
        	obj->left=NULL;
	        obj->right=NULL;
		a->right=obj;

		}else
			insert(a->right, k);
	}
}
	



void 
BST::Delete(int k)
{
if(!IsEmpty())
{
	node* del = Search(k);
	node* here;
if(del!=NULL){
	if(del->left!=NULL){
		here=del->left;

		while(here->right!=NULL)
			here=here->right;
	
		del->value=here->value;

		if(here!=del->left)
			here->parent->right=NULL;
		else
			del->left=NULL;

		delete here;
	}
	else if(del->right!=NULL){
		here=del->right;
	
		while(here->left!=NULL)
			here=here->left;

		del->value=here->value;

		if(here!=del->right)
			here->parent->left=NULL;
		else
			del->right=NULL;

		delete here;
	}
	else{
		if(del!=root)
		{node*p=del->parent;
		if(p->left==del)
			p->left=NULL;	
		else
			p->right=NULL;
		}
		else
			root=NULL;
		delete del;
		
	}

}
}

}



node* 
BST::Search(int k)
{
	node *here = root;
	
	while(here!=NULL && here->value!=k)
	{
		if(here->value>k)
			here=here->left;
		else if(here->value<k)
			here=here->right;		
		else{}
	}
	return here;
}


void 
BST::PrintInorder()
{
	
        if(!IsEmpty()){
        Inorder(root);
        int j=0;
        for(; j<num-1; j++)
                std::cout<<order[j]<<", ";
        std::cout<<order[j]<<std::endl;
        }
}

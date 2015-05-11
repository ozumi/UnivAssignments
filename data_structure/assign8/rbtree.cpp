#include "rbtree.h"
#include "assert.h"

/** 
 * Assignment 8 for CSE231 Data Structures
 *
 * 2014. 2. 2
 *
 */
int RBTREE::num = 0;

RBTREE::RBTREE()
{
	root=NULL;
	order = new int[10000000];
}


RBTREE::~RBTREE()
{
	delete[] order;
}


bool
RBTREE::IsEmpty()
{
	if(root==NULL)
		return 1;
	else
		return 0;
}


void 
RBTREE::Insert(int k)
{
	if(IsEmpty())
	{	
		rbnode* obj = new rbnode;
	        obj->value = k;
	        obj->red = 0;
	        obj->parent = NULL;
	        obj->left = NULL;
	        obj->right = NULL;
		root=obj;
		
	}else
		insert(root, k);

}

void
RBTREE::insert(rbnode* a, int k){

        if(k< a->value){
                if(a->left==NULL)
                {
                rbnode* obj = new rbnode;
                obj->value=k;
		obj->red = 1;
                obj->parent=a;
                obj->left=NULL;
                obj->right=NULL;
                a->left=obj;

		Arrange(obj);
                }else
                        insert(a->left, k);
        }else if(k>a->value)
	{
                if(a->right==NULL)
                {
                rbnode* obj = new rbnode;
                obj->value=k;
		obj->red = 1;
                obj->parent=a;
                obj->left=NULL;
                obj->right=NULL;
                a->right=obj;

		Arrange(obj);
                }else
                        insert(a->right, k);
        }
}

void
RBTREE::Arrange(rbnode* a)
{
	if(a->parent==NULL)
		a->red = 0;
	else 
		PisB(a);
}

void
RBTREE::PisB(rbnode* a) 
{
	if(a->parent->red == 0)
		return;
	else
		XYr(a);
}

void
RBTREE::rotateR(rbnode *a)
{
	rbnode* p = a->parent;
	rbnode* child = a->left;

	if(p!=NULL){
	if(p->left==a)
		p->left=child;
	else
		p->right=child;
	}
	child->parent=p;
	a->parent=child;

	if(child->right!=NULL){
		rbnode* r = child->right;
		a->left=r;
		r->parent=a;	
	}else
		a->left=NULL;

	child->right=a;
}

void
RBTREE::rotateL(rbnode *a)
{
        rbnode* p = a->parent;
        rbnode* child = a->right;
	if(p!=NULL){
        if(p->left==a)
                p->left=child;
        else
                p->right=child;
	}
	child->parent=p;
        a->parent=child;

	if(child->left!=NULL){
		rbnode* l = child->left;
        	a->right=l;
        	l->parent=a;
	}else
		a->right=NULL;
		
	child->left=a;
}

void
RBTREE::LLb(rbnode* a)
{
	a->parent->red = 0;
	gp(a)->red = 1;
	if(a==a->parent->left)
		rotateR(gp(a));
	else
		rotateL(gp(a));
}

void
RBTREE::LRb(rbnode* a)
{
	if(a==a->parent->right && a->parent==gp(a)->left){
		rotateL(a->parent);
		a=a->left;
	}else if(a==a->parent->left && a->parent==gp(a)->right){
		rotateR(a->parent);
		a=a->right;
	}
	LLb(a);
}

void 
RBTREE::XYr(rbnode* a)
{	
	if(uc(a) != NULL && uc(a)->red == 1){
	a->parent->red = 0;
	uc(a)->red = 0;
	if(gp(a)!=root)
		gp(a)->red = 1;
	Arrange(gp(a));
	}
	else
		LRb(a);
}

void
RBTREE::Delete(int k)
{
	bool ok, sk=0;
	bool noroot=1;
	rbnode* here;
	rbnode* del=Search(k);
if(!IsEmpty())
{
        
if(del!=NULL){

if(del->red==1)
	ok=1;

        if(del->left!=NULL){
                here=del->left;

                while(here->right!=NULL)
                        here=here->right;

                del->value=here->value;
		del->red=here->red;
		if(here->red==1)
			sk=1;

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
		del->red=here->red;

		if(here->red==1)	
			sk=1;

                if(here!=del->right)
                        here->parent->left=NULL;
                else
                        del->right=NULL;

                delete here;
                }
        else{
                if(del!=root)
                {rbnode*p=del->parent;
                if(p->left==del)
                        p->left=NULL;
                else
                        p->right=NULL;
                }
		else
			root=NULL;
		noroot=0;
        }

if(noroot){
	assert(del);
	if(ok == 0){
		if(sk==1)
			del->red == 0;
		else
			case0(del);
	}
}
else
	delete del;
}}}

void
RBTREE::case0(rbnode*a)
{
	if(a->parent!=NULL)
		case1(a);
}
void 
RBTREE::case1(rbnode* a)
{
//if(sb(a)!=NULL){
	if(sb(a)->red == 1){
		a->parent->red=1;
		sb(a)->red=0;

		if(a==a->parent->left){
			rotateL(a->parent);
			assert(sb(a));
		}else{
			rotateR(a->parent);
			assert(sb(a));
		}
	}
	case21(a);
//}
}

void
RBTREE::case22(rbnode* a)
{
bool l=0, r=0;

assert(sb(a));
if(sb(a)->left==NULL)
	l=1;
else
{
	if(sb(a)->left->red==0)
		l=1;
}
if(sb(a)->right==NULL)
	r=1;
else
{
	if(sb(a)->right->red==0)
		r=1;
}

	if((a->parent->red==1)&&(sb(a)->red==0)&&
	  l&&r)
	{	sb(a)->red=1;
		a->parent->red=0;
	}
	else
		case3(a);
}

void
RBTREE::case21(rbnode* a)
{
bool l=0, r=0;
assert(sb(a));
if(sb(a)->left==NULL)
        l=1;
else
{
        if(sb(a)->left->red==0)
                l=1;
}
if(sb(a)->right==NULL)
        r=1;
else
{
        if(sb(a)->right->red==0)
                r=1;
}

	if((a->parent->red==0)&&(sb(a)->red==0)&&
          l&&r) 
	{	  sb(a)->red=1;;
		  case1(a->parent);
	 } else
		  case22(a);
}

void
RBTREE::case3(rbnode* a)
{

assert(sb(a));
bool l=0, r=0;
if(sb(a)->left==NULL)
        l=1;
else
{
        if(sb(a)->left->red==0)
                l=1;
}
if(sb(a)->right==NULL)
        r=1;
else
{
        if(sb(a)->right->red==0)
                r=1;
}

if(sb(a)->red==0){
	if ((a==a->parent->left)&&r&&!l)
	{ 
		sb(a)->red=1;
		sb(a)->left->red=0;
		rotateR(sb(a));
	} else if((a==a->parent->right)&&l&&!r) 
	{
		sb(a)->red=1;
		sb(a)->right->red=0;
		rotateL(sb(a));
	}
 }
	case4(a);
}

void
RBTREE::case4(rbnode* a)
{
assert(sb(a));
	
	sb(a)->red=a->parent->red;
	a->parent->red=0;
	
	if (a==a->parent->left) 
	{
		sb(a)->right->red=0;
		rotateL(a->parent);
 	} else 
	{
		sb(a)->left->red=0;
		rotateR(a->parent);
 	}
}

rbnode* 
RBTREE::Search(int k)
{
        rbnode *here = root;

        while(here!=NULL && here->value!=k)
        {
                if(here->value>k)
                        here=here->left;
                else if(here->value<k)
                        here=here->right;
        }

       return here;
}


void 
RBTREE::PrintInorder()
{
	if(!IsEmpty()){
        Inorder(root);
	int j=0;
        for(; j<num-1; j++)
                std::cout<<order[j]<<", ";
	std::cout<<order[j]<<std::endl;
	}
}



#include <stdlib.h>
#include "bst.h"
#include "rbtree.h"
#include <stdio.h>
#include <time.h>
#include <math.h>

using namespace std;

#define NTEST 100


int main()
{
	// 1. Basic Tree Function Test
	RBTREE bt;
	
	bt.Insert(10);
	bt.Insert(1);
	bt.Insert(44);
	bt.Insert(2);
	bt.Insert(7);
	bt.Insert(32);
	bt.Insert(102);
	bt.Insert(62);

	bt.Delete(33);
	bt.Delete(44);
	bt.Delete(1);


	bt.PrintInorder();
	
	
	// 2. Performance comparision between BST and RBTREE
	std::cout << "Test data size : " << NTEST << std::endl;
	
	BST t;
	RBTREE rb;
	
	// create test data
	int *data = new int[NTEST];
	char *op = new char[NTEST];
	
	srand (time(NULL));
	
	for(int i=0; i<NTEST; i++) 
	{
		int num = i;
		t.Insert(num);
		rb.Insert(num);
	}
	
	//
	// BST test
	//
	clock_t start = clock();
		rb.PrintInorder();
	clock_t finish = clock();
	printf("BST took %f ms to execute.\n",
		   (double)(finish - start) / CLOCKS_PER_SEC*1000.0);
	
	//
	// Red-black tree test
	//
/*	start = clock();
	for(int i=0; i<NTEST; i++) 
	{
		int num = rand();
		rb.Insert(num);
	}
	finish = clock();
	printf("RBTREE took %f ms to execute.\n",
		   (double)(finish - start) / CLOCKS_PER_SEC*1000.0);
*/	
	
	delete [] data;
	delete [] op;
		
	return 0;
}

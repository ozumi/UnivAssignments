#include "minheap.h"

// Destructor
MinHeap::~MinHeap()
{
	delete []heapArray;
	delete []mapVidxToArray;
}	

void 
MinHeap::Push(const heapElem& e)
{
	size++;

	if(size==capacity)
	{
		heapElem *temp=new heapElem[2*capacity];
		unsigned int *ttmp=new unsigned int[2*capacity];
		for(int i=0; i<capacity; i++)
		{	temp[i]=heapArray[i];
			ttmp[i]=mapVidxToArray[i];
		}
		delete []heapArray;
		delete []mapVidxToArray;
		heapArray=temp;
		mapVidxToArray=ttmp;
		capacity*=2;
	}

	int currentNode = size;

	while(currentNode!=1 && heapArray[currentNode/2].dist > e.dist)
	{
		heapArray[currentNode-1]=heapArray[currentNode/2];
		currentNode/=2;
	}

	heapArray[currentNode-1]=e;
	mapVidxToArray[e.vidx]=e.dist;
}

const heapElem & 
MinHeap::Top()
{
	heapElem e;
	e=heapArray[1];
	return e;
}

void 
MinHeap::Pop()
{	
	heapArray[1].dist=0;
	heapElem last= heapArray[size--];

	int currentNode = 1;
	int child = 2;

	while (child <= size)
	{
	if(child < size && heapArray[child].dist > heapArray[child +1].dist)
			child++;

	if(last.dist <= heapArray[child].dist)
			break;

		heapArray[currentNode] = heapArray[child];
		currentNode = child;
		child *= 2;
	}

	heapArray[currentNode] = last;
	size--;
}

  
void MinHeap::Modify(const heapElem& e)
{
	int currentNode;

	if(0/*!IsInHeap(e)*/)
		Push(e);
	else
	{
		for(int j=1; j<=size; j++)
		{
			if(heapArray[j].vidx == e.vidx)	
			{
				heapArray[j]= e;
				mapVidxToArray[e.vidx]=1;
				currentNode=j;
				j==size;
			}
		}
	//change dist val

		while(heapArray[currentNode/2].dist > heapArray[currentNode].dist || currentNode/2<1)
		{
		        while(currentNode!=1 && heapArray[currentNode/2].dist > e.dist)
        		{
  		              heapArray[currentNode-1]=heapArray[currentNode/2];
        		        currentNode/=2;
		        }

        		heapArray[currentNode-1]=e;
		}

                while(heapArray[2*currentNode].dist<heapArray[currentNode].dist || 2*currentNode<=size)
                {
		        int child = currentNode*2;
			heapElem here=e;

	 	        while (child <= size)
		        {
	        	        if(child < size && heapArray[child].dist > heapArray[child +1].dist)
	                	        child++;

		                if(here.dist <= heapArray[child].dist)
		                        break;

		                heapArray[currentNode] = heapArray[child];
		     	        currentNode = child;
	        	        child *= 2;
	        	}
	      		heapArray[currentNode] = here;
		}
	}

}

bool MinHeap::IsEmpty()
{
	if(heapArray[1].dist==0)
		return true;
	else
		return false;	
}

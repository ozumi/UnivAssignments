#include "minheap.h"

// Destructor
MinHeap::~MinHeap()
{
	std::cout<<"d";
	delete []heapArray;
	delete []mapVidxToArray;
}

void 
MinHeap::Push(const heapElem& e)
{
	size++;
	
	if(size==capacity)
	{
		heapElem *tp1 = new heapElem[capacity*2];
		unsigned int* tp2 = new unsigned int[capacity*2];
		
		std::copy(heapArray, heapArray+capacity, tp1);
		std::copy(mapVidxToArray, mapVidxToArray+capacity, tp2);

		delete[] heapArray;
		delete[] mapVidxToArray;

		heapArray = tp1;
		mapVidxToArray = tp2;
	}

	int currentNode = size-1;
	
	while(currentNode!=1 && heapArray[currentNode/2].dist > e.dist)
	{
		heapArray[currentNode]=heapArray[currentNode/2];
		currentNode/=2;
std::cout<<"d";
	}
	
	heapArray[currentNode]=e;
	mapVidxToArray[e.vidx]=currentNode;

}

const heapElem & 
MinHeap::Top()
{
	return heapArray[1];
	
}

void 
MinHeap::Pop()
{	
	heapElem last = heapArray[size];
	
	int currentNode = 1;
	int child = 2;

	while(child <= size)
	{
		if(child<size && heapArray[child].dist > heapArray[child+1].dist)
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
	if(!IsInHeap(e))
		Push(e);
	else
	{
		int index = mapVidxToArray[e.vidx];
		heapElem here = heapArray[index];
		int current = index;
		int child = current*2;

		if(here.dist != e.dist)
		{
			while(current!=1 && heapArray[current/2].dist > heapArray[current].dist)
			{	heapArray[current]=heapArray[current/2];
				current/=2;
				mapVidxToArray[heapArray[current].vidx]=current;
			}

                        if(child < size && heapArray[child].dist > heapArray[child+1].dist)
                                child++;
		
			while(heapArray[child].dist < heapArray[current].dist && child<=size)
			{
                	        heapArray[current] = heapArray[child];
                                current = child;
                                child = current*2;
				mapVidxToArray[heapArray[current].vidx]=current;
                        
				if(child < size && heapArray[child].dist > heapArray[child+1].dist)
                        	        child++;
                        }

			heapArray[current]=here;
		}	
	}
}


bool MinHeap::IsEmpty()
{
	if(size=0)
		return true;
	else
		return false;
	
}

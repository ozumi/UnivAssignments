#include "minheap.h"
#include "minheap.cpp"
#include <iostream>

int main()
{
	Minheap m(3);
	MinHeap::heapElem e;
	e.dist=9;
	e.vidx=7;

	heapElem d;
	d.dist=8;
	e.vidx=1;

	m.Push(e);
	m.Modify(e);
	m.Top().dist;
	m.Pop();
	std::cout << IsEmpty();


	
	return 0;
}

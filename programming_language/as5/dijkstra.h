#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "minheap.h"
#include <iostream>

/** 
  * Assignment 5 for CSE231 Data Structures
  *
  * 2014. 1. 4
  *
  */

class graphNode {
public:
	unsigned int idx;  // vertex index
	double weight;     // edge weight
	graphNode* link;   // link to next node
};

// Dijkstra class
class Dijkstra {
public:
	Dijkstra() { mheap = NULL; adjList = NULL; };
	~Dijkstra();
	
	void ReadGraph(const char* file);
	
	double FindPath(const unsigned int v0, const unsigned int v1);
	
private:
	MinHeap* mheap;
	graphNode* adjList;
};

#endif

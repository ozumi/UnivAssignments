#include "dijkstra.h"
#include <fstream>

/** 
  * Assignment 5 for CSE231 Data Structures
  *
  * 2014. 1. 4
  *
  */

int vtxnum, edgnum;

Dijkstra::~Dijkstra()
{
	delete[] adjList;
	delete[] mheap;
}

void 
Dijkstra::ReadGraph(const char* file)
{
std::cout<<"F";
	std::ifstream is;
	int id, preid;
	unsigned int next;
	double wt;
	is.open(file);

	is >> vtxnum >> edgnum;

	mheap = new MinHeap(vtxnum);
	adjList = new graphNode[vtxnum];
	graphNode* adj;
	graphNode* preadj;

	for(int i=0; i<edgnum; i++)
	{
		is >> id >> next >> wt;
		adj = &adjList[id];
		
		if(i==0)
			preid=id;

		if(preid!=id)
			preadj->link = NULL;
	
		adj->link = new graphNode;
		adj->link->idx=next;
		adj->link->weight=wt;
		preid = id;
		preadj = adj;
	}

	is.close();
}

double 
Dijkstra::FindPath(const unsigned int v0, const unsigned int v1)
{
	double dist[vtxnum];
	int prev[vtxnum];
	int order[vtxnum];
	bool s[vtxnum];
	unsigned int v, u;
	double d, w;

	for(int i=0; i<vtxnum; i++)
	{
		s[i]=false;
		dist[i]=INT_MAX;
		prev[i]=0;
		order[i]=0;	
	}

	dist[v0]=0;
	graphNode* adj;
	adj = &adjList[v0];

	while(adj->link != NULL)
	{
		heapElem e;
		e.vidx=adj->link->idx;
		e.dist=adj->link->weight;
		dist[e.vidx]=e.dist;	
		mheap->Push(e);
		adj = adj -> link;
	}	

	while(!mheap->IsEmpty())
	{
		d = mheap->Top().dist;
		v = mheap->Top().vidx;
		mheap->Pop();
		
		s[v] = true;

		if(v==v1)
			break;
		
		adj = &adjList[v];

		while(adj -> link !='\0')
		{	
			w = adj->link->weight;
			u = adj->link->idx;

			if(!s[u] && dist[u] > w + dist[v])
			{
				dist[u]=dist[v]+w;
				heapElem e;
				e.vidx=u;
				e.dist=dist[u];
				mheap->Modify(e);
				prev[u]=v;	
			}
		adj = adj -> link;
	
		}
	}

	if(v!=v1)
	{
		std::cout<<"No Path";
		return -1;
	}
	int i=1, a=v1;
	order[0] = v1;

	while(prev[a]!=v0)
	{
		order[i]=prev[a];
		a=prev[a];
		i++;	
	}
	order[i]=v0;

	for(; i>0; i--)
		std::cout<<order[i] << ",";
	std::cout<<order[i]<<std::endl;
	std::cout<<"Distance : ";

	return dist[v1];

}


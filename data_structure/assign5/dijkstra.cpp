#include "dijkstra.h"
#include <fstream>


/** 
  * Assignment 5 for CSE231 Data Structures
  *
  * 2014. 1. 4
  *
  */



Dijkstra::~Dijkstra()
{
	delete[] adjList;
	delete[] mheap;
}
	
void 
Dijkstra::ReadGraph(const char* file)
{
	std::ifstream is;
	char vtxnum, edgnum, index, edge, nextnode;
	is.open(file);

	is >> vtxnum >> edgnum;

	mheap = new MinHeap(static_cast<int>(vtxnum));
       	adjList = new graphNode[static_cast<int>(vtxnum)];

	int i=0, id, preid;
	is >> index >> nextnode >> edge;
	id=static_cast<int>(index);

        adjList[id].idx=static_cast<int>(nextnode);
        adjList[id].weight=static_cast<double>(edge);
	graphNode temp;
//	temp=adjList[id]->link;

	preid=id;
	
	for(; i<static_cast<int>(edgnum); i++)
	{
		is >> index >> nextnode >> edge; 
		
		id=static_cast<int>(index);
	
		if(preid!=id)
		{	
//			temp=adjList[id];
		}
		else
		{
		temp.idx=static_cast<int>(nextnode);
		temp.weight=static_cast<double>(edge);

		temp.link = new graphNode;
//		temp = temp.link;
		preid=id;
		}
	}
	is.close();
}


double 
Dijkstra::FindPath(const long int v0, const long int v1)
{
	graphNode temp;
	

	int dist[100];
	int prev[100];
	int order[100];
	bool s[100];
	int v=0, d=0, w=0, u=0;

	for(int v=0; v<100; v++)
	{
		s[v]=false;
		dist[v]=1000;
		prev[v]=v0;
		order[100]=v0;
		s[v]=0;
	}

	dist[v0]=0;
	int b=0;
		
//	temp=adjList[v0];

//	while(temp.link.idx!=adjList[v0])
	{	v=temp.idx;
		d=temp.weight;
//		temp=temp.link;
		dist[v]=d;
		prev[v]=v0;
		heapElem e;
		e.vidx=v;
		e.dist=d;
		mheap->Modify(e);
	}

	while(!mheap->IsEmpty())
	{
		v=mheap->Top().vidx;
		d=mheap->Top().dist;
		mheap->Pop();
		
	s[v]=true;
		
		if(v==v1) 
			break;
		
		temp=adjList[v];
		while(/*adjList[v].link[c].weight!=*/0)
		{
			u=temp.idx;
			w=temp.weight;
			
			if(!s[u]&&dist[u]> w + dist[v])
			{	dist[u]=dist[v]+w;
				heapElem e;
				e.vidx=u;
				e.dist=d;
				mheap->Modify(e);
				prev[u]=v;	
			}
//		temp=temp.link;
		}
	}
	
	int i=1, a=v0;	
	order[0]=v0;
	while(prev[a]!=v0)
	{
		order[i]=prev[a];
		a=prev[a];
		i++;
	}
	i++;
	order[i]=v0;
	
	for(; i>0; i--)
		std::cout<<order[i] << ",";

std::cout<<order[i]<<std::endl;
std::	cout<<"Distance : ";

	double answer = dist[v1];

      //  delete[] dist;
    //    delete[] prev;
  //      delete[] order;
//        delete[] s;

	return answer;
}
	

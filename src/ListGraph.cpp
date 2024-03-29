// ListGraph.cpp
/*
*
* @Author: Nick Collins
* Implements the ListGraph.h, given by pre-written code
* @Cite: Many of these methods were developed in class
*
*/



#include "ListGraph.h"

//Uses the constructor developed in class
ListGraph::ListGraph(int numNodes){
	edgeList.resize(numNodes);
	num_edges=0;
}

// Not implemented.
ListGraph::~ListGraph(){
}


void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
	edgeList[u].push_back(std::make_pair(v,weight));
	edgeList[v].push_back(std::make_pair(u,weight));
	num_edges++;
}

//Developed in class
EdgeWeight ListGraph::weight(NodeID u, NodeID v) const{
	edgeList[u];
	EList::const_iterator it;
	for(it=edgeList[u].begin(); it!=edgeList[u].end(); it++){
		NWPair theEdge=*it; //Not a pointer!
		if(theEdge.first==v)
			return theEdge.second;
	}
	return 0.0;
}

// ...also developed in class
std::list<NWPair> ListGraph::getAdj(NodeID u) const{
	return edgeList[u];
}

unsigned ListGraph::degree(NodeID u) const{
	return edgeList[u].size();
}

unsigned ListGraph::size() const{
	return edgeList.size();
}

unsigned ListGraph::numEdges() const{
	return num_edges;
}

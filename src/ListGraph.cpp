// ListGraph.cpp

#include "ListGraph.h"

//Uses the constructor developed in class
ListGraph::ListGraph(int numNodes){
	edgeList.resize(numNodes);
	num_edges=0;
}

// Not implemented.
ListGraph::~ListGraph(){
}

//TODO
void addEdge(NodeID u, NodeID v, EdgeWeight weight){

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

//TODO
unsigned ListGraph::degree(NodeID u) const{
	return 0;
}

//TODO
unsigned ListGraph::size() const{
	return 0;
}

//TODO
unsigned ListGraph::numEdges() const{
	return 0;
}
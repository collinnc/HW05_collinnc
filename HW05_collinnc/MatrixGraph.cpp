#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(unsigned num_nodes){
	M.resize(num_nodes);

	for(int i=0; i<num_nodes; i++){
		M[i].resize(num_nodes);
		for(int j=0;j<num_nodes;j++)
			M[i][j] =-1;
	}
}
MatrixGraph::~MatrixGraph(){
}

void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
	M[u][v] = weight;
	M[u][v] = weight;
}

EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const{
	return M[u][v];
}

std::list<NWPair> MatrixGraph::getAdj(NodeID u) const{
	std::list<NWPair>* ret = new std::list<NWPair>;
	for(int  i= 0; i<M[u].size(); i++){
		if(M[u][i]!=-1)
			ret->push_back(std::make_pair(i,M[u][i]));
	}
	return *ret;
}

unsigned MatrixGraph::degree(NodeID u) const{
	return getAdj(u).size();
}

unsigned MatrixGraph::size() const{
	return M[0].size()*M[0].size();
}

unsigned MatrixGraph::numEdges() const{
	return num_edges;
}

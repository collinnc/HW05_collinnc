// GraphAlgs.cpp
/*
*
* @Author Nick Collins
* @Date 12-3-2012
* CSE 274B Fall 2012
*
*Solves the Traveling Sales Person Problem by 
* the brute-force method
*
* @Cite: Brandon Sonoda for making me read the .h file and realize
*	that this project is easier than I was making it.
*	..and also for suggesting using the next_permutation method to 
*	make my life easier.
*
* @note: Attempts goals: A, B, C, D
*/
#include "GraphAlgs.h"
#include <algorithm>

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G){
	
	EdgeWeight bestTourLength;

	std::vector<NodeID> bestTour, cur_tour;

	bestTour.resize(G->size());
	cur_tour.resize(G->size());

	// Fill the "bestTour" with a sample tour, to be permutated,
	// and populating cur_tour
	for(int i =0; i<bestTour.size(); i++){
		bestTour.at(i) = i;
		cur_tour.at(i) = i;
	}

	 bestTourLength = tourLength(bestTour, G);
	 EdgeWeight cur_len = tourLength(cur_tour, G);

	  // Loop uses the simple linear comparison method
	 // next_permutation takes care of going through each possible path
	 while(next_permutation(cur_tour.begin(), cur_tour.end())){
		 
		 cur_len = tourLength(cur_tour, G);
		 
		 if(cur_len < bestTourLength){
			 bestTourLength = cur_len;
			 bestTour = cur_tour;
		 }
	 }

	return make_pair(bestTour, bestTourLength);
}

EdgeWeight tourLength(std::vector<NodeID> path, Graph* G){
	 
	EdgeWeight sum = 0; 
	for(int i=0; i<path.size(); i++){
		if(i!=path.size()-1)
			sum+=G->weight(i,i+1);
		else
			sum+=G->weight(i,0);
	}

	return sum;
}

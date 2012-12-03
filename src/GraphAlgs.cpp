// GraphAlgs.cpp
#include "GraphAlgs.h"
#include <algorithm>

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G){
	/*std::vector<NodeID> vec;
	float total_weight = 0;
	vec.resize(G->size());*/

	// setting it equal to DBL_MAX was taken from Sam Wolf
	EdgeWeight bestTourLength = DBL_MAX;

	std::vector<NodeID> bestTour, cur_tour;
	//int* seenIDs = new int[G->size()];

	bestTour.resize(G->size());
	cur_tour.resize(G->size());

	// Fill the "bestTour" with a sample tour, to be permutated
	for(int i =0; i<bestTour.size(); i++){
		bestTour.at(i) = i;
		cur_tour.at(i) = i;
	}

	 bestTourLength = tourLength(bestTour, G);
	 EdgeWeight cur_len = tourLength(cur_tour, G);

	 while(next_permutation(cur_tour.begin(), cur_tour.end())){
		 
		 cur_len = tourLength(cur_tour, G);
		 
		 if(cur_len < bestTourLength){

			 bestTourLength = cur_len;
			 bestTour = cur_tour;

		 }
	 }



	return make_pair(bestTour, bestTourLength);
}

//void swap(int one, int two){
//	int tmp = one;
//	one = two;
//	two = tmp;
//}

//int factorial(int fac){
//	if(fac ==1) return 1;
//	else return fac*factorial(fac-1);
//}

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


//std::pair<std::vector<NodeID>,  EdgeWeight> tour(int* arr, int n, int startingPoint, Graph* G){
//	if(n-startingPoint==1){
//	}
//}
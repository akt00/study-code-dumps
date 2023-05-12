#ifndef ALGORITHM_CONTAINER_DISJOINTSET
#define ALGORITHM_CONTAINER_DISJOINTSET
#include<vector>
// array implementation of disjoint set forest
// // this implementation employes "union by rank" and "pass compresion" methods
// only supports positive integer values
// the disjoint set implementation automaticaly assumes that the input to FIND operation is present in the sets
// thus, the user is responsible for keeping track of elements in the sets


namespace algorithm::container {

	class DisjointSet {
	private:
		unsigned maximum_bound;
		std::vector<unsigned> sets; 
		std::vector<unsigned> rank; // keeps track of the rank of each element
	public:
		explicit DisjointSet(unsigned max) : maximum_bound(max) {}
		void makeSet(unsigned);
		void unionSet(unsigned, unsigned);
		unsigned findSet(unsigned);
	};
}                

#endif // ALGORITHM_CONTAINER_DISJOINTSET
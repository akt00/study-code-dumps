#ifndef ALGORITHM_TREE_FIBONACCIHEAP
#define ALGORITHM_TREE_FIBONACCIHEAP
/**
* theoritical data structure (issues in real world adaptation)
* advantages in UNION operation over binary heap
* desirable when extract_min and decrease_key operations are minimal
*/


namespace algorithm::tree {

	/**
	* degree: No. of child nodes
	* mark: boolean to indicate if a node is removed since the last child node creation
	* next: level wise circular doubly linked list
	* prev: level wise circular doubly linked list
	* key: key value
	* value: data to store
	*/
	struct FibonacciNode {
	};


	template<typename K, typename V>
	class FibonacciHeap {
	private:
		unsigned num; // No. of elements?
		FibonacciHeap<K, V>* min;
	public:
		// make_heap
		FibonacciHeap() { num = 0; min = nullptr; }
		// insert the value with the key is prensent in the tree
		void insert(V value);
		// returns a pointer to the min key node
		FibonacciNode* minimum();
		void extractMin();
		void makeUnion();
		void decreasKey();
		void deleteNode();
	};

	template<typename K, typename V>
	void FibonacciHeap<K, V>::insert(V value);
}


#endif // !ALGORITHM_TREE_FIBONACCIHEAP

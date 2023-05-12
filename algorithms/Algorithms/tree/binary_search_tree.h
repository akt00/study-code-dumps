#ifndef ALGORITHM_TREE_BSTREE
#define ALGORITHN_TREE_BSTREE
// implementation of binary search tree
#include<iostream>
#include<vector>
#include<memory>
#include<utility>


namespace algorithm::tree {

	template<typename K, typename V>
	struct bst_node {
		K key;
		V value;
		bst_node<K, V>* left;
		bst_node<K, V>* right;
	};

	template<typename K, typename V>
	class BinarySearchTree {
	private:
		bst_node<K, V>* root;
		unsigned tree_size;
	public:
		BinarySearchTree() { root = nullptr, tree_size = 0; }
		BinarySearchTree(const BinarySearchTree&);
		BinarySearchTree& operator=(const BinarySearchTree&);
		~BinarySearchTree() { clear(); }
		void insert(K key, V value);
		auto find(K key) -> decltype(root) const; // nullptr if not found
		bool remove(K key);
		void clear() { clear(root); } // delete all nodes
		unsigned size() const { return tree_size; }
		void show_tree() const { show_tree(root, 0); } // debug
		std::unique_ptr<BinarySearchTree> inverse_tree() const; // inverse the tree for fun, no actual use..
	private: // hepler functions
		void insert(bst_node<K, V>* current, bst_node<K, V>* newNode);
		std::pair<bst_node<K, V>, bst_node<K, V>> find_node(K key) const; // returns parent and current nodes
		void clear(bst_node<K, V>* current);
		void show_tree(bst_node<K, V>* current, int num) const;
		void inverse_tree(bst_node<K, V>* current) const;
		std::vector<std::pair<K, V>> parent_first_vectorize() const; // parent node comes first before the children, used for copy constructor and insertion
		void parent_first_vectorize(std::vector<std::pair<K, V>>& vec, bst_node<K, V>* current) const;
	};

	template<typename K, typename V>
	BinarySearchTree<K, V>::BinarySearchTree(const BinarySearchTree<K,V>& arg) {
		
		tree_size = 0;
		root = nullptr;
		auto elements = arg.parent_first_vectorize();
		for (auto i : elements) {
			insert(i.first, i.second);
		}
	}
	
	template<typename K, typename V>
	BinarySearchTree<K, V>& BinarySearchTree<K, V>::operator=(const BinarySearchTree<K, V>& arg) {

		if (&arg != this) {
			tree_size = 0;
			root = nullptr;
			auto elements = arg.parent_first_vectorize();
			for (auto i : elements) {
				insert(i.first, i.second);
			}
		}
		return *this;
	}


	template<typename K, typename V>
	void BinarySearchTree<K, V>::insert(K key, V value) {

		auto newNode = new bst_node<K, V>{ key, value, nullptr, nullptr };
		tree_size++;
		if (root == nullptr) root = newNode;
		else insert(root, newNode);
	}

	template<typename K, typename V>
	void BinarySearchTree<K, V>::insert(bst_node<K, V>* current, bst_node<K,V>* newNode) {

		if (newNode->key < current->key) {
			if (current->left == nullptr) current->left = newNode;
			else insert(current->left, newNode);
		}
		else {
			if (current->right == nullptr) current->right = newNode;
			else insert(current->right, newNode);
		}
	}


	template<typename K, typename V>
	auto BinarySearchTree<K, V>::find(K key) -> decltype(root) const {

		auto ret = find_node(K, key);
		return ret.second;
	}

	template<typename K, typename V>
	std::pair<bst_node<K,V>, bst_node<K,V>> BinarySearchTree<K, V>::find_node(K key) const {
		// if current is nullptr, node not found
		auto parent = root;
		auto current = root;

		while (true) {
			if (current == nullptr || current->key == key) return { parent, current };
			
			parent = current;
			if (key < current->key) current = current->left;
			else current = current->right;
		}
	}

	template<typename K, typename V>
	bool BinarySearchTree<K, V>::remove(K key) {
		/*
		* case 1: current left is nullptr
		* case 2: current right is nullptr
		* case 3: current has children 
		*/
		auto ret = find_node(key);
		auto parent = ret.first;
		auto current = ret.second; // target node

		if (current == nullptr) return false;

		bool isLeft = current->key < parent->key;
		if (current->left == nullptr) {
			if (isLeft) parent->left = current->right;
			else parent->right = current->right;
		}
		else if (current->right == nullptr) {
			if (isLeft) parent->left = current->left;
			else parent->right = current->left;
		}
		else {
			// find max key from left nodes of current
			auto leftMax = current->left;
			auto leftMaxParent = current;

			while (leftMax->right != nullptr) {
				leftMaxParent = leftMax;
				leftMax = leftMax->right;
			}

			// if leftMax is not a child node of current
			if (leftMaxParent != current) leftMaxParent->right = leftMax->left;
			
			// replacing current with leftMax
			if (isLeft) parent->left = leftMax;
			else parent->right = leftMax;
			leftMax->left = current->left;
			leftMax->right = current->right;

			delete current;
		}
		tree_size--;
		return true;
	}

	template<typename K, typename V>
	void BinarySearchTree<K, V>::clear(bst_node<K, V>* current) {

		if (current != nullptr) {
			clear(current->left);
			clear(current->right);
			std::cout << "node " << current->key << " deleted...\n";
			delete current;
		}
	}

	template<typename K, typename V>
	void BinarySearchTree<K, V>::show_tree(bst_node<K, V>* current, int num) const {
		if(current != nullptr){
			show_tree(current->left, num * 2 + 1);
			std::cout << "key: " << current->key << " node num: " << num << std::endl;
			show_tree(current->right, num * 2 + 2);
		}
	}

	template<typename K, typename V>
	std::vector<std::pair<K, V>> BinarySearchTree<K,V>::parent_first_vectorize() const {

		std::vector<std::pair<K, V>> vec;
		parent_first_vectorize(vec, root);
		return vec;
	}

	template<typename K, typename V>
	void BinarySearchTree<K, V>::parent_first_vectorize(std::vector<std::pair<K, V>> &vec, bst_node<K,V>* current) const {

		if (current != nullptr) {
			std::pair<K, V> p { current->key, current->value };
			vec.push_back(p);
			parent_first_vectorize(vec, current->left);
			parent_first_vectorize(vec, current->right);
		}
	}

	template<typename K, typename V>
	std::unique_ptr<BinarySearchTree<K, V>> BinarySearchTree<K, V>::inverse_tree() const {

		using bst = BinarySearchTree<K, V>;
		std::unique_ptr<bst> uptr = std::make_unique<bst>(*this);
		if (uptr->root != nullptr) inverse_tree(uptr->root);
		return uptr;
	}

	template<typename K, typename V>
	void BinarySearchTree<K,V>::inverse_tree(bst_node<K, V>* current) const {

		if (current != nullptr) {
			inverse_tree(current->left);
			inverse_tree(current->right);

			auto temp = current->left;
			current->left = current->right;
			current->right = temp;
		}
	}
}

#endif // !ALGORITHM_TREE_BSTREE
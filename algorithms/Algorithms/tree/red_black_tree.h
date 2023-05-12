#ifndef ALGORITHM_TREE_RBTREE
#define ALGORITHM_TREE_RBTREE
#include<algorithm>
#include<iostream>

// 1. root is black
// 2. nil is black
// 3. child nodes of red are black
// 4. every path to nil node have the same number of black nodes
namespace algorithm::tree {

	enum class Color : char { RED, BLACK }; // 1 byte enum

	template<typename K, typename V>
	struct rbt_node{
		K key;
		V value;
		Color color;
		rbt_node<K, V>* parent;
		rbt_node<K, V>* left;
		rbt_node<K, V>* right;
	};

	template<typename K, typename V> // comprison operator < for type K should be implemented
	class RedBlackTree {
	private:
		rbt_node<K, V>* root; // root. parent is nil
		rbt_node<K, V>* nil; // nil node

	public:
		explicit RedBlackTree() : nil(new rbt_node<K, V>({}, {}, Color::BLACK, nullptr, nullptr, nullptr)) { root = nil; }
		RedBlackTree(const RedBlackTree&) = delete;
		RedBlackTree& operator=(const RedBlackTree&) = delete;
		~RedBlackTree() { clear(), delete nil; };
		rbt_node<K, V>* find(K key) const { find(key, root); } // returns a pointer to the node or nullptr(key not found)
		void insert(K key, V value);
		void remove(K key);
		void clear() { clear(root); }; // deallocates all nodes
		void show_tree() const { show_tree(root); } // debug
		
	private:
		rbt_node<K, V>* find(K key, rbt_node<K, V>* current) const; // helper function
		void left_rotation(rbt_node<K, V>* x); // rotate the subtree around current to the left
		void right_rotation(rbt_node<K, V>* y); // rotate to the right
		void insert_self_balancing(rbt_node<K, V>* current); // perform self balancing
		rbt_node<K, V>* min(rbt_node<K, V>* current) const; // find the minimum node from the subtree of current
		void transplant(rbt_node<K, V>* x, rbt_node<K, V>* y); // replace x with y
		void remove_self_balancing(rbt_node<K, V>* current); // perform self balancing
		void clear(rbt_node<K,V>* current); // helper functoin
		void show_tree(rbt_node<K, V>* current, int node_num = 0) const; // helper function. root = 0
	};

	template<typename K, typename V>
	rbt_node<K, V>* RedBlackTree<K, V>::find(K key, rbt_node<K, V>* current) const {

		if (current == nil) nullptr;
		else if (current->key == key) return current;
		else {
			if (key < current->key) return find(key, current->left);
			else return find(key, current->right);
		}
	}

	// x.parent.left/right, x.right, x.parent, y.left, y.parent, b.parent
	template<typename K, typename V>
	void RedBlackTree<K, V>::left_rotation(rbt_node<K, V>* x) {

		auto y = x->right;
		x->right = y->left; // x.right
		if (y->left != nil) y->left->parent = x; // b.parent
		y->parent = x->parent; // y.parent
		if (x->parent == nil) root = y;
		// x.parent.left/right
		else if (x->parent->left == x) x->parent->left = y; // left node
		else x->parent->right = y; // right node
		y->left = x; // y.left
		x->parent = y; // x.parent
	}

	// y.parent.left/right, y.parent, y.left, x.parent, x.right, b.parent
	template<typename K, typename V>
	void RedBlackTree<K, V>::right_rotation(rbt_node<K, V>* y) {

		auto x = y->left;
		y->left = x->right; // y.left
		if (x->right != nil) x->right->parent = y; // b.parent
		x->parent = y->parent; // x.parent
		if (y->parent == nil) root = x;
		// y.parent.left/right
		else if (y->parent->left == y) y->parent->left = x; // left node
		else y->parent->right = x; // right node
		x->right = y; // x.right
		y->parent = x; // y.parent
	}

	template<typename K, typename V>
	void RedBlackTree<K, V>::insert(K key, V value) {

		auto newNode = new rbt_node<K, V>{ key, value, Color::RED, nil, nil, nil };
		auto parent = nil;
		auto current = root;

		while (current != nil) {
			parent = current;
			if (newNode->key < current->key) current = current->left;
			else current = current->right;
		}

		newNode->parent = parent;

		if (parent == nil) root = newNode;
		else if (newNode->key < parent->key) parent->left = newNode;
		else parent->right = newNode;
		insert_self_balancing(newNode);
	}

	// case 1: root = red, recolor
	// case 2: uncle = red, recolor parent, grandparent, and uncle
	// case 3: triangle & uncle = black, rotate left/right around z's parent
	// case 4: line & uncle = black, rotate left/right around grandparent and recolor parent and grandparent
	template<typename K, typename V>
	void RedBlackTree<K, V>::insert_self_balancing(rbt_node<K, V>* current) {

		while (current->parent->color == Color::RED) { // while parent is red
			if (current->parent == current->parent->parent->left) { // if parent is a left node
				auto uncle = current->parent->parent->right; // uncle is right of grandparent
				if (uncle->color == Color::RED) { // if uncle is red
					current->parent->color = Color::BLACK;
					uncle->color = Color::BLACK;
					current->parent->parent->color = Color::RED;
					current = current->parent->parent; // current = grandparent
				}
				else {
					if (current == current->parent->right) { // if uncle is black and current is a right node
						current = current->parent;
						// rotate around grandparent of inserted node
						left_rotation(current);
					}
					current->parent->color = Color::BLACK;
					current->parent->parent->color = Color::RED;
					right_rotation(current->parent->parent);
				}
			}
			else { // do the opposite
				if (current->parent == current->parent->parent->right) {
					auto uncle = current->parent->parent->left;
					if (uncle->color == Color::RED) {
						current->parent->color = Color::BLACK;
						uncle->color = Color::BLACK;
						current->parent->parent->color = Color::RED;
						current = current->parent->parent;
					}
					else {
						if (current == current->parent->left) {
							current = current->parent;
							right_rotation(current);
						}
						current->parent->color = Color::BLACK;
						current->parent->parent->color = Color::RED;
						left_rotation(current->parent->parent);
					}
				}
			}
		}
		root->color = Color::BLACK;
	}

	template<typename K, typename V>
	rbt_node<K, V>* RedBlackTree<K, V>::min(rbt_node<K, V>* current) const {

		while (current->left != nil) {
			current = current->left;
		}
		return current;
	}

	template<typename K, typename V>
	void RedBlackTree<K, V>::transplant(rbt_node<K, V>* removed, rbt_node<K, V>* replacement) {

		if (removed->parent == this->nil) { // root
			this->root = replacement;
		}
		else if (removed == removed->parent->left) { // transplant repalacement to removed
			removed->parent->left = replacement;
		}
		else {
			removed->parent->right = replacement;
		}
		replacement->parent = removed->parent;
	}

	template<typename K, typename V>
	void RedBlackTree<K, V>::remove(K key) {

		auto target = find(key);
		if (target == nullptr) return;

		auto y = target;
		auto y_original_color = y->color;
		decltype(root) x;
		if (target->left == nil) { // if left is nil, insert right node to target
			x = target->right;
			transplant(target, target->right);
		}
		else if (target->right == nil) { // if right is nil, insert left node to target
			x = target->left;
			transplant(target, target->left);
		}
		else {
			y = min(target->right); // find minimum from right node children
			y_original_color = y->color;
			x = y->right; // x is y's right node
			if (y->parent == target) { // if target is parent, 
				x->parent = y;
			}
			else {
				transplant(y, y->right);
				y->right = target->right;
				y->right->parent = y;
			}
			transplant(target, y);
			y->left = target->left;
			y->left->parent = y;
			y->color = target->color;
		}
		if (y_original_color == Color::BLACK) { // if deleted node is black, perform balancing
			remove_self_balancing(x);
		}
	}

	template<typename K, typename V>
	void RedBlackTree<K, V>::remove_self_balancing(rbt_node<K, V>* current) {

		auto removed = current;
		while ((current != this->root) && (current->color == Color::BLACK)) {
			if (current == current->parent->left) {
				auto w = current->parent->right;
				if (w->color == Color::RED) {
					w->color = Color::BLACK;
					current->parent->color = Color::RED;
					this->left_rotation(current->parent);
					w = current->parent->right;
				}
				if ((w->left->color == Color::BLACK) && (w->right->color == Color::BLACK)) {
					w->color = Color::RED;
					current = current->parent;
				}
				else {
					if (w->right->color == Color::BLACK) {
						w->left->color = Color::BLACK;
						w->color = Color::RED;
						this->right_rotation(w);
						w = current->parent->right;
					}
					w->color = current->parent->color;
					current->parent->color = Color::BLACK;
					w->right->color = Color::BLACK;
					this->left_rotation(current->parent);
					current = this->root;
				}
			}
			else { // opposite
				auto w = current->parent->left;
				if (w->color == Color::RED) {
					w->color = Color::BLACK;
					current->parent->color = Color::RED;
					this->right_rotation(current->parent);
					w = current->parent->left;
				}
				if ((w->right->color == Color::BLACK) && (w->left->color == Color::BLACK)) {
					w->color = Color::RED;
					current = current->parent;
				}
				else {
					if (w->left->color == Color::BLACK) {
						w->right->color = Color::BLACK;
						w->color = Color::RED;
						this->left_rotation(w);
						w = current->parent->left;
					}
					w->color = current->parent->color;
					current->parent->color = Color::BLACK;
					w->left->color = Color::BLACK;
					this->right_rotation(current->parent);
					current = this->root;
				}
			}
		}
		current->color = Color::BLACK;
		delete removed;
	}

	template<typename K, typename V>
	void RedBlackTree<K, V>::clear(rbt_node<K, V>* current) {
		if (current != nil) {
			clear(current->left);
			clear(current->right);
			delete current;
		}
	}

	template<typename K, typename V>
	void RedBlackTree<K, V>::show_tree(rbt_node<K, V>* current, int node_num) const {
		if (current != nil) {
			auto color = (current->color == Color::BLACK) ? "BLACK" : "RED";
			std::cout << "key: " << current->key << " node num: " << node_num << " color: " << color << std::endl;
			show_tree(current->left, node_num * 2 + 1);
			show_tree(current->right, node_num * 2 + 2);
		}
	}
}

#endif // !ALGORITHM_TREE_RBTREE
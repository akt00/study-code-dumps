#pragma once

#include<iostream>
#include<cassert>
#include<vector>

// root is black
// nil is black
// children of red are black
// simple paths leaves have the same No. of black nodes
namespace rbtree {
	enum class Color : char {RED, BLACK}; // 1 byte
	// enum class Attribute {NIL, NODE}; might not be needed

	struct node {
		int key;
		Color color;
		node* parent;
		node* left;
		node* right;
	};

	class RedBlackTree {
	private:
		node *root;
		node *nil;
	public:
		explicit RedBlackTree() {
			nil = new node{-1, Color::BLACK, nullptr, nullptr, nullptr};
			root = nil;
		}

		RedBlackTree(const RedBlackTree&) = delete;
		RedBlackTree& operator=(const RedBlackTree&) = delete;

		~RedBlackTree() {
			delete nil;
			// delete all nodes...
		}

		node* find_node(int key) {
			return find_node(key, this->root);
		}

		node* find_node(int key, node* current) {
			if (key == current->key) {
				return current;
			}
			else if (current == this->nil) {
				return nullptr;
			}
			else {
				if (key < current->key) return find_node(key, current->left);
				else return find_node(key, current->right);
			}
		}

		// x.parent.(left/right), x.right, x.parent, y.left, y.parent, b.parent
		void left_rotation(node* current) {
			node* parent = current->right;
			current->right = parent->left; // x.right
			if (parent->left != this->nil) {
				parent->left->parent = current; // b.parent
			}
			parent->parent = current->parent; // y.parent
			if (parent->parent == this->nil) {
				this->root = parent;
			}
			else if (current->parent->left == current) { // x.parent(left/right)
				current->parent->left = parent;
			}
			else {
				current->parent->right = parent;
			}
			parent->left = current; // y.left
			current->parent = parent; // x.parent
		}

		// y.parent.(left/right), y.parent, y.left, x.parent, x.right, b.parent
		void right_rotation(node* current) {
			node* parent = current->left;
			current->left = parent->right; // y.left
			if (parent->right != this->nil) { // if not nil, reassign the parent pointer
				parent->right->parent = current; // b.parent
			}
			parent->parent = current->parent; // x.parent
			if (parent->parent == this->nil) { // if parent of top node is nil, set it to root
				this->root = parent;
			}
			else if (current->parent->left == current) { // y.parent.(left/right)
				current->parent->left = parent;
			}
			else {
				current->parent->right = parent;
			}
			parent->right = current; // x.right
			current->parent = parent; // y.parent
		}

		void rb_insert(int key) {
			// new node is red
			node* newNode = new node{ key, Color::RED, this->nil, this->nil, this->nil };
			node* parent = this->nil;
			node* current = this->root;

			// until current becomes nil
			while (current != this->nil) {
				parent = current;
				if (newNode->key < current->key) {
					current = current->left;
				}
				else {
					current = current->right;
				}
			}

			newNode->parent = parent;

			// if parent is nil
			if (parent == this->nil) {
				this->root = newNode;
			}
			else if (newNode->key < parent->key) {
				parent->left = newNode;
			}
			else {
				parent->right = newNode;
			}
			
			rb_insert_self_balance(newNode);
		}

		// case 1: root = red, recolor
		// case 2: uncle = red, recolor parent, grandparent, and uncle
		// case 3: triangle & uncle = black, rotate left/right around z's parent
		// case 4: line & uncle = black, rotate left/right around grandparent and recolor parent and grandparent
		void rb_insert_self_balance(node* current) {

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
							this->left_rotation(current);
						}
						current->parent->color = Color::BLACK;
						current->parent->parent->color = Color::RED;
						this->right_rotation(current->parent->parent);
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
								this->right_rotation(current);
							}
							current->parent->color = Color::BLACK;
							current->parent->parent->color = Color::RED;
							this->left_rotation(current->parent->parent);
						}
					}
				}
			}

			this->root->color = Color::BLACK;
		}

		void rb_transplant(node* removed, node* replacement) {

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

		// find the minimum node of current
		node* rb_min(node* current) {

			while (current->left != this->nil) {
				current = current->left;
			}

			return current;
		}

		void rb_delete(node* target) {

			auto y = target;
			auto y_original_color = y->color;
			node* x;
			if (target->left == this->nil) { // if left is nil, insert right node to target
				x = target->right;
				this->rb_transplant(target, target->right);
			}
			else if (target->right == this->nil) { // if right is nil, insert left node to target
				x = target->left;
				this->rb_transplant(target, target->left);
			}
			else {
				y = this->rb_min(target->right); // find minimum from right node children
				y_original_color = y->color;
				x = y->right; // x is y's right node
				if (y->parent == target) { // if target is parent, 
					x->parent = y;
				}
				else {
					this->rb_transplant(y, y->right);
					y->right = target->right;
					y->right->parent = y;
				}
				this->rb_transplant(target, y);
				y->left = target->left;
				y->left->parent = y;
				y->color = target->color;
			}
			if (y_original_color == Color::BLACK) { // if deleted node is black, perform balancing
				this->rb_delete_self_balance(x);
			}
		}

		void rb_delete_self_balance(node* current){
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

		void show_tree() {
			show_tree(this->root);
		}

		void show_tree(node* current, int node_num=0) {
			if (current != this->nil) {
				show_tree(current->left, node_num * 2 + 1);
				auto color = (current->color == Color::RED) ? "RED" : "BLACK";
				std::cout << "key = " << current->key << " node_num = " << node_num 
					<< " node_color = "  << color << std::endl;
				show_tree(current->right, node_num * 2 + 2);
			}
		}
	};

	void unittest() {
		std::srand((unsigned)time(0));
		using list = std::vector<int>;
		{
			std::cout << "test copy constructor & insertion copy\n";
			RedBlackTree rbt;
			rbt.rb_insert(9);

			// prohibited
			// RedBlackTree temp1 = rbt;
			// RedBlackTree temp2(rbt);
		}

		{
			std::cout << "test left_rotation...\n";
			list vec = { 2, 1, 5, 4, 6 };
			rbtree::RedBlackTree rbt;
			for (auto i : vec) {
				rbt.rb_insert(i);
			}
			rbt.show_tree();
			rbt.left_rotation(rbt.find_node(2));
			std::cout << "left rotated...\n";
			rbt.show_tree();
			std::cout << "passed...\n";
		}

		{
			std::cout << "test right_rotation...\n";
			list vec = { 4, 2, 5, 1, 3};
			rbtree::RedBlackTree rbt;
			for (auto i : vec) {
				rbt.rb_insert(i);
			}
			rbt.show_tree();
			rbt.right_rotation(rbt.find_node(4));
			std::cout << "right rotated...\n";
			rbt.show_tree();
			std::cout << "passed...\n";
		}

		{
			std::cout << "test self balancing...\n";
			list vec = { 8, 5, 15, 12, 19, 9, 13, 32 };
			rbtree::RedBlackTree rbt;
			for (auto i : vec) {
				rbt.rb_insert(i);
				std::cout << "inserted " << i << std::endl;
				// rbt.show_tree();
			}
			std::cout << "passed...\n";
		}

		{
			std::cout << "test deleting...\n";
			list vec = { 8, 5, 15, 12, 19, 9, 13, 32 };
			rbtree::RedBlackTree rbt;
			for (auto i : vec) {
				rbt.rb_insert(i);
			}
			rbt.show_tree();
			for (auto i = 3; i < 6; i++) {
				auto node = rbt.find_node(vec[i]);
				if (node != nullptr) {
					rbt.rb_delete(node);
				}
				std::cout << " deleted node : " << vec[i] << std::endl;
				rbt.show_tree();
			}
			std::cout << "passed...\n";
		}

		{
			std::cout << "test sorted initialization...\n";
			list vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
			rbtree::RedBlackTree rbt;
			for (auto i : vec) {
				rbt.rb_insert(i);
			}
			rbt.show_tree();
			std::cout << "passed...\n";
		}
	}
}

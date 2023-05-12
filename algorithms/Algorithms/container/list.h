#ifndef ALGORITHM_CONTAINER_LIST
#define ALGORITHM_CONTAINER_LIST
// implementation of doubly linked list
#include<iterator>
#include<functional>


namespace algorithm::container {

	// node for linked list
	template<typename V>
	struct ListNode {
		V value;
		ListNode<V>* next;
		ListNode<V>* prev;
	};

	// doubly linked list class
	// either operator< must be implemented for custom objects or custom comparator must be provided if merge or sort operation are used
	template<typename V>
	class list {
	public:
		// forward iterator
		class ListIterator {
		public:
			using iterator_category = std::forward_iterator_tag;
			using value_type = V;
			using pointer = V*;
			using reference = V&;

			ListIterator(ListNode<V>* other) : current_ptr(other) {}
			ListIterator(const ListIterator& other) : current_ptr(other.current_ptr) {}
			ListIterator& operator=(const ListIterator& other) { current_ptr = other.current_ptr; return *this; }
			ListIterator& operator++() { if (current_ptr != nullptr) current_ptr = current_ptr->next; return *this; } // prefix ++
			ListIterator operator++(int) { ListIterator ret = *this; ++(*this); return ret; } // postfix ++
			reference operator*() { return current_ptr->value; }
			pointer operator->() { return &current_ptr->value; }
			friend bool operator==(const ListIterator& l, const ListIterator& r) {
				if (l.current_ptr == r.current_ptr) return true;
				return false;
			}
			friend bool operator!=(const ListIterator& l, const ListIterator& r) {
				if (l.current_ptr != r.current_ptr) return true;
				return false;
			}

		private:
			ListNode<V>* current_ptr;
		};

		list() { list_size = 0, head = nullptr, tail = nullptr; }
		list(const list<V>& other);
		list& operator=(const list<V>& other);
		~list() { clear(); }
		const V& front() const { return head->value; } // must call empty() in advance
		const V& back() const { return tail->value; } // must call empty() in advance
		ListIterator begin() const { return ListIterator(head); } // return an iterator
		ListIterator end() const { return ListIterator(nullptr); } // return the end of the iterator
		bool empty() const { return (list_size == 0) ? true : false; }
		unsigned size() const { return list_size; }
		ListIterator find(V key) const { for (auto iter = begin(); iter != end(); iter++) if(*iter == key) return iter; return end(); }
		// following push implementations call copy consturctor twice on user objects
		void push_front(V data);
		void push_back(V data);
		void pop_front();
		void pop_back();
		void clear();
		template<typename Comparator = std::less<V>>
		void merge(list<V>& other, Comparator comp = {}); // merge another list. the input list will be destroyed upon completion of merging.
		template<typename Comparator = std::less<>>
		void sort(Comparator comp = {});// performs merge sort

		// merge implementation is based on https://www.geeksforgeeks.org/merge-sort-for-doubly-linked-list/
	private:
		unsigned list_size; // number of nodes in list
		ListNode<V>* head; // pointer to the head node
		ListNode<V>* tail; // pointer to the tail node

		// helper functions below
		template<typename Comparator = std::less<>>
		auto merge_sort(ListNode<V>* head, Comparator comp = {}) -> decltype(head);
		auto split(ListNode<V>* head) -> decltype(head);
		template<typename Comparator = std::less<>>
		auto merge_nodes(ListNode<V>* left, ListNode<V>* right, Comparator comp = {}) -> decltype(head);
	};


	// list method implementatoins below

	template<typename V>
	list<V>::list(const list<V>& other) {

		list_size = 0;
		head = nullptr;
		tail = nullptr;
		for (auto i = other.begin(); i != other.end(); i++) {
			this->push_back(*i);
		}
	}

	template<typename V>
	list<V>& list<V>::operator=(const list<V>& other) {

		if (&other != this) {
			this->clear();
			for (auto i = other.begin(); i != other.end(); i++) {
				this->push_back(*i);
			}
		}
		return *this;
	}

	template<typename V>
	inline void list<V>::push_front(V value) {
		ListNode<V>* new_node = new ListNode<V>{ value, nullptr, nullptr };
		if (head == nullptr) {
			head = new_node;
			tail = new_node;
		}
		else {
			head->prev = new_node;
			new_node->next = head;
			head = new_node;
		}
		list_size++;
	}

	template<typename V>
	inline void list<V>::push_back(V value) {
		ListNode<V>* new_node = new ListNode<V>{ value, nullptr, nullptr };
		if (tail == nullptr) {
			head = new_node;
			tail = new_node;
		}
		else {
			tail->next = new_node;
			new_node->prev = tail;
			tail = new_node;
		}
		list_size++;
	}

	template<typename V>
	inline void list<V>::pop_front() {
		if (head != nullptr) {
			auto temp = head;
			if (head->next == nullptr) {
				head = nullptr;
				tail = nullptr;
			}
			else {
				head = head->next;
				head->prev = nullptr;
			}
			list_size--;
			delete temp;
		}
	}

	template<typename V>
	inline void list<V>::pop_back() {
		if (tail != nullptr) {
			auto temp = tail;
			if (tail->prev == nullptr) {
				head = nullptr;
				tail = nullptr;
			}
			else {
				tail = tail->prev;
				tail->next = nullptr;
			}
			list_size--;
			delete temp;
		}
	}

	template<typename V>
	inline void list<V>::clear() { while (!empty()) pop_back(); }

	template<typename V>
	template<typename Comparator>
	inline void list<V>::merge(list<V>& other,  Comparator comp) {

		auto current1 = head;
		auto current2 = other.head;
		decltype(head) newHead = nullptr;
		decltype(tail) newTail = nullptr;
		this->list_size = 0;

		while (current1 != nullptr && current2 != nullptr) {
			list_size++;
			if (comp(current1->value, current2->value) == true) {
				if (newHead == nullptr) {
					newHead = current1;
					newTail = current1;
				}
				else {
					newTail->next = current1;
					current1->prev = newTail;
					newTail = newTail->next;
				}
				current1 = current1->next;
			}
			else {
				if (newHead == nullptr) {
					newHead = current2;
					newTail = current2;
				}
				else {
					newTail->next = current2;
					current2->prev = newTail;
					newTail = newTail->next;
				}
				current2 = current2->next;
			}
		}

		while (current1 != nullptr) {
			list_size++;
			if (newHead == nullptr) {
				newHead = current1;
				newTail = current1;
			}
			else {
				newTail->next = current1;
				current1->prev = newTail;
				newTail = newTail->next;
			}
			current1 = current1->next;
		}

		while (current2 != nullptr) {
			list_size++;
			if (newHead == nullptr) {
				newHead = current2;
				newTail = current2;
			}
			else {
				newTail->next = current2;
				current2->prev = newTail;
				newTail = newTail->next;
			}
			current2 = current2->next;
		}

		head = newHead;
		tail = newTail;

		other.head = nullptr;
		other.tail = nullptr;
		other.list_size = 0;
	}

	template<typename V>
	template<typename Comparator>
	inline void list<V>::sort(Comparator comp) {

		head = merge_sort(head, comp);
		if (head == nullptr) tail = nullptr;
		else {
			auto current = head;
			while (current->next != nullptr) {
				current = current->next;
			}
			tail = current;
		}
	}

	// break down the list nodes into a single node and merge them
	template<typename V>
	template<typename Comparator>
	inline auto list<V>::merge_sort(ListNode<V>* head, Comparator comp) -> decltype(head) {

		if (head == nullptr || head->next == nullptr) return head;

		auto rightHead = split(head);
		head = merge_sort(head);
		rightHead = merge_sort(rightHead);
		return merge_nodes(head, rightHead, comp);
	}

	template<typename V>
	inline auto list<V>::split(ListNode<V>* head) -> decltype(head) {

		auto fast = head;
		auto slow = head;
		while (fast->next != nullptr && fast->next->next != nullptr) {
			fast = fast->next->next;
			slow = slow->next;
		}
		auto temp = slow->next;
		slow->next = nullptr;
		return temp;
	}

	template<typename V>
	template<typename Comparator>
	inline auto list<V>::merge_nodes(ListNode<V>* left, ListNode<V>* right, Comparator comp) -> decltype(head) {

		if (left == nullptr) return right;
		if (right == nullptr) return left;
		if (comp(left->value, right->value) == true) {
			left->next = merge_nodes(left->next, right, comp);
			left->next->prev = left;
			left->prev = nullptr;
			return left;
		}
		else {
			right->next = merge_nodes(left, right->next, comp);
			right->next->prev = right;
			right->prev = nullptr;
			return right;
		}
	}
}

#endif // !ALGORITHM_CONTAINER_LIST
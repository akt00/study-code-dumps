#ifndef ALGORITHM_CONTAINER_STACK
#define ALGORITHM_CONTAINER_STACK
// implementation of stack with linked list

#ifndef ALGORITHM_CONTAINER_QUEUE
#include"queue.h"
#endif


namespace algorithm::container {

	template<typename T>
	class stack {
	public:
		stack();
		stack(const stack<T>& other);
		~stack();
		stack<T>& operator=(const stack<T>& other);

		bool empty() const;
		unsigned size() const;
		const T& top() const; // calling top() while empty() causes an error
		void push(T data); // this implementation call copy consturctor twice on user objects
		void pop();
		void clear(); // erase all elements
		void swap(stack<T>& other);

	private:
		QueueStackNode<T>* head;
		unsigned stack_size;
		// helper function for copy constuctor/insertion
		void RecursivePush(QueueStackNode<T>* current);
	};


	// stack implementatinos below

	template<typename T>
	stack<T>::stack() {

		head = nullptr;
		stack_size = 0;
	}

	template<typename T>
	stack<T>::stack(const stack<T>& other) {

		head = nullptr;
		stack_size = 0;
		RecursivePush(other.head);
	}

	template<typename T>
	stack<T>& stack<T>::operator=(const stack<T>& other) {

		if (&other != this) {
			clear();
			RecursivePush(other.head);
		}
		return *this;
	}

	template<typename T>
	stack<T>::~stack() { clear(); }

	template<typename T>
	inline const T& stack<T>::top() const { return head->data; }

	template<typename T>
	inline bool stack<T>::empty() const { return (stack_size == 0) ? true : false; }

	template<typename T>
	inline unsigned stack<T>::size() const { return stack_size; }
	
	// this implementation calls copy constructor twice
	template<typename T>
	inline void stack<T>::push(T data) {

		auto new_node = new QueueStackNode<T>{ data, head };
		head = new_node;
		stack_size++;
	}

	template<typename T>
	inline void stack<T>::pop() {

		if (!empty()) {
			auto temp = head;
			head = head->next;
			delete temp;
			stack_size--;
		}
	}

	template<typename T>
	inline void stack<T>::clear() { while (!empty()) pop(); }

	template<typename T>
	inline void stack<T>::swap(stack<T>& other) {

		if (&other != this) {
			auto temp = head;
			head = other.head;
			other.head = temp;

			auto tmp = other.stack_size;
			other.stack_size = stack_size;
			stack_size = tmp;
		}
	}

	template<typename T>
	inline void stack<T>::RecursivePush(QueueStackNode<T>* current) {

		if (current != nullptr) {
			RecursivePush(current->next);
			push(current->data);
		}
	}
}

#endif // !ALGORITHM_CONTAINER_STACK

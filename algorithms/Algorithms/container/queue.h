#ifndef ALGORITHM_CONTAINER_QUEUE
#define ALGORITHM_CONTAINER_QUEUE
// implementation queue with linked list


namespace algorithm::container {

	// this node is used for queue and stack
	template<typename T>
	struct QueueStackNode {
		T data;
		QueueStackNode<T>* next;
	};

	// queue interface
	template<typename T>
	class queue {
	public:
		queue();
		queue(const queue<T>& other);
		queue& operator=(const queue<T>& other);
		~queue();
		const T& front() const; // out, must call empty() in advance
		const T& back() const; // in, must call empty() in advance
		bool empty() const; // calling top() while empty() causes an error
		unsigned size() const;
		void push(T data); // this implementation call copy consturctor twice on user objects
		void pop();
		void clear();
		void swap(queue<T>& other);

	private:
		QueueStackNode<T>* head; // out
		QueueStackNode<T>* tail; // in
		unsigned queue_size;
	};


	// queue implementations below

	template<typename T>
	queue<T>::queue() {

		head = nullptr;
		tail = nullptr;
		queue_size = 0;
	}

	template<typename T>
	queue<T>::queue(const queue<T>& other) {

		head = nullptr;
		tail = nullptr;
		queue_size = 0;
		auto current = other.head;
		while (current != nullptr) {
			push(current->data);
			current = current->next;
		}
	}

	template<typename T>
	queue<T>& queue<T>::operator=(const queue<T>& other) {

		if (&other != this) {
			clear();
			auto current = other.head;
			while (current != nullptr) {
				push(current->data);
				current = current->next;
			}
		}
		return *this;
	}

	template<typename T>
	queue<T>::~queue() { clear(); }

	template<typename T>
	inline const T& queue<T>::front() const { return head->data; }

	template<typename T>
	inline const T& queue<T>::back() const { return tail->data; }

	template<typename T>
	inline bool queue<T>::empty() const { return (queue_size == 0) ? true : false; }

	template<typename T>
	inline unsigned queue<T>::size() const { return queue_size; }

	template<typename T>
	inline void queue<T>::push(T data) {

		auto temp = new QueueStackNode<T>{ data, nullptr };
		if (tail == nullptr) {
			head = temp;
			tail = head;
		}
		else {
			tail->next = temp;
			tail = tail->next;
		}
		queue_size++;
	}

	template<typename T>
	inline void queue<T>::pop() {

		if (!empty()) {
			auto temp = head;
			if (head == tail) { // avoid dangling pointer
				head = nullptr;
				tail = nullptr;
			}
			else {
				head = head->next;
			}
			queue_size--;
			delete temp;
		}
	}

	template<typename T>
	inline void queue<T>::clear() { while (!empty()) pop(); }

	template<typename T>
	inline void queue<T>::swap(queue<T>& other) {

		if (&other != this) {
			auto tmp_head = other.head;
			auto tmp_tail = other.tail;
			other.head = head;
			other.tail = tail;
			head = tmp_head;
			tail = tmp_tail;

			auto tmp_size = other.queue_size;
			other.queue_size = queue_size;
			queue_size = tmp_size;
		}
	}
}

#endif // !ALGORITHM_CONTAINER_QUEUE

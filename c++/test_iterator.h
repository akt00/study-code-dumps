#ifndef TEST_ITERATOR
#define TEST_ITERATOR

#include<iterator>
#include<iostream>


// simple container 
class Integers {
private:
	int m_data[200];
public:
	// iterator base class: https://en.cppreference.com/w/cpp/iterator/iterator
	// iterator requirements: https://www.cplusplus.com/reference/iterator/
	struct Iterator : std::iterator<std::forward_iterator_tag, int, std::ptrdiff_t, int*, int&> {

		Iterator(pointer ptr) : m_ptr(ptr) {}
		reference operator*() const { return *m_ptr; }
		pointer operator->() { return m_ptr; }
		Iterator& operator++() { m_ptr++; return *this; }
		Iterator operator&&(int) { Iterator tmp = *this; ++(*this); return tmp; }
		friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; }
		friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; }

	private:
		pointer m_ptr;
	};

	explicit Integers() {
		for (auto i = 0;  i < 200; i++) {
			m_data[i] = i;
		}
	}
	Iterator begin() { return Iterator(&m_data[0]); }
	Iterator end() { return Iterator(&m_data[200]); }
};

void test() {
	Integers integers;
	std::fill(integers.begin(), integers.end(), 3);
	for (auto i : integers) {
		std::cout << i << std::endl;
	}
}

#endif // !TEST_ITERATOR

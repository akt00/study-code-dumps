#ifndef TEST_SMART_POINTER
#define TEST_SMART_POINTER

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <functional>
#include <memory>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;


class node {
public:
	int value;
	unique_ptr<node, function<void(node*)>> next;

	explicit node(int i) {
		cout << "constructor called...\n";
		value = i;
		next = { nullptr };
	}
	~node() {
		cout << "destructor called...\n";
	}

	void show() {
		cout << "value = " << value << endl;
	}
};

using smart = unique_ptr<node, function<void(node*)>>;


void append(int i, smart &head) {
	smart tmp(new node{ i }, [](node* n) {delete n; cout << "custom deleter called\n"; });
	tmp->next = move(head);
	head = move(tmp);
}

void print(smart& head) {

	if (head == nullptr) {
		cout << endl;
		return;
	}
	else {
		cout << head->value << " ";
		print(std::ref(head->next));
	}
}


test_smart_pointer() {

	smart head(new node{ 99 }, [](node* n) {delete n; cout << "custom deleter called\n"; });
	append(199, std::ref(head));
	print(head);
	cout << "end of line...\n";
}

#endif

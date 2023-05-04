#pragma once
#include <iostream>


struct node {
	int key;
	node* next;
};

node* head;

void init() {
	head = nullptr;
}

void add(int key) {
	auto tmp = new node{ key, head };
	head = tmp;
}

void remove() {
	if (head) {
		auto tmp = head;
		head = head->next;
		delete tmp;
	}
}

void remove_entry(node* entry) {
	node** indir = &head;
	// indir = &head
	// *indir = head
	while ((*indir) != entry) indir = &(*indir)->next;
	auto copy = *indir;
	// change the address pointed to by indir to entry->next
	*indir = entry->next;
	delete copy;
}

void print_list() {
	while (head) {
		std::cout << head->key << std::endl;
		head = head->next;
	}
}

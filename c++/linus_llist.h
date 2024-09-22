#pragma once
#include <iostream>


struct Node {
	int key;
	Node* next;
};

Node* init_list() {
	return nullptr;
}

void add_node(Node** head, int key) {
	auto* new_head = new Node{key, *head};
	*head = new_head;
}

void remove_head(Node** head) {
	if (*head) {
		Node* temp = *head;
		*head = (*head)->next;
		delete temp;
	}
}

void remove_entry(Node** indir, Node* entry) {
	while ((*indir) != entry) indir = &(*indir)->next;
	auto* copy = *indir;
	*indir = entry->next;
	delete copy;
}

void print_list(Node* head) {
	while (head) {
		std::cout << head->key << "->";
		head = head->next;
	}
	std::cout << "nullptr" << std::endl;
}

int main(void) {
	Node* head = init_list();
	for (int i = 0;i < 5;i++) {
		add_node(&head, i);
	}
	remove_head(&head);
	remove_entry(&head, head->next->next);
	print_list(head);
}

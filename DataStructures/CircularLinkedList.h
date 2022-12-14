#pragma once
#include "NodeStruct.h"

template <typename T>
class CircularLinkedList {
private:
	Node<T>* head;
public:
	// Constructor
	CircularLinkedList(T A[], int n) {
		Node<T>* t;
		Node<T>* tail;

		head = new Node<T>;
		head->data = A[0];
		head->next = head;
		tail = head;

		for (int i{ 1 }; i < n; i++) {
			t = new Node<T>;
			t->data = A[i];
			t->next = tail->next;
			tail->next = t;
			tail = t;
		}

	}
	// Destructor
	~CircularLinkedList() {
		Node<T>* p = head;
		while (p->next != head) {
			p = p->next;
		}
		while (p != head) {
			p->next = head->next;
			delete head;
			head = p->next;
		}
		if (p == head) {
			delete head;
			head = nullptr;
		}
	}
	// Display method to print the data in each element
	void Display() {
		Node<T>* p = head;
		do {
			std::cout << p->data << " ";
			p = p->next;
		} while (p != head);
		std::cout << std::endl;
	}
	// NodeCount method for the number of nods in a linkedlist
	int NodeCount() {
		int count{};
		Node<T>* p = head;
		do {
			count++;
			p = p->next;
		} while (p != head);
		return count;
	}
	// Insert method for inserting a Node in a Circularlinkedlist
	void Insert(int index, T x) {
		if (index < 0 || index > NodeCount())
			return;
		Node<T>* t = new Node<T>;
		Node<T>* p = head;
		t->data = x;
		if (index == 0) {
			if (head == NULL) {
				head = t;
				head->next = head;
			}
			else {
				while (p->next != head) p = p->next;
				p->next = t;
				t->next = head;
				head = t;
			}
		}
		else {
			for (int i{ 1 }; i < index - 1; i++)
				p = p->next;
			t->next = p->next;
			p->next = t;
		}

	}
	// Delete method for deleting a Node
	void Delete(int index) {
		Node<T>* p = head;
		Node<T>* q;
		if (index < 0 || index > NodeCount())
			return;
		if (index == 1) {
			while (p->next != head)p = p->next;
			if (p == head) {
				delete head;
				head = NULL;
			}
			else {
				p->next = head->next;
				delete head;
				head = p->next;
			}

		}
		else {
			for (int i{ 1 }; i < index - 2; i++)
				p = p->next;
			q = p->next;
			p->next = q->next;
			delete q;
		}
	}
	
	

};
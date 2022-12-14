#pragma once
#include "NodeStruct.h"


template <typename T>
class LinkedList {
public:
	Node<T>* first;
public:
	//  Zero-argument constructor
	LinkedList() {
		first = NULL;
	}
	// Constructoor
	LinkedList(T A[], int n) {
		Node<T>* last;
		Node<T>* t;

		first = new Node<T>;
		first->data = A[0];
		first->next = NULL;
		last = first;

		for (int i{ 1 }; i < n; i++) {
			t = new Node<T>;
			t->data = A[i];
			t->next = NULL;
			last->next = t;
			last = t;
		}
	}
	// Destructor
	~LinkedList() {
		Node<T>* p = first;
		while (first) {
			first = first->next;
			delete p;
			p = first;
		}
	}
	// Display method to print the data in each element
	void Display() {
		Node<T>* p = first;
		while (p != 0) {
			std::cout << p->data << " ";
			p = p->next;
		}
		std::cout << std::endl;
	}
	// RecursiveDisplay
	void RecursiveDisplay() {
		static Node<T>* p = first;
		while (p != 0) {
			std::cout << p->data << std::endl;
			p = p->next;
			RecursiveDisplay();
		}
	}
	// NodeCount method for the number of nods in a linkedlist
	int NodeCount() {
		int count{};
		Node<T>* p{ first };
		while (p != 0 ) {
			count++;
			p = p->next;
		}
		return count;
	}
	// Sum method for summation of elements in a linkedlist
	T Sum() {
		T sum;
		Node* p{ first };
		while (p != 0) {
			sum += p->data;
			p = p->data;
		}
		return sum;
	}
	// Search for searching for an element in a linkedlist and returning a pointer
	Node<T>* Search(T key) {
		Node<T>* p{ first };

		while (p != NULL) {
			if (key = p->data)
				return p;
			p = p->next;
		}
		return NULL;
	}
	// Insert method for inserting a node in a linkedlist
	void Insert(int index, T x) {
		if (index < 0 || index > NodeCount())
			return;
		Node<T>* t = new Node<T>;
			t->data = x;
		if (index == 0) {
			t->next = first;
			first = t;
		}
		else {
			Node<T>* p = first;
			for (int i{}; i < index - 1; i++)
				p = p->next;
			t->next = p->next;
			p->next = t;
		}
	}
	// Delete method for deleting a node
	void Delete(int index) {
		Node<T>* p, q = NULL;
		if (index <0 && index> NodeCount())
			break;
		if (index == 1) {
			p = first;
			first = first->next;
			delete p;
		}
		else {
			q = p = first;
			for (int i{}; i < index - 1; i++) {
				q = p;
				p = p->next;
			}
			q->next = p->next;
			delete p;
		}
	}
	// Reverse method for reversing a LinkedList
	void Reverse() {
		Node<T>* p = first;
		Node<T>* q = NULL, * r = NULL;
		while (p != NULL) {
			r = q;
			q = p;
			p = p->next;
			q->next = r;
		}
		first = q;
	}
	// Concatenate method for concatenating two LinkedLists
	void Concatenate(LinkedList<T>& rhs) {
		Node<T>* p = first;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = rhs.first;
		rhs.first = NULL;
	}
	// IsLOOP method for determining whether a linked-list is LOOP or not
	bool IsLOOP() {
		Node<T>* p;
		Node<T>* q;
		p = q = first;
		do {
			p = p->next;
			q = q->next;
			if (q != NULL)
				q = q->next;

		} while (p && q && q != p);
		if (q == p)
			return true;
		else
			return false;

	}
	// 


};
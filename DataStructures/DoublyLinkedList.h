#pragma once
template <typename T>
struct DoublyNode {
	DoublyNode<T>* previous;
	T data;
	DoublyNode<T>* next;
};
template <typename T>
class DoublyLinkedList {
private:
	DoublyNode<T>* head;
public:
	// Constructor
	DoublyLinkedList(T A[], int n) {
		DoublyNode<T>* tail;
		head = new DoublyNode<T>;
		head->previous = nullptr;
		head->data = A[0];
		head->next = nullptr;
		tail = head;

		for (int i{ 1 }; i < n; i++) {
			DoublyNode<T>* t = new DoublyNode<T>;
			t->previous = tail;
			t->data = A[i];
			t->next = tail->next;
			tail->next = t;
			tail = t;

		}
	}
	// Destructor
	~DoublyLinkedList() {
		DoublyNode<T>* p = head;
		while (head) {
			head = head->next;
			delete p;
			p = head;
		}

	}
	// Display method to print the data in each element
	void Display() {
		DoublyNode<T>* p = head;
		while (p != nullptr) {
			std::cout << p->data << " ";
			p = p->next;
		}
		std::cout << std::endl;
	}
	// NodeCount method for the number of nods in a linkedlist
	int NodeCount() {
		int count{};
		DoublyNode<T>* p = head;
		while (p != nullptr) {
			count++;
			p = p->next;
		}
		return count;
	}
	// Insert method for inserting a Node in a Circularlinkedlist
	void Insert(int index, T x) {
		if (index < 0 || index > NodeCount()) {
			return;
		}
		DoublyNode<T>* p = head;
		DoublyNode<T>* t = new DoublyNode<T>;
		t->data = x;

		if (index == 0) {
			t->previous = nullptr;
			t->next = head;
			head->previous = t;
			head = t;
		}
		else {
			for (int i{ 1 }; i < index - 1; i++)
				p = p->next;
			t->previous = p;
			t->next = p->next;
			if (p->next) 
				p->next->previous = t;
			p->next = t;
		}

	}
	// Delete method for deleting a Node
	void Delete(int index) {
		DoublyNode<T>* p = head;
		if (index < 0 || index > NodeCount()) {
			return ;
		}
		if (index == 1) {
			head = head->next;
			if (head)
				head->previous = nullptr;

			delete p;
		}
		else {
			for (int i{ 1 }; i < index - 1; i++)
				p = p->next;
			p->previous->next = p->next;
			if (p->next)
				p->next->prevoius = p->previous;
				delete p;
		}
	}

};
#pragma once
#include "NodeStruct.h"

// Queue using LinkedList
template <typename T>
class QueueL {
private:
	Node<T>* front;
	Node<T>* rear;
public:
	// Constructor
	QueueL()
		:front{ nullptr }, rear{ nullptr } {
	}
	// Destructor
	~QueueL() {
		Node<T>* p{ front };
		while (front) {
			front = front->next;
			delete p;
			p = front;
		}
	}
	// Enqueue method
	void Enqueue(T x) {
		Node<T>* t = new Node<T>;
		if (t == nullptr)
			std::cout << "Queue ovbeflow!" << std::endl;
		else {
			t->data = x;
			t->next = nullptr;
			if (front == nullptr) {
				front = t;
				rear = t;
			}
			else {
				rear->next = t;
				rear = t;
			}
		}
	}
	// Dequeue method
	void Dequeue() {
		Node<T>* p;
		if (IsEmpty())
			std::cout << "Queue underflow!" << std::endl;
		else {
			p = front;
			front = front->next;
			delete p;
		}
	}
	// IsEmpty method
	bool IsEmpty(){
		if (front == nullptr)
			return true;
		else
			return false;
	}
	// Display method
	void Display() {
		Node<T>* p{ front };
		while (p) {
			std::cout << p->data;
			p = p->next;
			if (p != nullptr)
				std::cout << "<-";
		}
		std::cout << std::endl;
	}

};
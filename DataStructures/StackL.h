#pragma once
#include "NodeStruct.h"

// Stack using LinkedList
template <typename T>
class StackL {
private:
	Node<T>* top;
public:
	// Constructor
	StackL() {
		top = nullptr;
	}
	// Destructor
	~StackL() {
		Node<T>* p = top;
		while (top) {
			top = top->next;
			delete p;
			p = top;
		}
	}
	// push method
	void Push(T x) {
		Node<T>* t = new Node<T>;
		if (t == nullptr)
			std::cout << "Stack overflow!" << std::endl;
		else {
			t->data = x;
			t->next = top;
			top = t;
		}
	}
	// Pop method
	void Pop() {
		Node<T>* p;
		if (top == nullptr)
			std::cout << "Stack underflow!" << std::endl;
		else {
			p = top;
			top = top->next;
			delete p;
		}
	}
	// IsFool method
	bool IsFool() {
		Node<T>* t=new Node<T>;
		if (t)
			return true;
		else
			return false;
	}
	// IsEmpty method
	bool IsEmpty() {
		if (top)
			return false;
		else
			return true;
	}
	// StackTop method
	T StackTop() {
		if (top)
			return top->data;
	}
	// Peek method
	T Peek(int index) {
		if (IsEmpty())
			return -1;
		else {
			Node<T>* p = top;
			for (int i{}; p != nullptr && i < index - i; i++)
				p = p->next;
			if (p != nullptr)
				return p->data;
			else return -1;
		}

	}
};
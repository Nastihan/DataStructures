#pragma once

template <typename T>
class CircularQueue {
private:
	int size;
	int front;
	int rear;
	T* Q;
public:
	// Constructor
	CircularQueue(int size) 
		: size{ size } {
		front = 0;
		rear = 0;
		Q = new T[size];
	}
	// Destructor
	~CircularQueue() {
		delete[] Q;
	}
	// IsEmpty method
	bool IsEmpty() {
		if (front == rear)
			return true;
		else
			return false;
	}
	// IsFool method
	bool IsFool() {
		if ((rear + 1) % size == front)
			return true;
		else
			return false;
	}
	// Enqueue method
	void Enqueue(T x) {
		if (IsFool())
			std::cout << "Queue overflow!" << std::endl;
		else {
			rear = (rear + 1) % size;
			Q[rear] = x;
		}
	}
	// Dequeue method
	void Dequeue() {
		if (IsEmpty())
			std::cout << "Queue underflow!" << std::endl;
		else 
			front = (front + 1) % size;
	}
	// Display method
	void Display() {
		int i{ front + 1 };
		do {
			std::cout << Q[i];
			if (i < rear)
				std::cout << "<-";
			i = (i + 1) % size;
		} while (i != (rear + 1) % size);
	}
};
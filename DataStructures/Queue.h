#pragma once
template <typename T>
class Queue {
private:
	int size;
	int front;
	int rear;
	T* Q;
public:
	// Constructor
	Queue(int size)
		: size{size} {
		front = -1;
		rear = -1;
		Q = new T[size];
	}
	// Destructor
	~Queue() {
		delete[] Q;
	}
	// Enqueue method
	void Enqueue(T x) {
		if (IsFool()) 
			std::cout << "Queue overflow!" << std::endl;
		else {
			rear++;
			Q[rear] = x;
		}
		
	}
	// Dequeue method
	void Dequeue() {
		if (IsEmpty())
			std::cout << "Queue underflow!" << std::endl;
		else
			front++;
	}
	// Display method
	void Display() {
		for (int i{ front + 1 }; i <= rear; i++) {
			std::cout << Q[i];
			if (i < rear)
				std::cout << "<-";
		}
		std::cout << std::endl;
	}
	// IsEmpty method 
	bool IsEmpty() {
		if (rear == front)
			return true;
		else
			return false;
	}
	// IsFool method
	bool IsFool() {
		if (rear == size - 1)
			return true;
		else
			return false;
	}
	

	

};
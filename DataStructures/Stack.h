#pragma once
template <typename T>
class Stack {
private:
	int size;
	int top;
	T* S;
public:
	// Constructor
	Stack(int size)
		: size{ size }, top{ -1 } {
		S = new T[size];
	}
	// Copy constructor
	Stack(const Stack<T>& rhs) 
		:size{ rhs.size }, top{ rhs.top } {
			S = new T[size];
			for (int i{}; i < top; i++)
				S[i] = rhs.S[i];
	}
	// Move constructor
	Stack(Stack<T>&& rhs) {

	}
	// Destructor
	~Stack() {
		delete[] S;
	}
	// Push method
	void Push(T x) {
		if (IsFool())
			std::cout << "Stack overflow!" << std::endl;
		else {
			top++;
			S[top] = x;
		}
	}
	// Pop method
	void Pop() {
		if (IsEmpty())
			std::cout << "Stack underflow!" << std::endl;
		else 
			top--;
	}
	// Peek method
	T Peek(int index) {
		if (top - index + 1 < 0 || top - index + 1 == size)
			std::cout << "Invalid position!"  << std::endl;
		else
			return S[top - index + 1];
	}
	// IsFull method
	bool IsFool() {
		if (top == size - 1)
			return true;
		else
			return false;
	}
	// IsEmpty
	bool IsEmpty() {
		if (top == -1)
			return true;
		else
			return false;
	}
	// Display method
	void Display() {
		for (int i{ top }; i >= 0; i--) {
			std::cout << S[i] << " | ";
		}
		std::cout << std::endl;
	}
	// StackTop method
	T StackTop() {
		if (IsEmpty())
			std::cout << "Stack is empty" << std::endl;
		else
			return S[top];
	}
	// IsBalance metgod for paranthesis matching
	bool IsBalance(char C[]) {
		// Stack created
		Stack<char> stack(strlen(C));

		// Procesing through the string
		for (int i{}; i < strlen(C); i++) {
			// ( pushed to stack
			if (C[i] == '(')
				Push(C[i]);
			else if (C[i] == ')') {
				// Unbalanced 
				if (IsEmpty())
					return false;
				// Stack is not empty ) poped
				else
					Pop();
			}

		}
		// If IsEmpty is true expression is balanced 
		if (IsEmpty())
			return true;
		else
			return false;

	}


};
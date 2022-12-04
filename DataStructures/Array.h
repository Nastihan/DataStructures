#pragma once
#include <iostream>

template <typename T>
class Array
{
private:
	int size;
	int length;
	T* arr;
public:
	// Overloaded insertion operator
	friend std::ostream& operator<<(std::ostream& os, const Array<T>& rhs) {
		std::cout << "=================================================" << std::endl;
		os << "[";
		for (int i{}; i < rhs.length; i++) {
			os << rhs.arr[i] << " ";
		}
		os << "]" << std::endl;
		return os;
	}
	// Constructor
	Array(int size)
		: size{ size }, length{ 0 }, arr{ new T[size] } {
	}
	// Copy constructor
	Array(const Array<T>& source)
		: size{ source.size }, length{ source.length }, arr{ new T[size] } {
		for (int i{}; i < length; i++)
			arr[i] = source.arr[i];

	}
	// Move constructor
	Array(const Array<T>&& source)
		: size{ source.size }, length{ source.length }, arr{ source.arr } {
		source.arr = nullptr;
	}
	// Destructor
	~Array() { delete[] arr; }
	// Fill method
	void fill() {
		std::cout << "=================================================" << std::endl;
		std::cout << "how many elements would like to have in your array ?" << std::endl;
		int temp{};
		std::cin >> temp;
		length = temp;
		for (int i{}; i < length; i++) {
			std::cout << "enter element index [" << i << "]:" << std::endl;
			T temp;
			std::cin >> temp;
			arr[i] = temp;
		}
	}
	// Append metyhod 
	void append(T x) {
		if (length < size) {
			arr[length++] = x;
		}
	}
	// Inser method
	void insert(int index, T x) {
		if (index >= 0 && index <= length) {
			for (int i{ length }; i > index; i--) {
				arr[i] = arr[i - 1];
			}
			arr[index] = x;
			length++;
		}
	}
	// Delete method
	void Delete(int index) {
		if (index >= 0 && index < length) {
			for (int i[index]; i < length - 1; i++) {
				arr[i] = arr[i + 1];
			}
			length--;
		}

	}
	//linear search method for unique arrays
	int LinearSearch(T key) {
		for (int i{}; i < length; i++) {
			if (arr[i] == key)
				return i;
		}
		return -1;

	}
	// Binary search method for sorted arrays
	int BinarySearch(T key) {
		int high, low, mid;
		high = length - 1;
		low = 0;

		while (low <= high) {
			mid = (low + high) / 2;
			if (key == arr[mid])
				return mid;
			else if (key < arr[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}
		return -1;
	}
	// Recursive binary method search for sorted arrays
	int RecursiveBinarySearch(int low, int high, T key) {
		int mid;
		while (low <= high) {
			mid = (low + high) / 2;
			if (key == arr[mid])
				return mid;
			else if (key < arr[mid])
				return RecursiveBinarySearch(low, mid - 1, key);
			else
				return RecursiveBinarySearch(mid + 1, high, key);

		}
		return -1;
	}
	// Get method
	T Get(int index) {
		if (index >= 0 && index < length)
			return arr[index];
	}
	// Set method
	void Set(T x, int index) {
		if (index >= 0 && index < length)
			arr[index] = x;
	}
	/* Max method
	T Max() {
		T max{ arr[0] };
		for (int i{1};i < length;i++) {
			if(arr[i] > max)
				max = arr[i];
		}
		return max;
	}
	// Min method
	T Min() {
		T min{ arr[0] };
		for (int i{ 1 }; i < length;i++) {
			if (arr[i] < min)
				min = arr[i];
		}
		return min;
	}
	*/
	// Reverse method
	void Reverse() {
		int i, j;
		for ( i=0, j=length-1; i < j;i++,j--) {
			T temp;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}

	}
	



};

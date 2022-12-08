#pragma once
#include <iostream>

template <typename T>
struct Element {
	int i{};
	int j{};
	T x;
	 
};
template <typename T>
class SparseMatrix {


private:
	int m{};
	int n{};
	int num{};
	Element<T>* E;
public:
	
	// Constructor
	SparseMatrix(int m, int n, int num)
		: m{ m }, n{ n }, num{ num } {
		E = new Element<T>[num];
	}
	// Copy constructor
	SparseMatrix(const SparseMatrix& source)
		: m{ source.m }, n{ source.n }, num{ source.num } {
		E = new Element<T>[source.num];
		for (int i{}; i < source.num ;i++)
			E[i] = source.E[i];
	}
	// Move constructor
	SparseMatrix(SparseMatrix& source)
		: m{ source.m }, n{ source.n }, num{ source.num }, E{ source.E } {
		source.E = nullptr;
	}
	// Destructor
	~SparseMatrix() {
		delete[] E;
	}
	// + operator overloaded for adding two sparse matrices
	SparseMatrix operator+(SparseMatrix& rhs) {
		int i, j, k;
		if (m != rhs.m || n != rhs.n)
			return SparseMatrix(0,0,0);
		SparseMatrix sum(m,n,num+rhs.num);
		i = j = k = 0;
		while (i < num && j < rhs.num) {
			if (E[i].i < rhs.E[j].i)
				sum.E[k++] = E[i++];
			else if (E[i].i > rhs.E[j].i)
				sum.E[k++] = rhs.E[j++];
			else {
				if (E[i].j < rhs.E[j].j)
					sum.E[k++] = E[i++];
				else if (E[i].j > rhs.E[j].j)
					sum.E[k++] = rhs.E[j++];
				else {
					sum.E[k] = E[i];
					sum.E[k++].x = E[i++].x + rhs.E[j++].x;
				}


			}
		}


	}
	// >> overloaded stream extraction operator for getting non-zero elements
	friend std::istream& operator>>(std::istream& is, SparseMatrix<T>& rhs) {
		
			std::cout << "Enter non-zero elements";
			for (int i = 0; i < rhs.num; i++)
				is >> rhs.E[i].i >> rhs.E[i].j >> rhs.E[i].x;
			return is;
	}
	// >> overloaded stream insertion operator for displaying all elements
	friend std::ostream& operator<<(std::ostream& os, SparseMatrix<T>& s) {
		int k{};
		for (int i{}; i < s.m; i++) {
			for (int j{}; j < s.n; j++) {
				if (s.E[k].i == i && s.E[k].j == j)
					os << s.E[k++].x << " ";
				else
					os << "0 ";
			}
			os << std::endl;
		}
		return os;
	}
	
};
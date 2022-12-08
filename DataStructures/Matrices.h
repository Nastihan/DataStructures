#pragma once
#include <iostream>
template <typename T>
class Matrices {
private:
	int n;
	T* matrix;
public:
	// Constructor
	Matrices(int n){
		this->n = n;
		matrix = new T[n];
		// matrix = new T[n*(n+1)/2]; for Triangular matrix 

	}
	// Copy constructor
	Matrices(const Matrices<T>& source)
		: n{ source.n } {
		matrix = new T[source.n];
		for (int i{}; i < source.n ; i++)
			matrix[i] = source.matrix[i];
		// matrix = new T[n*(n+1)/2];
	}
	// Move constructor
	Matrices(Matrices<T>&& source) 
		: n{ source.n }, matrix{ source.matrix } {
		source.matrix = nullptr;
	}
	// Destructor
	~Matrices() {
		delete[] matrix;
	}
	// SetDiagonalMatrix
	void SetDiagonalMatrix(int i,int j,T x) {
		if (i == j)
			matrix[i - 1] = x;
	}
	// GetDiagonalMatrix
	T GetDiagonalMatrix(int i,int j) {
		if (i == j)
			return matrix[i - 1];
		//else return 0;
	}
	// DisplayDiagonalMatrix
	void DisplayeDiagonalMatrix() {
		for (int i{1}; i <= n; i++) {
			for (int j{1}; j <= n; j++) {
				if (i == j)
					std::cout << matrix[i]<<" ";
				else
					std::cout << "0 ";
			}
			std::cout << std::endl;
		}
	}
	// SetLowerTriangularMatrix 
	void SetLowerTriangularMatrix(int i, int j, T x) {
		if (i >= j)
			matrix[i * (i - 1) / 2 + j - 1] = x; // row-major mapping
		// matrix[n*(j-1)-(j-2)*(j-1)/2+i-j]=x; column-major mapping

	}
	// GetLowerTriangularMatrix
	T GetLowerLowerTriangularMatrix(int i, int j) {
		if (i >= j)
			return matrix[i * (i - 1) / 2 + j - 1]; // row-major mapping
		// matrix[n * (j - 1) - (j - 2) * (j - 1) / 2 + i - j]; column-major mapping
		// else return 0;
	}
	// DisplayLowerTriangularlMatrix
	void DisplayeLowerTriangularlMatrix() {
		for (int i{ 1 }; i <= n; i++) {
			for (int j{ 1 }; j <= n; j++) {
				if (i >= j)
					std::cout << matrix[i*(i-1)/2+j-1] << " "; // row-major mapping
					// std::cout << matrix[n * (j - 1) - (j - 2) * (j - 1) / 2 + i - j] << " column-major mapping				else
					std::cout << "0 ";
			}
			std::cout << std::endl;
		}
	}
	// SetUpperTriangularMatrix 
	void SetUpperTriangularMatrix(int i, int j, T x) {
		if (j >= i)
			matrix[j * (j - 1) / 2 + i - 1] = x; // column-major mapping
		// matrix[n * (i - 1) - (i - 2) * (i - 1) / 2 + j - i]=x; row-major mapping

	}
	// GetUpperTriangularMatrix
	T GetUpperLowerTriangularMatrix(int i, int j) {
		if (j >= i)
			return matrix[j * (j - 1) / 2 + i - 1]; // column-major mapping
		   // return matrix[n * (i - 1) - (i - 2) * (i - 1) / 2 + j - i]; row-major mapping;
		// else return 0;
	}
	// DisplayUpperTriangularlMatrix
	void DisplayeUpperTriangularlMatrix() {
		for (int i{ 1 }; i <= n; i++) {
			for (int j{ 1 }; j <= n; j++) {
				if (j >= i)
					std::cout << matrix[j * (j - 1) / 2 + i - 1] << " "; // column-major mapping
				// std::cout << matrix[n * (i - 1) - (i - 2) * (i - 1) / 2 + j - i] << " "; row-major mapping
				else
					std::cout << "0 ";
			}
			std::cout << std::endl;
		}
	}
};

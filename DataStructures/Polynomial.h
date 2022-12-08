#pragma once
#include <iostream>
#include <cmath>
struct Term {
	int coeff;
	int exp;
};
class Polynomial{
private:
	int n{};
	Term* T;
public:
	// Constructor
	Polynomial(int n)
		:n{ n } {
		T = new Term[n];
	}
	// Destructor
	~Polynomial() {
		delete[] T;
	}
	// Create method 
	void Create() {
		std::cout << "Enter the terms' coeff and exp" << std::endl;
		for (int i{}; i < n; i++) {
			std::cin >> T[i].coeff >> T[i].exp;
		}
	}
	// Result method
	int Result(int x) {
		int sum{};
		for (int i{}; i < n;i++) {
			sum = T[i].coeff + pow(x, T[i].exp);
		}
		return sum;
	}
	// Add method
	Polynomial Add(const Polynomial& rhs) {
		int i{}, j{}, k{};
		Polynomial sum(n + rhs.n);
		while (i < n && j < rhs.n) {
			if (T[i].exp > rhs.T[j].exp)
				sum.T[k++] = T[i++];
			else if (T[i].exp < rhs.T[j].exp)
				sum.T[k++] = rhs.T[j++];
			else {
				sum.T[k].exp = T[i].exp;
				sum.T[k++].coeff = T[i++].coeff + rhs.T[j++].coeff;
			}
			for (i; i < n; i++)
				sum.T[k++] = T[i];
			for (j; j < rhs.n; j++)
				sum.T[k++] = rhs.T[j];

			sum.n = k;
			return sum;

		}

	}



};
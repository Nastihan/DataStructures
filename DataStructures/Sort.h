#pragma once
#include <iostream>
// Sorting Techniques

class Sort {
private:
	int n;
	int* A;
public:
	// Constructor
	Sort(int A[], int n) 
		:n{ n } {
		this->A = new int[n];
		for (int i{}; i < n; i++)
			this->A[i] = A[i];
	}
	// Swap method
	void Swap(int& x,int& y) {
		int temp{ x };
		x = y;
		y = temp;
	}
	// Destructor 
	~Sort() {
		delete A;
	}
	// BubbleSort
	void BubbleSort() {
		int flag{};
		for (int i{}; i < n - 1; i++) {
			for (int j{}; j < n - 1; j++) {
				if (A[j] > A[j + 1]) {
					Swap(A[j], A[j + 1]);
						flag = 1;
				}
			}
			if (flag == 0)
				return;
		}
	}
	// InserSort
	void InsertSort() {
		for (int i{ 1 }; i < n; i++) {
			int j = i - 1;
			int x = A[i];
			while (j > -1 && A[j] > x) {
				A[j + 1] = A[j];
				j--;
			}
			A[j + 1] = x;
		}
	}
	// SelectionSort
	void SelectionSort() {
		for (int i{}; i < n - 1; i++) {
			int j;
			int k;
			for (j = k = i; j < n; j++) {
				if (A[j] < A[k])
					k = j;
			}
			Swap(A[i], A[k]);
		}
	}
	// Merge method (Helper for MergeSort)
	void Merge(int low, int mid, int high) {
		int i{ low };
		int j{ mid + 1 };
		int k{ low };
		int *B = new int[high +1];
		while (i <= mid && j <= high) {
			if (A[i] < A[j])
				B[k++] = A[i++];
			else
				B[k++] = A[j++];
		}
		while (i <= mid)
			B[k++] = A[i++];
		while (j <= high)
			B[k++] = A[j++];
		for (int i{ low }; i <= high; i++)
			A[i] = B[i];
		delete B;
	}
	// MergeSort method
	void MergeSort() {
		int p;
		for (p = 2; p <= n; p = p * 2) {
			for (int i{}; i + p - 1 < n; i = i + p) {
				int low{ i };
				int high{ i + p - 1 };
				int mid{ (low + high) / 2 };
				Merge(low, mid, high);
			}
		}
		if (p / 2 < n)
			Merge(0, p / 2 - 1, n - 1);
	}
	// FindMax method (Helper for CountSort)
	int FindMax() {
		int max{ INT32_MIN };
		int i{};
		for (i; i < n; i++) {
			if (A[i] > max)
				max = A[i];
		}
		return max;
	}
	// CountSort method
	void CountSort() {
		int i, j;
		int max = FindMax();
		int* C{ new int[sizeof(int) * (max + 1)] };
		for (i = 0; i < max + 1; i++)
			C[i] = 0;
		for (i = 0; i < n; i++)
			C[A[i]]++;
		i = j = 0;
		while (j < max + 1) {
			if (C[j] > 0) {
				A[i++] = j;
				C[j]--;
			}
			else
				j++;
		}
	}
	// ShellSort method
	void ShellSort() {
		for (int gap= n / 2 ; gap >= 1; gap /=2) {
			for (int j= gap ; j < n; j++) {
				int temp = A[j];
				int i = j - gap;
				while (i >= 0 && A[i]> temp) {
					A[i + gap] = A[i];
					i = i - gap;
				}
				A[i + gap] = temp;
			}
		}
	}
	void Display() {
		for (int i{}; i < n; i++)
			std::cout << A[i] << " ";
	}

};
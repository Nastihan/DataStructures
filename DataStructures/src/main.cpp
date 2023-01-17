#include <iostream>
#include "Array.h"
#include "Strings.h"
#include "Matrices.h"
#include "SparseMatrix.h"
#include "LinkedList.h"
#include "CircularLinkedList.h"
#include "DoublyLinkedList.h"
#include "Stack.h"
#include "StackL.h"
#include "Queue.h"
#include "QueueL.h"
#include "CircularQueue.h"
#include "BinaryTree.h"
#include "BST.h"
#include "Sort.h"
#include "Chaining.h"

int main(){
	
	int A[8]{ 10,50,40,30,25,80,5,7};

	Chaining H;
	for (int i{}; i < 8; i++)
		H.Insert(A[i]);
	int x =H.Search(13);
	std::cout << x;

	
	



	return 0;
}
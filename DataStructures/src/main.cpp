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


int main(){
	
	int A[8]{ 10,50,40,30,25,80,5,7};

	Sort obj(A, 8);

	obj.ShellSort();

	obj.Display();

	
	



	return 0;
}
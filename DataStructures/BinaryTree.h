#pragma once
#include <iostream>
#include <queue>

template <typename T>
struct TreeNode {
	TreeNode<T>* Lchild;
	T data;
	TreeNode<T>* Rchild;
};
template < typename T>
class BinaryTree {
private:
	TreeNode<T>* root;
public:
	// Constructor
	BinaryTree()
		:root{ nullptr } {
	}
	// Copy constructor
	// Move constructor

	/* Destructor
	~BinaryTree() {

	}
	*/
	void CreateTree() {
		TreeNode<T>* p;
		TreeNode<T>* t;
		std::string input; //  *
		T x; // reminder
		std::queue<TreeNode<T>*> Q;

		root = new TreeNode<T>;
		std::cout << " Enter root data" << std::endl;
		std::cin >> x;
		root->data = x;
		root->Lchild = nullptr;
		root->Rchild = nullptr;
		Q.emplace(root);

		while (!Q.empty()) {
			p = Q.front();
			Q.pop();

			std::cout << "Enter left child data of " << p->data << " :" << std::endl;
			std::cin >> x;
			if (x != -1) {
				t = new TreeNode<T>;
				t->data = x;
				t->Lchild = nullptr;
				t->Rchild = nullptr;
				p->Lchild = t;
				Q.emplace(t);
			}

			std::cout << "Enter right child data of " << p->data << " :" << std::endl;
			std::cin >> x;
			if (x != -1) {
				t = new TreeNode<T>;
				t->data = x;
				t->Lchild = nullptr;
				t->Rchild = nullptr;
				p->Rchild = t;
				Q.emplace(t);
			}
		}
	}
	// Helper method to easily call in main
	void PreOrder() {
		PreOrder(root);
	}
	// PreOrder method
	void PreOrder(TreeNode<T>* p) {
		if (p) {
			std::cout << p->data << ", ";
			PreOrder(p->Lchild);
			PreOrder(p->Rchild);
		}
	}
	// Helper method to easily call in main
	void InOrder() {
		InOrder(root);
	}
	// InOrder method
	void InOrder(TreeNode<T>* p) {
		if (p) {
			InOrder(p->Lchild);
			std::cout << p->data << ", ";
			InOrder(p->Rchild);
		}
	}
	// Helper method to easily call in main
	void PostOrder() {
		PostOrder(root);
	}
	// PostOrder method
	void PostOrder(TreeNode<T>* p) {
		if (p) {
			PostOrder(p->Lchild);
			PostOrder(p->Rchild);
			std::cout << p->data << ", ";
		}
	}
	// Helper method to easily call in main
	void LevelOrder() {
		LevelOrder(root);
	}
	// LevelOrder method
	void LevelOrder(TreeNode<T>* p) {
		std::queue<TreeNode<T>*> Q;
		std::cout << root->data << ", ";
		Q.emplace(root);

		while (!Q.empty()) {
			TreeNode<T>* p = Q.front();
			Q.pop();

			if (p->Lchild) {
				std::cout << p->Lchild->data << ", ";
				Q.emplace(p->Lchild);
			}
			if (p->Rchild) {
				std::cout << p->Rchild->data << ", ";
				Q.emplace(p->Rchild);
			}
		}
	}
	// Helper method to call easily in main
	int Height() {
		return Height(root);
	}
	// Height method
	int Height(TreeNode<T>* p) {
		int l{ 0 };
		int r{ 0 };

		if (p == nullptr)
			return 0;
		l = Height(p->Lchild);
		r = Height(p->Rchild);

		if (l > r)
			return l + 1;
		else 
			return r + 1;
	}
	// Helper method to call easily in main
	int NodeCount() {
		return NodeCount(root);
	}
	// NodeCount method for counting nodes in a binary tree
	int NodeCount(TreeNode<T>* p){
		int x{};
		int y{};
		if (p!=nullptr){
			x = NodeCount(p->Lchild);
			y = NodeCount(p->Rchild);
			return x + y + 1;
		}
		return 0;
	}
	// Helper method to call easily in main
	int Degree2NodeCount() {
		return Degree2NodeCount(root);
	}
	// Degree2NodeCount for counting degree2 nodes in a binary tree
	int Degree2NodeCount(TreeNode<T>* p) {
		int x{};
		int y{};
		if (p != nullptr) {
			x = Degree2NodeCount(p->Lchild);
			y = Degree2NodeCount(p->Rchild);
			if (p->Lchild && p->Rchild) 
				return x + y + 1;
			else 
				return x + y;
			
		}
		return 0;
	}


};
#pragma once
#include <iostream>
#include <stack>

struct BSTnode {
	BSTnode* Lchild;
	int data;
	BSTnode* Rchild;
};
// Binary Search Tree class 
class BST {
private:
	BSTnode* root;
public:
	// Constructor
	BST()
		: root{ nullptr } {

	}
	// Insert method
	void Insert(int key) {
		BSTnode* t = root;
		BSTnode* p;
		BSTnode* r = nullptr;

		if (root == nullptr) {
			p = new BSTnode;
			p->data = key;
			p->Lchild = nullptr;
			p->Rchild = nullptr;
			root = p;
			return;
		}
		while (t != nullptr) {
			r = t;
			if (key < t->data)
				t = t->Lchild;
			else if (key > t->data)
				t = t->Rchild;
			else
				return;
		}
		// Now t points at NULL and r points at insert location
		p = new BSTnode;
		p->data = key;
		p->Lchild = nullptr;
		p->Rchild = nullptr;

		if (key < r->data)
			r->Lchild = p;
		else
			r->Rchild = p;

	}
	// helper method to call in main
	void Inorder() {
		 Inorder(root);
	}
	// Inorder method
	void Inorder(BSTnode* p) {
		if (p) {
			Inorder(p->Lchild);
			std::cout << p->data << ", ";
			Inorder(p->Rchild);
		}
	}
	// Search method
	BSTnode* Search(int key) {
		BSTnode* t = root;
		while (t != nullptr) {
			if (key == t->data)
				return t;
			else if (key < t->data)
				t = t->Lchild;
			else
				t = t->Rchild;
		}
		return nullptr;
	}
	// Helper method to easily call in main
	BSTnode* Delete(int key) {
		return Delete(root, key);
	}
	// Delete method
	BSTnode* Delete(BSTnode* p, int key) {
		BSTnode* q;
		if (p == nullptr)
			return nullptr;
		if (p->Lchild == nullptr && p->Rchild == nullptr) {
			if (p == root)
				root = nullptr;
			delete p;
			return nullptr;
		}
		if (key < p->data)
			p->Lchild = Delete(p->Lchild, key);
		else if (key > p->data)
			p->Rchild = Delete(p->Rchild, key);
		else {
			if (Heigth(p->Lchild) > Heigth(p->Rchild)) {
				q = InPre(p->Lchild);
				p->data = q->data;
				p->Lchild = Delete(p->Lchild, q->data);
			}
			else {
				q = InSucc(p->Rchild);
				p->data = q->data;
				p->Rchild = Delete(p->Rchild, q->data);
			}
		}
	}
	// Helper method to easily call in main
	int Heigth() {
		return Heigth(root);
	}
	// Heigth method
	int Heigth(BSTnode* p) {
		int x;
		int y;
		if (p == nullptr)
			return 0;
		x = Heigth(p->Lchild);
		y = Heigth(p->Rchild);
		return x > y ? x + 1 : y + 1;
	}
	// InPre method
	BSTnode* InPre(BSTnode* p) {
		while (p && p->Rchild != nullptr)
			p = p->Rchild;
		return p;
	}
	// InSucc method
	BSTnode* InSucc(BSTnode* p) {
		while (p && p->Lchild != nullptr)
			p = p->Lchild;
		return p;
	}


};

#pragma once
#include <iostream>

struct AVLnode {
	AVLnode* Lchild;
	int data;
	AVLnode* Rchild;
	int height;
};
struct AVL {
private:
	AVLnode* root;
	// Constructor
public:
	AVL() 
		: root{ nullptr } {
	}
	// Helper methods for inserting/deleting - from NodeHeight() to InSucc() 
	int NodeHeight(AVLnode* p) {
		int hl;
		int hr;

		hl = (p && p->Lchild) ? p->Lchild->height : 0;
		hr = (p && p->Rchild) ? p->Rchild->height : 0;

		return hl > hr ? hl + 1 : hr + 1;
	}

	int BalanceFactor(AVLnode* p) {
		int hl;
		int hr;

		hl = (p && p->Lchild) ? p->Lchild->height : 0;
		hr = (p && p->Rchild) ? p->Rchild->height : 0;

		return hl - hr;
	}

	AVLnode* LLRotation(AVLnode* p) {
		AVLnode* pl = p->Lchild;
		AVLnode* plr = pl->Rchild;

		pl->Rchild = p;
		p->Lchild = plr;

		// Update height
		p->height = NodeHeight(p);
		pl->height = NodeHeight(pl);

		// Update Root
		if (root == p)
			root = pl;
		return pl;

	}

	AVLnode* RRRotation(AVLnode* p) {
		AVLnode* pr = p->Rchild;
		AVLnode* prl = pr->Lchild;

		pr->Lchild = p;
		p->Rchild = prl;

		// Update height
		p->height = NodeHeight(p);
		pr->height = NodeHeight(pr);

		// Update root
		if (root == p)
			root = pr;
		return pr;

	}

	AVLnode* LRRotation(AVLnode* p) {
		AVLnode* pl = p->Lchild;
		AVLnode* plr = pl->Rchild;

		pl->Rchild = plr->Lchild;
		p->Lchild = plr->Rchild;

		plr->Lchild = pl;
		plr->Rchild = p;

		// Update height
		pl->height = NodeHeight(pl);
		p->height = NodeHeight(p);
		plr->height = NodeHeight(plr);

		// Upodate root
		if (p == root)
			root = plr;
		return plr;

	}

	AVLnode* RLRotatiopn(AVLnode* p) {
		AVLnode* pr = p->Rchild;
		AVLnode* prl = pr->Lchild;

		pr->Lchild = prl->Rchild;
		p->Rchild = prl->Lchild;

		prl->Rchild = pr;
		prl->Lchild = p;

		// Update height
		pr->height = NodeHeight(pr);
		p->height = NodeHeight(p);
		prl->height = NodeHeight(prl);

		// Update root
		if (root == p)
			root = prl;
		return prl;

	}

	AVLnode* InPre(AVLnode* p) {
		while (p && p->Rchild != nullptr)
			p = p->Rchild;
		return p;
	}

	AVLnode* InSucc(AVLnode* p) {
		while (p && p->Lchild != nullptr)
			p = p->Lchild;
		return p;
	}

	// Method for insert 
	AVLnode* rInsert(AVLnode* p, int key) {
		AVLnode* t;
		if (p == nullptr) {
			t = new AVLnode;
			t->data = key;
			t->Lchild = nullptr;
			t->Rchild = nullptr;
			t->height = 1; // Starting heigth from 1 onwards
			return t;
		}
		if (key < p->data)
			p->Lchild = rInsert(p->Lchild, key);
		else if (key > p->data)
			p->Rchild = rInsert(p->Rchild, key);

		// Update heigth
		p->height = NodeHeight(p);

		// BalanceFactor and Rotation
		if (BalanceFactor(p) == 2 && BalanceFactor(p->Lchild) == 1)
			return LLRotation(p);
		else if (BalanceFactor(p) == 2 && BalanceFactor(p->Lchild) == -1)
			return LRRotation(p);
		else if (BalanceFactor(p) == -2 && BalanceFactor(p->Rchild) == -1)
			return RRRotation(p);
		else if (BalanceFactor(p) == -2 && BalanceFactor(p->Rchild) == 1)
			return RLRotatiopn(p);

		return p;
	}
	void Inorder(AVLnode* p) {
		if (p) {
			Inorder(p->Lchild);
			std::cout << p->data << ", ";
			Inorder(p->Rchild);
		}
	}
	AVLnode* Delete(AVLnode* p, int key) {
		if (p == nullptr)
			return nullptr;
		if (p->Lchild == nullptr && p->Rchild == nullptr) {
			if (p == root)
				root = nullptr;
			delete p;
			return nullptr;
		}
		if (key, p->data)
			p->Lchild = Delete(p->Lchild, key);
		else if (key > p->data)
			p->Rchild = Delete(p->Rchild, key);
		else {
			AVLnode* q;
			if (NodeHeight(p->Lchild) > NodeHeight(p->Rchild)) {
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
		// Update height
		p->height = NodeHeight(p);
		// Balance factor and rotation
		if (BalanceFactor(p) == 2 && BalanceFactor(p->Lchild) == 1)
			return LLRotation(p);
		else if (BalanceFactor(p) == 2 && BalanceFactor(p->Lchild) == -1)
			return LRRotation(p);
		else if (BalanceFactor(p) == -2 && BalanceFactor(p->Rchild) == -1)
			return RRRotation(p);
		else if (BalanceFactor(p) == -2 && BalanceFactor(p->Rchild) == 1)
			return RLRotatiopn(p);
		else if (BalanceFactor(p) == 2 && BalanceFactor(p->Lchild))
			return LLRotation(p);
		else if (BalanceFactor(p) == -2 && BalanceFactor(p->Rchild) == 0)
			return RRRotation(p);
		return p;
	}

};
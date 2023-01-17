#pragma once
struct HashNode {
	int data;
	HashNode* next;
};
class Chaining {
private:
	HashNode** HT;
public:
	// Constructor
	Chaining() {
		HT = new HashNode * [10];
		for (int i{}; i < 10; i++)
			HT[i] = nullptr;
	}
	int Hash(int key) {
		return key % 10;
	}
	void Insert(int key) {
		int index = Hash(key);
		HashNode* t = new HashNode;
		t->data = key;
		t->next = nullptr;
		// No HashNodes
		if (HT[index] == nullptr)
			HT[index] = t;
		else {
			HashNode* p = HT[index];
			HashNode* q = HT[index];
			// Find insert position'
			while (p && p->data < key) {
				q = p;
				p = p->next;
			}
			// If Insert position is first
			if (q == HT[index]) {
				t->next = HT[index];
				HT[index] = t;
			}
			else {
				t->next = q->next;
				q->next = t;
			}
		}
	}
	int Search(int key) {
		int index = Hash(key);
		HashNode* p = HT[index];
		while (p) {
			if (p->data == key)
				return p->data;
			p = p->next;
		}
		return -1;
	}
	// Destructor
	~Chaining() {
		for (int i{}; i < 10; i++) {
			HashNode* p = HT[i];
			while (HT[i]) {
				HT[i] = HT[i]->next;
				delete p;
				p = HT[i];
			}
		}
		delete[] HT;
	}
	
};
#pragma once

struct NODE {
	NODE* left;
	NODE* right;
	int data;
};

class BST {

public:
	BST();
	~BST();
	void Insert(int data);
	bool Delete(int data);
	void Display();
	void BFS();
	void Count();
	bool isEmpty();
	bool Contains(int data);

private:
	int count;
	NODE* ROOT;
	NODE* CreateNode(int data);
	NODE* _Insert(NODE* ROOT, NODE* node);
	void _Display(NODE* ROOT);
	NODE* _Delete(NODE* ROOT, int data);
	NODE* _Search(NODE* ROOT, int data);
	NODE* _Smallest(NODE* ROOT);
	NODE* _Largest(NODE* ROOT);
};


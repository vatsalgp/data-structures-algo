#pragma once

struct Node {
	int data;
	Node* next;
};

class Stack {
private:
	Node* Top;

public:
	Stack();
	~Stack();
	bool isEmpty();
	bool isFull();
	void Push(int);
	int Pop();
	void Display();
	int StackTop();

};

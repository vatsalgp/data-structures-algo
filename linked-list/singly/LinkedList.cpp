#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList(int data) {

	HEAD = new Node();
	HEAD->data = data;
	HEAD->next = nullptr;
}

LinkedList::~LinkedList() {
	Node* temp = HEAD;
	while (temp) {
		temp = temp->next;
		delete HEAD;
		HEAD = temp;
	}
}

void LinkedList::Display() {
	std::cout << "The list is: " << std::endl;
	Node* temp = HEAD;
	while (temp) {
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << std::endl << std::endl;
}

void LinkedList::Push(int data) {

	Node* temp = HEAD;
	while (temp->next)	temp = temp->next;
	temp->next = new Node();
	temp = temp->next;
	if (temp) {
		temp->data = data;
		temp->next = nullptr;
	}
	else
		std::cout << "Overflow" << std::endl;
}

int LinkedList::Pop() {

	if (HEAD == nullptr){
		std::cout << "Underflow" << std::endl;
		return 0;
	}
	int data;
	if (HEAD->next == nullptr) {
		data = HEAD->data;
		delete HEAD;
		HEAD = nullptr;
		return data;
	}
	Node* temp = HEAD;

	while (temp->next->next)	temp = temp->next;
	data = temp->next->data;
	delete temp->next;
	temp->next = nullptr;

	return data;
}

int LinkedList::Max() {
	
	int max = 0;
	Node* temp = HEAD;
	while (temp) {
		if ((temp->data) > max) {
			max = temp->data;
		}
		temp = temp->next;
	}
	return max;
}

int LinkedList::Min() {
	
	int min = 0;
	Node* temp = HEAD;
	while (temp) {
		if ((temp->data) < min) {
			min = temp->data;
		}
		temp = temp->next;
	}
	return min;
}

int LinkedList::Length() {

	int length = 0;
	Node* temp = HEAD;
	while (temp) {
		length++;
		temp = temp->next;
	}
	return length;
}

int LinkedList::Sum() {

	int sum = 0;
	Node* temp = HEAD;
	while (temp) {
		sum += temp->data;
		temp = temp->next;
	}
	return sum;
}

bool LinkedList::IsSorted() {

	Node* temp = HEAD;
	while (temp->next) {
		if (temp->data > temp->next->data)
			return false;
		temp = temp->next;
	}
	return true;
}

float LinkedList::Average() {

	int sum = 0;
	int length = 0;
	Node* temp = HEAD;
	while (temp) {
		length++;
		sum += temp->data;
		temp = temp->next;
	}
	return (float)sum / length;
}

void LinkedList::Reverse() {

	Node* p = HEAD;
	Node* q = nullptr;
	Node* r = nullptr;

	while (p) {
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	HEAD = q;
	std::cout << "The list has been reversed." << std::endl << std::endl;
}

void LinkedList::Concat(LinkedList& Second) {

	Node* last = HEAD;
	while (last->next) last = last->next;
	last->next = Second.HEAD;
	Second.HEAD = nullptr;
	std::cout << "Lists have been Concatenated." << std::endl << std::endl;
}

void LinkedList::Merge(LinkedList& SecondLL) {
	Node* first = HEAD;
	Node* second = SecondLL.HEAD;
	Node* third = nullptr;
	Node* last = nullptr;
	Node** smaller = nullptr;

	if (first->data < second->data)
		smaller = &first;
	else
		smaller = &second;

	third = last = (*smaller);
	(*smaller) = (*smaller)->next;
	last->next = nullptr;

	while (first && second) {
		if (first->data < second->data)
			smaller = &first;
		else
			smaller = &second;

		last->next = (*smaller);
		last = last->next;
		(*smaller) = (*smaller)->next;
		last->next = nullptr;
	}
	if (first)
		last->next = first;
	else
		last->next = second;
	
	SecondLL.HEAD = nullptr;
	HEAD = third;
	std::cout << "Lists have been Merged." << std::endl << std::endl;
}

bool LinkedList::IsLoop() {
	
	Node* p = HEAD;
	Node* q = HEAD;

	while (q) {
		if (p->next)
			p = p->next;
		else
			return false;

		if (q->next)
			q = q->next;
		else
			return false;

		if (q->next)
			q = q->next;
		else
			return false;

		if (p == q)
			return true;
	}
	return false;
}

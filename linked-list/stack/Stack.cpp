#include "Stack.h"

#include <iostream>

Stack::Stack() { Top = nullptr; }

Stack::~Stack() {
    while (!isEmpty()) {
        Node *temp = Top;
        Top = Top->next;
        delete temp;
    }
}

bool Stack::isEmpty() { return Top == nullptr; }

bool Stack::isFull() {
    Node *temp = new Node;
    delete temp;

    return !temp;
}

void Stack::Push(int data) {
    if (isFull())
        std::cout << "Overflow" << std::endl;
    else {
        Node *temp = new Node;
        temp->data = data;
        temp->next = Top;
        Top = temp;
    }
}

int Stack::Pop() {
    int data = -1;
    if (isEmpty())
        std::cout << "Underflow" << std::endl;
    else {
        data = Top->data;
        Node *temp = Top;
        Top = Top->next;
        delete temp;
    }
    return data;
}

void Stack::Display() {
    Node *temp = Top;
    while (!isEmpty()) {
        std::cout << Top->data << std::endl;
        Top = Top->next;
    }
    Top = temp;
}

int Stack::StackTop() {
    if (isEmpty()) {
        return 0;
    } else
        return Top->data;
}

#include "Stack.h"

#include <iostream>

Stack::Stack(int s) {
    size = s;
    top = -1;
    arr = new int[size];
}

Stack::~Stack() {
    size = 0;
    top = -1;
    delete[] arr;
}

bool Stack::isEmpty() { return top == -1; }

bool Stack::isFull() { return top == size - 1; }

void Stack::Push(int data) {
    if (isFull())
        std::cout << "Overflow" << std::endl;
    else
        arr[++top] = data;
}

int Stack::Pop() {
    int data = -1;
    if (isEmpty())
        std::cout << "Underflow" << std::endl;
    else
        data = arr[top--];

    return data;
}

void Stack::Display() {
    int temp = top;
    while (!isEmpty())
        std::cout << arr[top--] << std::endl;
    top = temp;
}

int Stack::StackTop() {
    if (isEmpty())
        return 0;
    else
        arr[top];
}

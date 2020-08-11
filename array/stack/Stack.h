#pragma once

class Stack {
  private:
    int size;
    int top;
    int *arr;

  public:
    Stack(int s = 8);
    ~Stack();
    bool isEmpty();
    bool isFull();
    void Push(int);
    int Pop();
    void Display();
    int StackTop();
};

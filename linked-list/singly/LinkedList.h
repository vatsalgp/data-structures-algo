#pragma once

struct Node {
    int data;
    Node *next;
};

class LinkedList {
  private:
    Node *HEAD;

  public:
    LinkedList(int data = 0);
    ~LinkedList();
    void Display();
    void Push(int);
    int Pop();
    int Max();
    int Min();
    int Length();
    int Sum();
    bool IsSorted();
    float Average();
    void Reverse();
    void Concat(LinkedList &);
    void Merge(LinkedList &);
    bool IsLoop();
};

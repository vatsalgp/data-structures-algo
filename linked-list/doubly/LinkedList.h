#pragma once

struct Node {
    Node *prev;
    int data;
    Node *next;
};

class LinkedList {
  private:
    Node *HEAD;
    Node *TAIL;

  public:
    LinkedList(int data = 0);
    ~LinkedList();
    void Push(int);
    int Pop();
    void Display();
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

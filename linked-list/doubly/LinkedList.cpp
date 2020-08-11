#include "LinkedList.h"

#include <iostream>

LinkedList::LinkedList(int data) {
    HEAD = new Node;
    HEAD->data = data;
    HEAD->prev = nullptr;
    HEAD->next = nullptr;
    TAIL = HEAD;
}

LinkedList::~LinkedList() {
    Node *temp = HEAD;
    while (temp) {
        temp = temp->next;
        delete HEAD;
        HEAD = temp;
    }
    TAIL = nullptr;
}

void LinkedList::Push(int data) {
    Node *temp = new Node;
    temp->data = data;
    temp->next = nullptr;
    temp->prev = TAIL;
    TAIL->next = temp;
    TAIL = temp;
}

int LinkedList::Pop() {
    int data;
    if (!HEAD) {
        data = 0;
        std::cout << "Underflow" << std::endl;
    } else if (HEAD == TAIL) {
        data = TAIL->data;
        delete HEAD;
        HEAD = nullptr;
        TAIL = nullptr;
    } else {
        Node *temp = TAIL->prev;
        temp->next = nullptr;
        data = TAIL->data;
        delete TAIL;
        TAIL = temp;
    }
    return data;
}

void LinkedList::Display() {
    std::cout << "The List is: " << std::endl;
    Node *temp = HEAD;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int LinkedList::Max() {
    int max = 0;
    Node *temp = HEAD;
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
    Node *temp = HEAD;
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
    Node *temp = HEAD;
    while (temp) {
        length++;
        temp = temp->next;
    }
    return length;
}

int LinkedList::Sum() {
    int sum = 0;
    Node *temp = HEAD;
    while (temp) {
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}

bool LinkedList::IsSorted() {
    Node *temp = HEAD;
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
    Node *temp = HEAD;
    while (temp) {
        length++;
        sum += temp->data;
        temp = temp->next;
    }
    return (float)sum / length;
}

void LinkedList::Reverse() {
    Node *temp = HEAD;
    Node *swap = nullptr;
    while (temp) {
        swap = temp->next;
        temp->next = temp->prev;
        temp->prev = swap;
        temp = temp->prev;
    }

    swap = TAIL;
    TAIL = HEAD;
    HEAD = swap;
    std::cout << "List has been Reversed." << std::endl << std::endl;
}

void LinkedList::Concat(LinkedList &SecondLL) {
    Node *first = TAIL;
    Node *second = SecondLL.HEAD;
    first->next = second;
    second->prev = first;
    SecondLL.HEAD = nullptr;
    SecondLL.TAIL = nullptr;
    std::cout << "Lists have been Concatenated." << std::endl << std::endl;
}

void LinkedList::Merge(LinkedList &SecondLL) {
    Node *first = HEAD;
    Node *second = SecondLL.HEAD;
    Node *third = nullptr;
    Node *last = nullptr;
    Node **smaller = nullptr;

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
    SecondLL.TAIL = nullptr;
    HEAD = third;
    std::cout << "Lists have been Merged." << std::endl << std::endl;
}

bool LinkedList::IsLoop() {
    Node *p = HEAD;
    Node *q = HEAD;

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

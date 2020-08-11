#include "BST.h"

#include <iostream>
#include <vector>

BST::BST() {
    ROOT = nullptr;
    count = 0;
}

BST::~BST() {
    while (!isEmpty()) {
        Delete(ROOT->data);
    }
}

void BST::Insert(int data) {
    if (!ROOT) {
        ROOT = CreateNode(data);
    } else {
        _Insert(ROOT, CreateNode(data));
    }
    count++;
}

NODE *BST::_Insert(NODE *ROOT, NODE *node) {
    if (!ROOT)
        return node;
    else if (node->data < ROOT->data) {
        ROOT->left = _Insert(ROOT->left, node);
        return ROOT;
    } else {
        ROOT->right = _Insert(ROOT->right, node);
        return ROOT;
    }
}

NODE *BST::CreateNode(int data) {
    NODE *node = new NODE;
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

bool BST::Delete(int data) {
    count--;
    if (ROOT = _Delete(ROOT, data)) {
        return true;
    } else
        return false;
}

NODE *BST::_Delete(NODE *node, int data) {
    if (!node) {
        count++;
        return nullptr;
    } else if (data < node->data) {
        node->left = _Delete(node->left, data);
        return node;
    } else if (data > node->data) {
        node->right = _Delete(node->right, data);
        return node;
    } else {
        if (!(node->left)) {
            NODE *temp = node;
            node = node->right;
            delete temp;
            return node;
        } else if (!(node->right)) {
            NODE *temp = node;
            node = node->left;
            delete temp;
            return node;
        } else {
            NODE *smallest = _Smallest(node->right);
            node->data = smallest->data;
            node->right = _Delete(smallest, smallest->data);
            return node;
        }
    }
}

NODE *BST::_Search(NODE *ROOT, int data) {
    if (!ROOT)
        return nullptr;
    else if (data < ROOT->data)
        _Search(ROOT->left, data);
    else if (data > ROOT->data)
        _Search(ROOT->right, data);
    else
        return ROOT;
}

NODE *BST::_Smallest(NODE *ROOT) {
    if (ROOT && ROOT->left)
        _Smallest(ROOT->left);
    return ROOT;
}

NODE *BST::_Largest(NODE *ROOT) {
    if (ROOT && ROOT->right)
        _Largest(ROOT->right);
    return ROOT;
}

void BST::Display() { _Display(ROOT); }

void BST::_Display(NODE *ROOT) {
    if (ROOT) {
        _Display(ROOT->left);
        std::cout << ROOT->data << " ";
        _Display(ROOT->right);
    }
}

void BST::BFS() {
    std::vector<NODE *> data;
    data.push_back(ROOT);
    for (int i = 0; i < data.size(); i++) {
        std::cout << data[i]->data << std::endl;
        if (data[i]->left)
            data.push_back(data[i]->left);
        if (data[i]->right)
            data.push_back(data[i]->right);
    }
}

void BST::Count() { std::cout << std::endl << "Count: " << count; }

bool BST::isEmpty() { return count == 0; }

bool BST::Contains(int data) { return _Search(ROOT, data); }

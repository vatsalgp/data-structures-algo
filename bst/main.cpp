#include <iostream>

#include "BST.h"

using namespace std;

int main() {
    BST tree;
    int x;
    do {
        system("CLS");
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> x;
        system("CLS");
        switch (x) {
        case 1:
            cout << "Enter element to Insert: ";
            cin >> x;
            tree.Insert(x);
            break;
        case 2:
            cout << "Enter element to Delete: ";
            cin >> x;
            tree.Delete(x);
            break;
        case 3:
            tree.Display();
            tree.Count();
            x = (int)getchar();
            x = (int)getchar();
            break;
        case 4:
            exit(0);
        }
    } while (true);
}

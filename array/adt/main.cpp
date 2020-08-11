#pragma once
#include "Array.cpp"

int main() {
    Array<int> arr;
    int x, ele, pos;
    char ans;
    system("CLS");
    do {
        cout << "Enter what to do: " << endl << endl;
        cout << "01.Display the array" << endl;
        cout << "02.Add element to the end of the array" << endl;
        cout << "03.Insert element at a specific position" << endl;
        cout << "04.Remove specific element from the array" << endl;
        cout << "05.Search for specific element in the array" << endl;
        cout << "06.Get the element at specific position" << endl;
        cout << "07.Set value at a specific position" << endl;
        cout << "08.Reverse the array" << endl;
        cout << "09.Sort the array" << endl;
        cout << "10.Find the max of the array" << endl;
        cout << "11.Find the min of the array" << endl;
        cout << "12.Find the sum of the array" << endl;
        cout << "13.Find the avg of the array" << endl << endl;
        cout << "Choice: ";
        cin >> x;
        system("CLS");
        switch (x) {
        case 1:
            arr.display();
            break;
        case 2:
            cout << "Enter the element: ";
            cin >> ele;
            arr.add(ele);
            arr.display();
            break;
        case 3:
            cout << "Enter the element: ";
            cin >> ele;
            cout << "Enter the position: ";
            cin >> pos;
            pos--;
            arr.insert(pos, ele);
            arr.display();
            break;
        case 4:
            cout << "Enter the element: ";
            cin >> ele;
            arr.remove(ele);
            arr.display();
            break;
        case 5:
            cout << "Enter the element: ";
            cin >> ele;
            pos = arr.search(ele);
            if (pos >= 0)
                cout << "The element is at position " << pos + 1;
            else
                cout << "Element not found";
            break;
        case 6:
            cout << "Enter the position: ";
            cin >> pos;
            pos--;
            cout << arr.get(pos);
            break;
        case 7:
            cout << "Enter the element: ";
            cin >> ele;
            cout << "Enter the position: ";
            cin >> pos;
            pos--;
            arr.set(pos, ele);
            arr.display();
            break;
        case 8:
            arr.reverse();
            cout << "The array has been reversed." << endl;
            arr.display();
            break;
        case 9:
            arr.sort();
            cout << "The array has been sorted." << endl;
            arr.display();
            break;
        case 10:
            cout << "The max element is " << arr.max();
            break;
        case 11:
            cout << "The min element is " << arr.min();
            break;
        case 12:
            cout << "The sum is " << arr.sum();
            break;
        case 13:
            cout << "The average is " << arr.avg();
            break;
        }
        cout << endl;
        cout << "Do you want to continue?(y/n) ";
        cin >> ans;
        system("CLS");
    } while (ans == 'y' || ans == 'Y');
    return 0;
}

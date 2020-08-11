#pragma once
#include "Array.h"
#include <iostream>
using namespace std;

template <class T>
Array<T>::Array() {
	length = 0;
	char ch;
	do {
		cout << "Enter the number of elements: ";
		cin >> size;
	} while (size<=0);
	cout << endl;
	a = new T[size];
	for (int i = 0; i < size; i++) {
		cout << "Enter another element ?(y/n): ";
		cin >> ch;
		if (ch == 'y' || ch == 'Y') {
			cout << "Enter element number " << i + 1 << " : ";
			cin >> a[i];
			length++;
		}
		else
			break;
	}
	cout << endl;
}

template <class T>
void Array<T>::display() {
	cout << "The array is:" << endl;
	for (int i = 0; i < length; i++)
		cout << a[i] << " ";
	cout << endl;
}

template <class T>
int Array<T>::search(T ele) {
	for (int i = 0; i < length; i++)
		if (a[i] == ele)
			return i;
	return -1;
}

template <class T>
T Array<T>::get(int index) {
	return a[index];
}

template <class T>
void Array<T>::sort() {
	T temp;
	for (int i = 0; i < length; i++) {
		for (int j = i + 1; j < length; j++) {
			if (a[j] < a[i]) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

template <class T>
int Array<T>::add(T ele) {
	if (length < size) {
		a[length] = ele;
		length++;
		return length-1;
	}
	return -1;
}

template <class T>
void Array<T>::insert(int index, T ele) {
	if (length < size && index < size && index>=0) {
		for (int i = length; i > index; i--) {
			a[i] = a[i-1];
		}
		a[index] = ele;
		length++;
	}
}

template <class T>
void Array<T>::remove(T ele) {
	int pos = search(ele);
	if (pos != -1) {
		for (int i = pos; i < length - 1; i++) {
			a[i] = a[i + 1];
		}
		a[length - 1] = 0;
		length--;
	}
}

template <class T>
void Array<T>::set(int index, T ele) {
	if(index>=0 && index<length)
		a[index] = ele;
	else if (index == length && length < size) {
		a[index] = ele;
		length++;
	}
}

template <class T>
T Array<T>::max() {
	T max = a[0];
	for (int i = 0; i < length; i++){
		if (a[i] > max)
			max = a[i];
	}
	return max;
}

template <class T>
T Array<T>::min() {
	T min = a[0];
	for (int i = 0; i < length; i++) {
		if (a[i] < min)
			min = a[i];
	}
	return min;
}

template <class T>
T Array<T>::sum() {
	T sum = 0;
	for (int i = 0; i < length; i++) {
		sum += a[i];
	}
	return sum;
}

template <class T>
T Array<T>::avg() {
	return sum()/length;
}

template <class T>
void Array<T>::reverse() {
	T temp;
	for (int i = 0, j = length - 1; i < length / 2; i++, j--) {
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
}

template <class T>
Array<T>::~Array() {
	delete[] a;
}

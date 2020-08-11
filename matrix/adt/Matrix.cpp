#pragma once
#include "Matrix.h"

#include <iostream>

template <class T> Matrix<T>::Matrix(int n) {
    this->n = n;

    a = new T *[n];
    for (int i = 0; i < n; i++) {
        a[i] = new T[n];
    }
}

template <class T> void Matrix<T>::Input() {
    T temp;
    std::cout << "Enter the array of order " << n << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> temp;
            SetElement(i, j, temp);
        }
    }
}

template <class T> void Matrix<T>::Print() {
    // std::cout << "The array is:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << GetElement(i, j) << "\t";
        }
        std::cout << std::endl;
    }
}

template <class T> Matrix<T> *Matrix<T>::Add(Matrix<T> *m2) {
    Matrix<T> *m3 = new Matrix<T>(n);

    T x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            x = GetElement(i, j) + m2->GetElement(i, j);
            m3->SetElement(i, j, x);
        }
    }
    return m3;
}

template <class T> Matrix<T> *Matrix<T>::Subt(Matrix<T> *m2) {
    Matrix<T> *m3 = new Matrix<T>(n);

    T x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            x = GetElement(i, j) - m2->GetElement(i, j);
            m3->SetElement(i, j, x);
        }
    }
    return m3;
}

template <class T> Matrix<T> *Matrix<T>::Mult(Matrix<T> *m2) {
    Matrix<T> *m3 = new Matrix<T>(n);

    T x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            x = 0;
            for (int k = 0; k < n; k++)
                x += GetElement(i, k) * m2->GetElement(k, j);
            m3->SetElement(i, j, x);
        }
    }

    return m3;
}

template <class T> T Matrix<T>::GetElement(int i, int j) { return a[i][j]; }

template <class T> void Matrix<T>::SetElement(int i, int j, T x) {
    a[i][j] = x;
}

template <class T> T Matrix<T>::Determinant() {
    int det = 0;

    if (n == 1)
        return a[0][0];

    for (int i = 0, j = 0; i < n; i++)
        det += GetElement(i, j) * GetCofactor(i, j);

    return det;
}

template <class T> Matrix<T> *Matrix<T>::Transpose() {
    Matrix<T> *Transpose = new Matrix<T>(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            Transpose->SetElement(j, i, a[i][j]);

    return Transpose;
}

template <class T> Matrix<T> *Matrix<T>::Adjoint() {
    Matrix<T> *Adjoint = new Matrix<T>(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Adjoint->SetElement(j, i, GetCofactor(i, j));
        }
    }
    return Adjoint;
}

template <class T> Matrix<T> *Matrix<T>::Inverse() {
    T det = Determinant();
    if (det) {
        Matrix<T> *Inverse = new Matrix<T>(n);
        Matrix<T> *Adjoint = new Matrix<T>(n);
        Adjoint = this->Adjoint();
        T x;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                x = Adjoint->GetElement(i, j) / det;
                if (x == -0)
                    x = 0;
                Inverse->SetElement(i, j, x);
            }
        delete Adjoint;
        return Inverse;
    } else
        return NULL;
}

template <class T> Matrix<T>::~Matrix() {
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
}

template <class T> T Matrix<T>::GetMinor(int p, int q) {
    Matrix<T> *Minor = new Matrix<T>(n - 1);
    int r = 0, c = 0;
    T x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != p && j != q) {
                x = GetElement(i, j);
                Minor->SetElement(r, c++, x);
                if (c == n - 1) {
                    c = 0;
                    r++;
                }
            }
        }
    }

    return Minor->Determinant();
}

template <class T> T Matrix<T>::GetCofactor(int r, int c) {
    int sign;
    if ((r + c) % 2)
        sign = -1;
    else
        sign = 1;

    return sign * GetMinor(r, c);
}

// Permissible Types Declaration
template class Matrix<int>;
template class Matrix<long>;
template class Matrix<float>;
template class Matrix<double>;

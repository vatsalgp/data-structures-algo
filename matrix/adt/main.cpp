#include <iostream>

#include "Matrix.h"

int Menu();
void Singular();
void Plural();

// Order of Matrices (Global)
int n;

int main() {
    char ch;
    do {
        switch (Menu()) {
        case 1:
            Singular();
            break;
        case 2:
            Plural();
            break;
        default:
            std::cout << "Wrong Input" << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Do you want to continue?(y/n): ";
        std::cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    return 0;
}

int Menu() {
    int x;
    system("CLS");
    std::cout << "Enter order of matrices: ";
    std::cin >> n;

    system("CLS");
    std::cout << "1.SINGULAR MATRIX OPERATIONS" << std::endl;
    std::cout << "2.PLURAL MATRIX OPERATIONS" << std::endl;
    std::cout << std::endl;
    std::cout << "Choice: ";
    std::cin >> x;
    system("CLS");

    return x;
}

void Singular() {
    int x;
    Matrix<float> *m1 = new Matrix<float>(n);
    Matrix<float> *temp;
    std::cout << "PRIMARY MATRIX" << std::endl;
    m1->Input();
    system("CLS");

    std::cout << "SINGULAR MATRIX OPERATIONS" << std::endl;
    std::cout << "1.Transpose" << std::endl;
    std::cout << "2.Determinant" << std::endl;
    std::cout << "3.Inverse" << std::endl;
    std::cout << std::endl;
    std::cout << "Choice: ";
    std::cin >> x;
    system("CLS");

    switch (x) {
    case 1:
        std::cout << "Original Matrix: " << std::endl;
        m1->Print();
        std::cout << std::endl;
        std::cout << "Its Transpose: " << std::endl;
        temp = m1->Transpose();
        temp->Print();
        break;
    case 2:
        std::cout << "Original Matrix: " << std::endl;
        m1->Print();
        std::cout << std::endl;
        std::cout << "Its determinant is: " << m1->Determinant() << std::endl;
        break;
    case 3:
        std::cout << "Original Matrix: " << std::endl;
        m1->Print();
        std::cout << std::endl;

        temp = m1->Inverse();
        if (temp) {
            std::cout << "Its Inverse: " << std::endl;
            temp->Print();
        } else
            std::cout << "Its Inverse does not exist. " << std::endl;
    }
    delete m1, temp;
}

void Plural() {
    int x;
    Matrix<float> *m1 = new Matrix<float>(n);
    Matrix<float> *m2 = new Matrix<float>(n);
    Matrix<float> *temp;
    std::cout << "PRIMARY MATRIX" << std::endl;
    m1->Input();
    std::cout << std::endl;
    std::cout << "SECONDARY MATRIX" << std::endl;
    m2->Input();
    system("CLS");

    std::cout << "PLURAL MATRIX OPERATIONS" << std::endl;
    std::cout << "1.Add" << std::endl;
    std::cout << "2.Subtract" << std::endl;
    std::cout << "3.Multiply" << std::endl;
    std::cout << std::endl;
    std::cout << "Choice: ";
    std::cin >> x;
    system("CLS");

    switch (x) {
    case 1:
        std::cout << "Primary Matrix: " << std::endl;
        m1->Print();
        std::cout << std::endl;
        std::cout << "Secondary Matrix: " << std::endl;
        m2->Print();
        std::cout << std::endl;
        std::cout << "Their Sum is: " << std::endl;
        temp = m1->Add(m2);
        temp->Print();
        break;
    case 2:
        std::cout << "Primary Matrix: " << std::endl;
        m1->Print();
        std::cout << std::endl;
        std::cout << "Secondary Matrix: " << std::endl;
        m2->Print();
        std::cout << std::endl;
        std::cout << "Their Difference is: " << std::endl;
        temp = m1->Subt(m2);
        temp->Print();
        break;
    case 3:
        std::cout << "Primary Matrix: " << std::endl;
        m1->Print();
        std::cout << std::endl;
        std::cout << "Secondary Matrix: " << std::endl;
        m2->Print();
        std::cout << std::endl;
        std::cout << "Their Product is: " << std::endl;
        temp = m1->Mult(m2);
        temp->Print();
        break;
    }
    delete m1, m2, temp;
}

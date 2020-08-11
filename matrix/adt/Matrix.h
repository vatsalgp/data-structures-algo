#pragma once

template <class T>
class Matrix {
public:
	Matrix(int);
	void Input();
	void Print();
	T Determinant();
	Matrix<T>* Transpose();
	Matrix<T>* Inverse();
	Matrix<T>* Add(Matrix<T>*);
	Matrix<T>* Subt(Matrix<T>*);
	Matrix<T>* Mult(Matrix<T>*);
	~Matrix();
private:
	T** a;
	int n;

	T GetElement(int, int);
	void SetElement(int, int, T);
	Matrix<T>* Adjoint();
	T GetCofactor(int , int);
	T GetMinor(int, int);
};

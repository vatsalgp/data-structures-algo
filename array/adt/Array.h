#pragma once

template <class T> class Array {
  private:
    T *a;
    int size;
    int length;

  public:
    Array();
    void display();
    int add(T);
    void insert(int, T);
    void remove(T);
    int search(T);
    T get(int);
    void set(int, T);
    T max();
    T min();
    T sum();
    T avg();
    void reverse();
    void sort();
    ~Array();
};

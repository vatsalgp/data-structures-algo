#pragma once
#include <iostream>

struct Elements {
    int r, c, val;
};

class Sparse {
    int m, n, num;
    Elements *e;

  public:
    Sparse();
    Sparse(int, int, int);
    ~Sparse();
    friend std::istream &operator>>(std::istream &, Sparse *); // Input
    friend std::ostream &operator<<(std::ostream &, Sparse *); // Display
    Sparse *operator+(Sparse *);
};

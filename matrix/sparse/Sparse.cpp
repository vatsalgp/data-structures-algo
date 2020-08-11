#include "Sparse.h"

Sparse::Sparse() {
    std::cout << "Enter the number of rows: ";
    std::cin >> m;
    std::cout << "Enter the number of cols: ";
    std::cin >> n;
    std::cout << "Enter the number of non zero elements: ";
    std::cin >> num;
    std::cout << std::endl;
    e = new Elements[num];
}

Sparse::Sparse(int m, int n, int num) {
    this->m = m;
    this->n = n;
    this->num = num;
    this->e = new Elements[num];
}

Sparse::~Sparse() { delete[] e; }

std::istream &operator>>(std::istream &in, Sparse *s) {
    std::cout << "Enter the row number, column number and the value: "
              << std::endl;
    for (int i = 0; i < s->num; i++) {
        std::cin >> s->e[i].r >> s->e[i].c >> s->e[i].val;
    }
    std::cout << std::endl;
    return in;
}

std::ostream &operator<<(std::ostream &out, Sparse *s) {
    std::cout << "The Matrix is: " << std::endl;
    int k = 0;
    for (int i = 0; i < s->m; i++) {
        for (int j = 0; j < s->n; j++) {
            if (i == s->e[k].r && j == s->e[k].c) {
                std::cout << s->e[k].val << " ";
                k++;
            } else
                std::cout << "0 ";
        }
        std::cout << std::endl;
    }
    return out;
}

Sparse *Sparse::operator+(Sparse *s) {
    Sparse *sum = new Sparse(m, n, num + s->num);

    int i = 0, j = 0, k = 0;
    while (i < num && j < s->num) {
        if (e[i].r < s->e[j].r) {
            sum->e[k++] = e[i++];
        } else if (s->e[j].r < e[i].r) {
            sum->e[k++] = s->e[j++];
        } else {
            if (e[i].c < s->e[j].c) {
                sum->e[k++] = e[i++];
            } else if (s->e[j].c < e[i].c) {
                sum->e[k++] = s->e[j++];
            } else {
                sum->e[k].r = e[k].r;
                sum->e[k].c = e[k].c;
                sum->e[k].val = e[k].val + s->e[k].val;
                i++;
                j++;
                k++;
            }
        }
    }
    while (i < num) {
        sum->e[k++] = e[i++];
    }
    while (j < s->num) {
        sum->e[k++] = s->e[j++];
    }
    sum->num = k;

    Sparse *s2 = new Sparse(m, n, k);

    for (int l = 0; l < k; l++) {
        s2->e[l] = sum->e[l];
    }

    delete sum;

    return s2;
}

#include "Sort.h"
#include <limits.h>

void Sort::Bubble(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        int flag = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                Swap(a[j], a[j + 1]);
                flag++;
            }
        }
        if (!flag)
            break;
    }
}

void Sort::Insertion(int *a, int n) {

    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int temp = a[i];
        while (j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

void Sort::Selection(int *a, int n) {
    int i, j, k;
    for (i = 0; i < n - 1; i++) {
        for (j = k = i; j < n; j++) {
            if (a[j] < a[k])
                k = j;
        }
        Swap(a[k], a[i]);
    }
}

void Sort::Quick(int *a, int n) {
    _Quick(a, 0, n - 1);
}

void Sort::Merge(int *a, int n) { 
    _Merge(a, 0, n - 1); 
}

void Sort::Swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int Sort::Partition(int *a, int l, int h) {
    Swap(a[l], a[(l + h) / 2]);
    int i = l + 1, j = h, pivot = a[l];
    while (i < j) {
        while (i < h && a[i] <= pivot)
            i++;
        while (j > l && a[j] >= pivot)
            j--;
        if (i < j)
            Swap(a[i], a[j]);
    }
    if (a[j] < a[l])
        Swap(a[l], a[j]);
    return j;
}

void Sort::_Quick(int *a, int l, int h) {
    if (l < h) {
        int mid = Partition(a, l, h);
        _Quick(a, l, mid - 1);
        _Quick(a, mid + 1, h);
    }
}

void Sort::_Merge(int *a, int l, int h) {
    if (l < h) {
        int m = (l + h) / 2;

        _Merge(a, l, m);
        _Merge(a, m + 1, h);

        int i = l, j = m + 1, k = 0;
        int *b = new int[(long long)h - l + 1];

        while (i <= m && j <= h) {
            if (a[i] < a[j])
                b[k++] = a[i++];
            else
                b[k++] = a[j++];
        }
        while (i <= m) {
            b[k++] = a[i++];
        }
        while (j <= h) {
            b[k++] = a[j++];
        }
        for (i = 0; l <= h; l++, i++) {
            a[l] = b[i];
        }

        delete[] b;
    }
}

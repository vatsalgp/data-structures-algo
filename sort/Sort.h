#pragma once

class Sort {
  public:
    static void Bubble(int *a, int n);
    static void Insertion(int *a, int n);
    static void Selection(int *a, int n);
    static void Quick(int *a, int n);
    static void Merge(int *a, int n);

  private:
    static void Swap(int &x, int &y);
    static void _Quick(int *a, int l, int h);
    static void _Merge(int *a, int l, int h);
};

#include <iostream>
#include <cstring>

using namespace std;

int n;

int *&funA(int **&p);

void funB(int *c, int **p, int **q);

int main() {
    int a[100], b[100], c[100];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    int **p, **q;
    funA(p) = a;
    funA(q) = b;
    funB(c, p, q);
    for (int i = 0; i < n; ++i)
        cout << c[i] << " ";
    return 0;
}

// 写出两个函数的定义
int *&funA(int **&p) {
    p = new int *;
    return *p;
}

void funB(int *c, int **p, int **q) {
    for (int i = 0; i < 98; i++)
        c[i] = (*p)[i] * (*q)[i];
    delete p;
    delete q;
}
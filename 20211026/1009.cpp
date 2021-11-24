#include <bits/stdc++.h>

using namespace std;
int a[100005] = {0};

int main() {
    void BinarySort(int a[], int head, int tail, int b);
    int n, m, b;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int j = 0; j < m; j++) {
        cin >> b;
        if (a[n - 1] < b)
            cout << "-1" << endl;
        else if (a[0] >= b)
            cout << a[0] << endl;
        else
            BinarySort(a, 0, n - 1, b);
    }
    return 0;
}

void BinarySort(int a[], int head, int tail, int b) {
    int mid = (head + tail) / 2;
    if (a[mid] == b) {
        cout << a[mid] << endl;
        return;
    }
    if (head + 1 == tail && a[head] < b && a[tail] >= b) {
        cout << a[tail] << endl;
        return;
    }
    if (a[mid] > b)
        BinarySort(a, head, mid, b);
    if (a[mid] < b)
        BinarySort(a, mid, tail, b);
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    void BinarySort(int a[], int head, int tail, int c);
    int n, m, a[100005] = {0}, c;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int j = 1; j <= n; j++) {
        cin >> c;
        BinarySort(a, 0, n, c);
    }
    return 0;
}
//1 3 6 10 15
void BinarySort(int a[], int head, int tail, int c) {
    int mid = (head + tail) / 2;
    if (a[mid] == c) {
        cout << mid << " " << a[mid] - a[mid - 1] << endl;
        return;
    }
    if (head + 1 == tail && a[head] < c && a[tail] >= c) {
        cout << tail << " " << c - a[head] << endl;
        return;
    }
    if (a[mid] > c)
        BinarySort(a, head, mid, c);
    if (a[mid] < c)
        BinarySort(a, mid, tail, c);
}
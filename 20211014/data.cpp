#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 3, x = 4, p = 7;
    srand((unsigned) time(NULL));
    cout << n << " " << x << " " << p << endl;
    for (int i = 0; i <= n; i++)
        cout << rand() % 100 + 1 << " " << rand() % 100 + 1 << " " << rand() % 100 + 1 << endl;
    return 0;
}
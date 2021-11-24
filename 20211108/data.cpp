#include <bits/stdc++.h>

using namespace std;

int main() {
    srand((unsigned) time(NULL));
    const int m = 25, mod = 500;
    cout << "1 " << m << endl;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++)
            cout << rand() % mod + 1 << " ";
        cout << endl;
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
#define int long long
int binary[50] = {0};
int mod[50] = {0};
const int kMod = 2019;

signed main() {
    int a, n, cursor = 0;
    int ans = 1;
    cin >> a >> n;
    mod[0] = a;
    while (n >= 1) {
        binary[cursor] = n % 2;
        n /= 2;
        cursor++;
    }

    int num = a;
    for (int i = 1; i < cursor; i++)
        mod[i] = (mod[i - 1] * mod[i - 1]) % kMod;

    for (int i = 0; i < cursor; i++)
        if (binary[i])
            ans = (ans * mod[i]) % kMod;

    cout << ans << endl;
    return 0;
}
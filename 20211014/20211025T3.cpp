#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    int Remainer(int y, int p, int head, int tail);
    int QuickPow(int a, int b, int p);
    int n, x, p, ans = 0;
    cin >> n >> x >> p;
    for (int i = 0; i <= n; i++) {
        int a, y, k;
        cin >> a >> y >> k;
        int temp = a * Remainer(y, p, 0, k) % p;
        temp = (QuickPow(x, i, p) * temp) % p;
        ans = (ans + temp) % p;
    }
    cout << ans << endl;
    return 0;
}

int Remainer(int y, int p, int head, int tail) {
    int QuickPow(int a, int b, int p);
    if (head == tail)
        return QuickPow(y, head, p);
    if ((tail - head) % 2) {
        int mid = (head + tail) / 2;
        int left = Remainer(y, p, head, mid);
        int right = (QuickPow(y, mid - head + 1, p) * left) % p;
        return (left + right) % p;
    } else {
        int tail_ = tail - 1;
        int mid = (head + tail_) / 2;
        int left = Remainer(y, p, head, mid);
        int right = (QuickPow(y, mid - head + 1, p) * left) % p;
        return (((left + right) % p) + QuickPow(y, tail, p)) % p;
    }
}

int QuickPow(int a, int b, int p) {
    if (!b)
        return 1;
    int binary[60] = {0}, mod[60] = {0}, index = b, i = 0, ans = 1;
    mod[0] = a % p;
    while (index) {
        binary[i] = index % 2;
        index /= 2;
        i++;
    }
    for (int j = 1; j < i; j++)
        mod[j] = (mod[j - 1] * mod[j - 1]) % p;
    for (int j = 0; j < i; j++)
        if (binary[j])
            ans = (ans * mod[j]) % p;
    return ans;
}
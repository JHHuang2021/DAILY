#include <bits/stdc++.h>

using namespace std;
#define int long long
int factorial[25] = {1};
int f[25] = {0};
int finger[25] = {0};
int ans[25] = {0};

signed main() {
    int FingerToInt(int array[], int num);
    void IntToFinger(int num, int _n);
    int n, m, _ans;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        f[i] = i;
        factorial[i] = factorial[i - 1] * i;
    }
    for (int i = 1; i <= n; i++)
        cin >> finger[i];
    _ans = FingerToInt(finger, n) + m;
    IntToFinger(_ans-1, n);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    return 0;
}

int FingerToInt(int array[], int n) {
    int sum = 1;
    for (int i = 1; i <= n; i++) {
        sum += (f[array[i]] - 1) * factorial[n - i];
        for (int j = i + 1; j <= n; j++)
            if (array[i] < array[j])
                f[array[j]]--;
    }
    return sum;
}

void IntToFinger(int num, int n) {
    vector<int> available;
    for (int i = 1; i <= n; i++)
        available.push_back(i);
    for (int i = 1; i <= n; i++) {
        finger[i] = num / factorial[n - i];
        num %= factorial[n - i];
    }
    for (int i = 1; i <= n; i++) {
        ans[i] = available[finger[i]];
        available.erase(available.begin()+finger[i]);
    }
}
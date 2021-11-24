#include <bits/stdc++.h>

using namespace std;
int dp[1005][1005];
int pyramid[1005][1005];

int main() {
    int n, _max = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> pyramid[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + pyramid[i][j];
    for (int j = 1; j <= n; j++)
        _max = max(_max, dp[n][j]);
    cout << _max << endl;
    return 0;
}
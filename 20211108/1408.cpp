#include <bits/stdc++.h>

using namespace std;
#define int long long
int p[1005][1005] = {0};
int n, m, a, b;

signed main() {
    bool check(int aver);
    int tmp = 0;
    cin >> n >> m >> a >> b;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> p[i][j];
            tmp += p[i][j];
            p[i][j] += p[i - 1][j];
        }
    int l = 0, r = tmp / (a * b) + 1;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l;
    return 0;
}

bool check(int aver) {
    int an = 0, bn = 0, flag = 0;//区块
    int rst = 1, red = 1, cst = 0, ced = 0, sum = 0;
    while (an < a && red <= n) {
        sum = 0;
        ced = cst;
        while (sum < aver && ced < m) {
            ced++;
            sum += (p[red][ced] - p[rst - 1][ced]);
        }
        if (sum < aver) {
            red++;
            bn = 0;
            cst = ced = 0;
        } else {
            bn++;
            cst = ced;
            if (bn >= b) {
                an++;
                bn = 0;
                red = rst = red + 1;
                cst = ced = 0;
            }
        }
    }
    if (an >= a)
        return true;
    else
        return false;
}
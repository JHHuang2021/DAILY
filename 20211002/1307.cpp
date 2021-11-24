#include <bits/stdc++.h>

using namespace std;
int dot[2005][2005] = {0};
int op[2005][2005] = {0};

int main() {
    int m, n, k;
    int a, b, c, d;
    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            cin >> dot[i][j];
            op[i][j] = op[i][j - 1] + dot[i][j];
        }
    for (int i = 1; i <= k; i++) {
        int ans = 0;
        cin >> a >> b >> c >> d;
        for (int j = a; j <= c; j++)
            ans += (op[j][d] - op[j][b - 1]);
        cout << ans << endl;
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
int a[2005] = {0}, b[2005] = {0};
int ansdays[2005] = {0}, book[2005] = {0};
int n, m;//n:number of trees m:days
int ans = 0;

int main() {
    void dfs(int sdays, int fdays, int last_ans, int last_index);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    if (n < m) {
        for (int i = 1; i <= n; i++)
            a[i] += (b[i] * (m - n));
        m = n;
    }
    dfs(1, m, 0, 0);
    cout << ans << endl;
    return 0;
}

void dfs(int sdays, int fdays, int last_ans, int last_index) {
    if (sdays == fdays + 1)
        ans = max(ans, last_ans);
    for (int i = 1; i <= n; i++) {
        if (book[i] || b[i] < b[last_index])
            continue;
        else {
            book[i] = 1;
            dfs(sdays + 1, fdays, last_ans + a[i] + b[i] * (sdays - 1), i);
            book[i] = 0;
        }
    }
}
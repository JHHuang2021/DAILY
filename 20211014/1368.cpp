#include <bits/stdc++.h>

using namespace std;
int f[2005][2005] = {0};
struct node {
    int a = 0;
    int b = 0;
} tree[2005];
int n, m;

bool cmp(node c, node d) {
    if (c.b != d.b)
        return c.b < d.b;
    else
        return c.a < d.a;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> tree[i].a;
    for (int i = 1; i <= n; i++)
        cin >> tree[i].b;

    sort(tree + 1, tree + n + 1, cmp);
    int _max = 0;
    for (int i = 1; i <= n; i++) {
        f[1][i] = max(_max, tree[i].a);
        _max = f[1][i];
    }
    _max = 0;
    for (int i = 1; i <= m; i++) {
        f[i][1] = max(_max, tree[1].a + (i - 1) * tree[1].b);
        _max = f[i][1];
    }
    for (int i = 2; i <= m; i++)
        for (int j = 2; j <= n; j++)
            f[i][j] = max(f[i][j - 1], f[i - 1][j - 1] + tree[j].a + (i - 1) * tree[j].b);
    cout << f[m][n] << endl;
    return 0;
}
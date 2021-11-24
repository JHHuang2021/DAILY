#include <bits/stdc++.h>

using namespace std;
const int kNum = 1e6 + 5;
int a[kNum] = {0};
int ans[kNum] = {0};

signed main() {
    int n;
    int ans_ = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    ans[0] = a[0];
    for (int i = 1; i < n; i++) {
        ans[i] = max(ans[i - 1] + a[i], a[i]);
        ans_ = max(ans_, ans[i]);
    }
    cout << ans_ << endl;
    return 0;
}
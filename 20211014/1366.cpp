#include <bits/stdc++.h>

using namespace std;
#define int long long
priority_queue<int, vector<int>, greater<int> > gala_array;

signed main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        gala_array.push(temp);
    }
    for (int j = 0; j < n-1; j++) {
        int together = 0;
        for (int i = 0; i < 2; i++) {
            together += gala_array.top();
            gala_array.pop();
        }
        ans += together;
        gala_array.push(together);
    }
    cout << ans << endl;
    return 0;
}
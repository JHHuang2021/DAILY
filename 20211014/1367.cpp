#include <bits/stdc++.h>

using namespace std;
#define int long long
int bridge_left[500005] = {0};

signed main() {
    int Return_Func(int tail, int bridge[]);
    int n, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> bridge_left[i];
    sort(bridge_left, bridge_left + n);
    int a = bridge_left[0], b = bridge_left[1];
    if (n == 1 || n == 2)
        cout << bridge_left[n - 1] << endl;
    else {
        for (int tail = n - 1; tail >= 1; tail -= 2) {
            if (tail == 1) {
                sum += b;
                break;
            }
            if (tail == 2) {
                sum += (a + b + bridge_left[2]);
                break;
            }
            if (a + bridge_left[tail - 1] > 2 * b)
                sum += (a + 2 * b + bridge_left[tail]);
            else
                sum += (2 * a + bridge_left[tail - 1] + bridge_left[tail]);
        }
        cout << sum << endl;
    }
    return 0;
}
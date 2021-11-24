#include <bits/stdc++.h>

using namespace std;
int num_array[10005] = {0};
int n, m;//m for quary
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> num_array[i];
    for (int i = 0; i < m; i++) {
        int quiry_array[105] = {0};
        int vis[10005] = {0};
        int bucket_sort[10005] = {0};
        int ans, q;
        cin >> q;
        int head = 0, tail = 0;
        for (int j = 0; j < q; j++) {
            cin >> quiry_array[j];
            vis[quiry_array[j]] = 1;
        }
        for (int j = head; j <= tail; j++)
            bucket_sort[num_array[j]]++;
        for (int j = 0; j < q; j++)
            while (!bucket_sort[quiry_array[j]]) {
                tail++;
                bucket_sort[num_array[tail]]++;
            }
        ans = tail - head + 1;
        while (1) {
            int flag = 0;
            bucket_sort[num_array[head]]--;
            while (vis[num_array[head]] && !bucket_sort[num_array[head]]) {
                if (tail == n - 1) {
                    flag = 1;
                    break;
                }
                tail++;
                bucket_sort[num_array[tail]]++;
            }
            if (flag)
                break;
            else
                head++;
            ans = min(ans, tail - head + 1);
        }
        cout << ans << endl;
    }
    return 0;
}
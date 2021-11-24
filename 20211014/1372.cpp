#include <bits/stdc++.h>

using namespace std;

struct node {
    int h = 0;
    int w = 0;
    int hw;
    int r = 0;
} cow[1005], cow_h_up[1005], cow_w_up[1005];
int vish[1005] = {0};

bool cmp(node m, node n) {
    return m.hw < n.hw;
}

bool cmp_h_up(node m, node n) {
    return m.h < n.h;
}

bool cmp_w_up(node m, node n) {
    return m.w < n.w;
}

int main() {
    int n, a, b, c;
    int ans = 0;
    cin >> n >> a >> b >> c;
    for (int i = 1; i <= n; i++) {
        cin >> cow[i].h >> cow[i].w;
        cow[i].hw = a * cow[i].h + b * cow[i].w;
        cow[i]. r= i;
        cow_h_up[i] = cow[i];
        cow_w_up[i] = cow[i];
    }
    sort(cow + 1, cow + n + 1, cmp);
    sort(cow_w_up + 1, cow_w_up + n + 1, cmp_w_up);
    sort(cow_h_up + 1, cow_h_up + n + 1, cmp_h_up);
    for (int h_head = 1; h_head <= n; h_head++) {
        int cnt = 0;
        int head = 1, w_head = 1;
        int visw[1005] = {0};
        for (; w_head <= n; w_head++) {
            int flag = 0;
            while (a *cow_w_up[w_head].h > a * cow_h_up[h_head].h + c ||
                                       b * cow_h_up[h_head].w > b * cow_w_up[w_head].w + c ||
                                       visw[cow_w_up[w_head].r] || vish[cow_w_up[w_head].r]) {
                if (w_head == n) {
                    visw[cow_w_up[w_head].r] = 1;
                    flag = 1;
                    break;
                }
                visw[cow_w_up[w_head].r] = 1;
                w_head++;
            }
            if (flag)
                break;
            for (; head <= n; head++)
                if (cow[head].hw > a * cow_h_up[h_head].h + b * cow_w_up[w_head].w + c)
                    break;
                else if (visw[cow[head].r] || vish[cow[head].r])
                    continue;
                else if (cow[head].hw <= a * cow_h_up[h_head].h + b * cow_w_up[w_head].w + c)
                    cnt++;
            ans = max(ans, cnt);
            visw[cow_w_up[w_head].r] = 1;
            cnt--;
        }
        vish[cow_h_up[h_head].r] = 1;
    }
    cout << ans << endl;
    return 0;
}
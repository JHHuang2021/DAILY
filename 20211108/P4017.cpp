#include <bits/stdc++.h>

using namespace std;
struct node {
    int to = 0;
    int next = 0;
} edge[500005];
struct topo {
    int in = 0;
    int out = 0;
} dot[5005];
int head[5005] = {0}, cnt = 0, ans[5005] = {0};
const int kmod = 80112002;

void add_edge(int u, int v) {
    edge[++cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt;
}

int main() {
    vector<int> p, q;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        dot[u].out++;
        dot[v].in++;
        add_edge(u, v);
    }
    for (int i = 1; i <= n; i++) {
        if (dot[i].out != 0)
            p.push_back(i);
        else
            q.push_back(i);
        if (dot[i].in == 0)
            ans[i] = 1;
    }
    while (!p.empty()) {
        for (auto iter = p.begin(); iter != p.end(); iter++) {
            if (dot[*iter].in == 0) {
                for (int tmp = head[*iter]; tmp; tmp = edge[tmp].next) {
                    ans[edge[tmp].to] += ans[*iter];
                    ans[edge[tmp].to] %= kmod;
                    dot[edge[tmp].to].in--;
                }
                p.erase(iter);
                break;
            }
        }
    }
    for (int &iter: q) {
        ans[0] += ans[iter];
        ans[0] %= kmod;
    }
    cout << ans[0];
    return 0;
}
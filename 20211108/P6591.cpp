#include <bits/stdc++.h>

using namespace std;
struct node {
    int to = 0;
    int next = 0;
} edge[100005];
int head[100005] = {0}, cnt = 0, size[100005] = {0};

void add_edge(int u, int v) {
    edge[++cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt;
};

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
        add_edge(v, u);
    }
    for (int i = 1; i <= n; i++) {
        int cntt = 0;
        for (int tmp = head[i]; tmp; tmp = edge[tmp].next)
            cntt++;
        size[i] = cntt;
    }
    for (int i = 1; i <= n; i++) {
        int cmp = size[edge[head[i]].to], flag = 0;
        for (int tmp = head[i]; tmp; tmp = edge[tmp].next) {
            if (cmp != size[edge[tmp].to]) {
                flag = 1;
                break;
            }
        }
        if (!flag)
            printf("%d ", i);
    }
    return 0;
}
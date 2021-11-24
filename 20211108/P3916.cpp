#include <bits/stdc++.h>

using namespace std;
struct node {
    int to = 0;
    int next = 0;
} edge[100005];
int head[100005] = {0}, vis[100005] = {0}, preans[100005];
int cnt = 0;

void add_edge(const int &st, const int &ed) {
    edge[++cnt].to = ed;
    edge[cnt].next = head[st];
    head[st] = cnt;
}

void dfs(const int &index, int &tmp_ans) {
    if (preans[index]) {
//        tmp_ans = max(tmp_ans, preans[index]);
        tmp_ans = tmp_ans > preans[index] ? tmp_ans : preans[index];
        return;
    }
    for (int tmp = head[index]; tmp; tmp = edge[tmp].next) {
        if (vis[edge[tmp].to])
            continue;
        else
            vis[edge[tmp].to] = 1;
        if (tmp_ans < edge[tmp].to)
            tmp_ans = edge[tmp].to;
        dfs(edge[tmp].to, tmp_ans);
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
    }
    for (int i = 1; i <= n; i++) {
        int ans = 0;
        memset(vis, 0, sizeof(vis));
        dfs(i, ans);
        ans = ans > i ? ans : i;
//        ans = max(ans, i);
        preans[i] = ans;
        printf("%d ", ans);
    }
    return 0;
}
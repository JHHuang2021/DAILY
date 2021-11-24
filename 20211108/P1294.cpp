#include <bits/stdc++.h>

using namespace std;
struct node {
    int to = 0;
    int next = 0;
    int w = 0;
} edge[100];
int head[100] = {0}, vis[100] = {0}, cnt = 0, ans = 0, an = 0;

void add_edge(int u, int v, int w) {
    edge[++cnt].to = v;
    edge[cnt].next = head[u];
    edge[cnt].w = w;
    head[u] = cnt;
}

void dfs(const int &index, const int &dis) {
    ans = max(ans, dis);
    for (int tmp = head[index]; tmp; tmp = edge[tmp].next) {
        if (vis[edge[tmp].to])
            continue;
        else
            vis[edge[tmp].to] = 1;
        dfs(edge[tmp].to, dis + edge[tmp].w);
        vis[edge[tmp].to] = 0;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        vis[i] = 1;
        ans = 0;
        dfs(i, 0);
        an = max(an, ans);
    }
    cout << an << endl;
    return 0;
}
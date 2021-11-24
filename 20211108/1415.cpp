#include <bits/stdc++.h>

using namespace std;
struct node {
    int to;
    int next;
} edge[200005];
struct node1 {
    int m;
    int M;
} dot[200005];
int head[200005] = {0}, dot_order[200005] = {0};
int cnt = 0;

void add_edge(int u, int v) {
    edge[++cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt;
}

void dfs(int index) {
    dot_order[index] = ++cnt;
    dot[index].m = cnt;
    for (int tmp = head[index]; tmp; tmp = edge[tmp].next)
        if (dot_order[edge[tmp].to] == 0)
            dfs(edge[tmp].to);
    dot[index].M = cnt;
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
        add_edge(v, u);
    }
    cnt = 0;
    dfs(1);
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        if (dot_order[x] <= dot[y].M && dot_order[x] > dot[y].m)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
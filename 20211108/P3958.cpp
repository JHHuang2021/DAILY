#include <bits/stdc++.h>

using namespace std;
#define int long long
struct coor {
    int x;
    int y;
    int z;
} centre[1005];
struct edge {
    int to = 0;
    int next = 0;
} edge[500005];
int head[1005] = {0}, vis[1005] = {0}, cnt = 0, avail = 0;

inline double dist(coor dot1, coor dot2) {
    return sqrt((dot1.x - dot2.x) * (dot1.x - dot2.x) + (dot1.y - dot2.y) * (dot1.y - dot2.y) +
                (dot1.z - dot2.z) * (dot1.z - dot2.z));
}

void add_edge(int u, int v) {
    edge[++cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt;
}

void dfs(int index, int r, int h) {
    if (avail)
        return;
    if (centre[index].z + r >= h) {
        avail = 1;
        return;
    }
    for (int tmp = head[index]; tmp; tmp = edge[tmp].next) {
        if (vis[edge[tmp].to])
            continue;
        else
            vis[edge[tmp].to] = 1;
        dfs(edge[tmp].to, r, h);
    }
}

signed main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n, h, r;
        vector<int> st;
        cnt = 0;
        memset(head, 0, sizeof(head));
        memset(edge, 0, sizeof(edge));
        memset(centre, 0, sizeof(centre));
        memset(vis, 0, sizeof(vis));
        cin >> n >> h >> r;
        for (int j = 1; j <= n; j++) {
            cin >> centre[j].x >> centre[j].y >> centre[j].z;
            for (int k = 1; k <= j - 1; k++) {
//                double dis = dist(centre[j], centre[k]);
                if (dist(centre[j], centre[k]) <= 2.0 * r) {
                    add_edge(j, k);
                    add_edge(k, j);
                }
            }
        }
        for (int j = 1; j <= n; j++)
            if (centre[j].z - r <= 0)
                st.push_back(j);
        avail = 0;
        for (int &j: st) {
            vis[j] = 1;
            dfs(j, r, h);
            if (avail)
                break;
        }
        if (avail)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
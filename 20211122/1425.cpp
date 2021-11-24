#include <bits/stdc++.h>

using namespace std;
char mp[55][55];
int n, m, sx, sy, ans = 1e5;
int downy, downx = 0;
typedef pair<int, int> ppoint;
typedef pair<ppoint, int> stat;

ppoint operator+(const ppoint &lhs, const ppoint &rhs) {
    return {lhs.first + rhs.first, lhs.second + rhs.second};
}

ppoint dp[8] = {{1,  1},{1,  -1},{-1, 1},{-1, -1},{1,  0},{0,  -1},{-1, 0},{0,  1}};
ppoint st;
map<stat, int> dist;
queue<stat> q;

bool check(const stat &now, const stat &nxt) {//valid
    if (now.first.first == downx && nxt.first.first == downx + 1 || now.first.first > downx)
        if (now.first.second > downy && nxt.first.second <= downy)
            return true;
    return false;
}

bool check2(const stat &now, const stat &nxt) {//invalid
    if (now.first.first == downx && nxt.first.first == downx + 1 || now.first.first > downx)
        if (now.first.second <= downy && nxt.first.second > downy)
            return true;
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == '*')
                st = {i, j};
            if (mp[i][j] == 'X')
                if (i > downx) {
                    downx = i;
                    downy = j;
                }
        }
    q.push({st, 0});
    dist[{st, 0}] = 0;
    while (!q.empty()) {
        stat now = q.front();
        q.pop();
        for (const auto &i: dp) {
            stat nxt;
            nxt.first = now.first + i;
            if (mp[nxt.first.first][nxt.first.second] == 'X' || nxt.first.first < 1 || nxt.first.second < 1 ||
                nxt.first.first > n || nxt.first.second > m)
                continue;
            nxt.second = now.second | check(now, nxt);
            if (dist.find(nxt) != dist.end() || check2(now, nxt))
                continue;
            dist[nxt] = dist[now] + 1;
            q.push(nxt);
        }
    }
    cout << dist[{st, 1}] << endl;
    return 0;
}
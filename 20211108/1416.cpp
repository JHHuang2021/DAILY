#include <bits/stdc++.h>

using namespace std;
char maze[210][80];
int vis[210][80] = {0};
int ans[210][80] = {0};
int step[4][2] = {{-2, 0},
                  {2,  0},
                  {0,  2},
                  {0,  -2}};
int w, h;

struct Coor {
    int x = 0;
    int y = 0;
    int cnt = 0;

    bool operator==(const Coor &xy) const {
        if (x == xy.x && y == xy.y)
            return true;
        else
            return false;
    }
} coor[2];

void dfs(Coor start) {
    queue<Coor> q;
    vis[start.x][start.y] = 1;
    q.push(start);
    while (!q.empty()) {
        for (int i = 0; i <= 3; i++) {
            Coor next;
            next.x = q.front().x + step[i][0];
            next.y = q.front().y + step[i][1];
            if (vis[next.x][next.y])
                continue;
            if (next.x < 1 || next.y < 1 || next.x > 2 * h + 1 || next.y > 2 * w + 1)
                continue;
            if (maze[q.front().x + step[i][0] / 2][q.front().y + step[i][1] / 2] != ' ')
                continue;
            vis[next.x][next.y] = 1;
            next.cnt = q.front().cnt + 1;
            q.push(next);
            if (ans[next.x][next.y])
                ans[next.x][next.y] = min(ans[next.x][next.y], next.cnt);
            else
                ans[next.x][next.y] = next.cnt;
        }
        q.pop();
    }
}

int main() {
    int cnt = 0, cntt = 0, answer = 0;
    cin >> w >> h;
    getchar();
    for (int i = 1; i <= 2 * h + 1; i++) {
        for (int j = 1; j <= 2 * w + 1; j++) {
            scanf("%c", &maze[i][j]);
            if (i == 1 && maze[i][j] == ' ')
                if (coor[cnt].x == 0 && coor[cnt].y == 0) {
                    coor[cnt].x = i - 1;
                    coor[cnt].y = j;
                    cnt++;
                }
            if (i == 2 * h + 1 && maze[i][j] == ' ')
                if (coor[cnt].x == 0 && coor[cnt].y == 0) {
                    coor[cnt].x = i + 1;
                    coor[cnt].y = j;
                    cnt++;
                }
            if (j == 1 && maze[i][j] == ' ')
                if (coor[cnt].x == 0 && coor[cnt].y == 0) {
                    coor[cnt].x = i;
                    coor[cnt].y = j - 1;
                    cnt++;
                }
            if (j == 2 * w + 1 && maze[i][j] == ' ')
                if (coor[cnt].x == 0 && coor[cnt].y == 0) {
                    coor[cnt].x = i;
                    coor[cnt].y = j + 1;
                    cnt++;
                }
        }
        getchar();
    }
    memset(vis, 0, sizeof(vis));
    dfs(coor[0]);
    memset(vis, 0, sizeof(vis));
    dfs(coor[1]);
    for (int i = 1; i <= 2 * h + 1; i++)
        for (int j = 1; j <= 2 * w + 1; j++)
            answer = max(answer, ans[i][j]);
    cout << answer << endl;
    return 0;
}
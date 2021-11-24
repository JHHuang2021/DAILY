#include <bits/stdc++.h>

using namespace std;
struct node {
    double x;
    double y;
} dot[3];

int main() {
    double a, b;
    double sym[3];
    for (int i = 0; i < 3; i++)
        cin >> dot[i].x >> dot[i].y;
    cin >> a >> b;
    for (int i = 0; i < 3; i++) {
        int j = (i + 1) % 3;
        int k = (i + 2) % 3;
        sym[i] = ((dot[j].y - dot[k].y) * a - (dot[j].x - dot[k].x) * b + dot[j].x * dot[k].y - dot[k].x * dot[j].y) *
                 ((dot[j].y - dot[k].y) * dot[i].x - (dot[j].x - dot[k].x) * dot[i].y + dot[j].x * dot[k].y -
                  dot[k].x * dot[j].y);
    }
    if (sym[0] < 0 || sym[1] < 0 || sym[2] < 0)
        cout << "outside";
    else if (sym[0] > 0 && sym[1] > 0 && sym[2] > 0)
        cout << "inside";
    else
        cout << "false";
    return 0;
}


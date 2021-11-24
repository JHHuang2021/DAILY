#include <bits/stdc++.h>

using namespace std;
const int kMod = 1e9 + 7;

struct node {
    long long r = 0;
    long long list_rank = 0;

    bool operator==(node b) const {
        if (this->r == b.r)
            return true;
        else
            return false;
    }
};

int main() {
    long long rank_(long long matrix[35][35], long long m);
    vector<node> r;
    long long matrix[35][35] = {0};
    long long n, m;
    cin >> n >> m;
    for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= m; j++)
            for (long long k = 1; k <= m; k++)
                cin >> matrix[j][k];
        node tmp;
        tmp.r = rank_(matrix, m);
        tmp.list_rank = i;
        r.push_back(tmp);
    }
//    for (int i = 0; i < r.size(); i++)
//        cout << r[i].r << ' ';
//    cout << endl;
    auto last = unique(r.begin(), r.end());
    r.erase(last, r.end());
    cout << r.size() << endl;
    for (long long i = 0; i < r.size(); i++)
        cout << r[i].list_rank << " ";
    cout << endl;
    return 0;
}

long long rank_(long long matrix[35][35], long long m) {
    void sub_multi(const long long matrix_r1[], long long matrix_r2[], long long c, long long m);
    long long c = 1, r = 1, cnt = 0;
    while (r <= m) {
        while (matrix[r][c] == 0 && c <= m)
            c++;
        if (c == m + 1) {
            c = 1;
            r++;
            continue;
        } else {
            for (long long j = r + 1; j <= m; j++)
                if (matrix[j][c] != 0)
                    sub_multi(matrix[r], matrix[j], c, m);
            r++;
            c = 1;
        }
    }
    for (long long i = 1; i <= m; i++) {
        for (long long j = 1; j <= m; j++)
            if (matrix[i][j]) {
                cnt++;
                break;
            }
    }
    return cnt;
}

void sub_multi(const long long matrix_r1[], long long matrix_r2[], long long c, long long m) {
    long long r1 = matrix_r1[c], r2 = matrix_r2[c];
    for (long long i = 1; i <= m; i++)
        matrix_r2[i] = (matrix_r2[i] * r1 - matrix_r1[i] * r2) % kMod;
}
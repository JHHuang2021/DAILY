#include <bits/stdc++.h>

using namespace std;
int num_array[10005] = {0};
int n, m;//m for quary
int main() {
    int LeastLength(int num[], int length);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> num_array[i];
    for (int i = 0; i < m; i++) {
        int quiry_array[105] = {0};
        int q;
        cin >> q;
        for (int j = 0; j < q; j++)
            cin >> quiry_array[j];
        cout << LeastLength(quiry_array, q) << endl;
    }
    return 0;
}

int LeastLength(int num[], int length) {
    bool FindNum(int num[], int num_length, int head, int tail);
    int head = 0, tail = 0, ans = 1e5 + 5;
    while (tail < n) {
        while (!FindNum(num, length, head, tail)) {
            tail++;
            if (tail >= n)
                return ans;
        }
        while (FindNum(num, length, head, tail))
            head++;
        ans = min(ans, tail - head + 2);
        head++;
    }
    return ans;
}

bool FindNum(int num[], int num_length, int head, int tail) {
    int bucketsort[10005] = {0};
    for (int i = head; i <= tail; i++)
        bucketsort[num_array[i]]++;
    for (int i = 0; i < num_length; i++)
        if (bucketsort[num[i]] == 0)
            return false;
    return true;
}
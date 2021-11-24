#include <bits/stdc++.h>

using namespace std;
int A[10005] = {0};
int fix[10005] = {0};

int main() {
    char op;
    int n, k, x, y;
    string str;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    while ((op = getchar()) != EOF) {
        switch (op) {
            case '1':
                cin >> x;
                cout << A[x] << endl;
                break;
            case '2':
                cin >> k;
                for (int i = 0; i < k; i++) {
                    cin >> x >> y;
                    A[x] = y;
                }
                break;
            case '3':
                int j = 0;
                getline(cin, str);
                for (int i = 0; i <= str.length(); i++) {
                    if (str[i] <= '9' && str[i] >= '0' && str[i - 1] <= '9' && str[i - 1] >= '0') {
                        fix[j - 1] = fix[j - 1] * 10 + str[i] - '0';
                    } else if (str[i] != ' ') {
                        fix[j] = str[i] - '0';
                        j++;
                    }

                }

                for (int i = 0; i < j-1; i += 2)
                    A[fix[i]] = fix[i + 1];
                break;
        }
    }
    return 0;
}
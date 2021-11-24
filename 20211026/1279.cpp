#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int length, cnt = 0;
        char ch[60], up[60];
        cin >> length;
        scanf("%s", ch);
        strcpy(up, ch);
        sort(up, up + length);
        for (int j = 0; j < length; j++)
            if (ch[j] != up[j])
                cnt++;
        cout << cnt << endl;
    }
    return 0;
}
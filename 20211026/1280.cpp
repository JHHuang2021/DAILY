#include <bits/stdc++.h>

using namespace std;

int main() {
    int k;
    char ch[10];
    scanf("%s %d", ch, &k);
    sort(ch, ch + strlen(ch));
    for (int i = 1; i < k; i++)
        next_permutation(ch, ch + strlen(ch));
    printf("%s", ch);
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

template<class T>
T pow(T base, int exp, T MOD = 19260817) {
    if (!exp)
        return 1;
    base %= MOD;
    int binary[40] = {0}, index = exp, i = 0, ans = 1;
    T mod[40] = {base};
    while (index) {
        binary[i] = index % 2;
        index /= 2;
        i++;
    }
    for (int j = 1; j < i; j++)
        mod[j] = (mod[j - 1] * mod[j - 1]) % MOD;
    for (int j = 0; j < i; j++)
        if (binary[j])
            ans = (ans * mod[j]) % MOD;
    return ans;
}

int main() {
    long long a = 1000000;
    unsigned int b = 10;
    short c = 100000;
    long int d = 10;
    cout << pow(a, 2) << " " << pow(b, 2) << " " << pow(c, 2) << " " << pow(d, 2) << " " << endl;
    return 0;
}
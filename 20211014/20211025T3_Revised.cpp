#include <bits/stdc++.h>
using namespace std;

const long long N = 1e6 + 5, M = 50;
const long long ooo = 1;
long long n, x, p;
long long pow2[M];
long long ppow[M];
long long tot;

void init(long long y)
{
    long long now = tot;
    ppow[0] = 1;
    long long ty = y;
    for (long long i = 1; i < M; i++)
    {
        ppow[i] = ((1 + ty) * ppow[i - 1]) % p;
        ty = (ty * ty) % p;
        // printf("ppow[%lld] = %lld\n", i, ppow[i]);
    }
    return;
}

long long highbit(long long x)
{
    for (long long i = M - 1; i; i--)
        if ((ooo << i) <= x)
            return i;
    return 0;
}

long long qpow(long long x, long long n)
{
    long long ans = 1;
    // printf("pow(%lld,%lld) = ",x,n);
    while (n)
    {
        if (n & 1)
            ans = (ans * x) % p;
        x = (x * x) % p;
        n >>= 1;
    }
    // printf("%lld\n",ans);
    return ans;
}

long long calc(long long y, long long k)
{
    if (!k)
        return 0;
    long long tb = highbit(k);
    // printf("%lld\n",tb);
    // printf("del %lld\n",(ooo<<tb));
    // printf("ppow[%lld] = %lld\n",tb,ppow[now][tb]);
    return (calc(y, k - (ooo << tb)) + (qpow(y, k - (ooo << tb)) * ppow[tb]) % p) % p;
}

signed main()
{
    scanf("%lld%lld%lld", &n, &x, &p);
    long long ans = 0;
    long long tx = 1;
    tot = 0;
    for (long long i = 0; i <= n; i++)
    {
        long long a, y, k;
        scanf("%lld%lld%lld", &a, &y, &k);
        init(y);
        long long tans = calc(y, k + 1);
        // printf("tans = %lld\n", tans);
        ans = (ans + ((tans * a) % p * tx) % p) % p;
        tx = (tx * x) % p;
    }
    printf("%lld\n", ans % p);
}
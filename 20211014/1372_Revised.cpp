
#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 10000
int wmin,hmin,cnt,ptr,A,B,C,ht[N],wt[N],wcnt[100001];
struct node
{
    int w,h;
    void input(int i)
    {
        scanf("%d%d",&h,&w);
        ht[i] = h;
        wt[i] = w;
    }
}arr[N];

bool cmp(node a,node b)
{
    return a.h * A + a.w * B < b.h * A + b.w * B;
}
int main()
{
    int i,j,k,n;
    scanf("%d%d%d%d",&n,&A,&B,&C);
    for(i = 0; i < n; ++i)
        arr[i].input(i);
    sort(ht,ht+n);
    sort(wt,wt+n);
    sort(arr,arr+n,cmp);
    int cnt,res = 0,val;
    for(i = 0; i < n; ++i)
    {
        cnt = 0;
        hmin = ht[i];
        val = C + ht[i] * A;
        k = 0;
        for(j = 0; j < n; ++j)
        {
            wmin = wt[j];
            val += wmin * B;
            for(; k < n; ++k)
            {
                if(arr[k].h * A + arr[k].w * B > val)
                    break;
                if(arr[k].h >= hmin && arr[k].w >= wmin)
                    ++cnt,++wcnt[arr[k].w];
            }
            if(j)
                cnt -= wcnt[wt[j-1]],wcnt[wt[j-1]] = 0;
            val -= wmin * B;
            if(cnt > res)
                res  = cnt;
        }
    }
    printf("%d\n",res);
//    while(1);
    return 0;
}
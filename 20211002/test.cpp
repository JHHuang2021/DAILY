#include <bits/stdc++.h>
using namespace std;
template<class T> T _max(T a,T b);
int main()
{
    cout<<_max(1.5,2.6)<<endl;//实例化
}
template<class T>T _max(T a,T b)
{
    return a>b?a:b;
}
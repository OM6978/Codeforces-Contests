#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N,x,y;
    cin>>N>>x>>y;

    int ar[N];
    if(y > 1)ar[y-2] = -1;
    if(x<N)ar[x] = -1;

    for(int i=y-3;i>=0;i--)
    {
        ar[i] = 0-ar[i+1];
    }

    for(int i=x+1;i<N;i++)
    {
        ar[i] = 0 - ar[i-1];
    }

    for(int i=y-1;i<x;i++)
    {
        ar[i] = 1;
    }

    for(int i=0;i<N;i++)
    {
        cout<<ar[i]<<' ';
    }
    cout<<'\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/OneDrive/Contest-Codeforces/input.txt", "r", stdin);
        freopen("/home/om/OneDrive/Contest-Codeforces/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
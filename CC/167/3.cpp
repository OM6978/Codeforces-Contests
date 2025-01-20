#include <bits/stdc++.h>
using namespace std;

#define int long long

int findwins(int x1,int x2)
{
    return (x2 - x1)/2;
}

void solve()
{
    int N;
    cin>>N;

    int x;
    cin>>x;

    int ar[--N];
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    sort(ar,ar+N);

    int in = lower_bound(ar,ar+N,x) - ar;
    
    if(in == N)
    {
        int e16 = 1e6;
        cout << findwins(ar[in-1],x) + e16 - x + 1 << '\n';
    }
    else if(in == 0)
    {
        cout << x + findwins(x,ar[in]) << '\n';
    }
    else
    {
        cout << findwins(x,ar[in]) + findwins(ar[in-1],x) + 1 << '\n';
    }
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
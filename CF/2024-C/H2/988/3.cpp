#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    if(N<=4)
    {
        cout << -1 << '\n';
        return;
    }

    for(int i=1;i<=N;i+=2)
    {
        if(i==5)continue;
        cout << i << ' ';
    }

    cout << 5 << ' ' << 4 << ' ';
    for(int i=2;i<=N;i+=2)
    {
        if(i==4)continue;
        cout << i << ' ';
    }
    cout << '\n';
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
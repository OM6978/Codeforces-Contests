#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N,M;
    cin>>N>>M;

    int x,y;
    cin>>x>>y;

    int ans = 4*M;
    for(int i=1;i<N;i++)
    {
        cin>>x>>y;
        ans += 4*M - 2*(M-x) - 2*(M-y);
    }

    cout << ans << '\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    int freqz[N+1];
    for(int i=1;i<=N;i++)freqz[i] = 0;

    int ar[N];
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        freqz[ar[i]]++;
    }

    int ans = 0;
    for(int i=1;i<=N;i++)
    {
        ans += freqz[i]/2;
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
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
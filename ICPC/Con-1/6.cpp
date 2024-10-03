#include <bits/stdc++.h>
using namespace std;

#define int long long

int MOD = 1e9 + 7;
int dp[21];

void get_dp()
{
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    dp[2] = 1;

    int mult;
    for(int i=3;i<21;i++)
    {
        mult = 1;
        for(int j=i-1;j>=1;j--)
        {
            mult = mult*j;
            dp[i] = (dp[i] + mult*dp[j-1])%MOD;
        }
    }
}

void solve()
{
    int N;
    cin>>N;

    cout<<dp[N]<<'\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    get_dp();
    solve();
    
    return 0;
}
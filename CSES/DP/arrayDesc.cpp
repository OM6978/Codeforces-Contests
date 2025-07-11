#include <bits/stdc++.h>
using namespace std;

#define int long long

int MOD = 1e9 + 7;

int solvedp(int in,int val,vector<int> & ar,vector<vector<int>> & dp)
{
    int N = dp.size(),M = dp[0].size()-1;
    if(val > M || val < 1)return 0;
    if(in == N-1)return 1;
    if(dp[in][val]!=-1)return dp[in][val];

    if(ar[in+1] != 0)
    {
        if(abs(ar[in+1] - val) > 1)
        {
            return dp[in][val] = 0;
        }
        else
        {
            return dp[in][val] = solvedp(in+1,ar[in+1],ar,dp);
        }
    }

    int ans = 0;

    ans = (ans + solvedp(in+1,val-1,ar,dp))%MOD;
    ans = (ans + solvedp(in+1,val,ar,dp))%MOD;
    ans = (ans + solvedp(in+1,val+1,ar,dp))%MOD;

    return dp[in][val] = ans;
}

void solve()
{
    int N,M;
    cin>>N>>M;

    vector<int> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    vector<vector<int>> dp(N,vector<int> (M+1,-1));

    int ans = 0;
    if(ar[0] == 0)
    {
        for(int i=1;i<=M;i++)
        {
            ans = (ans + solvedp(0,i,ar,dp))%MOD;
        }
    }
    else
    {
        ans = solvedp(0,ar[0],ar,dp);
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
    
    solve();

    return 0;
}
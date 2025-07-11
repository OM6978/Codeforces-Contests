#include <bits/stdc++.h>
using namespace std;

int solvedp(int in,int left,vector<int> & price,vector<int> & pages,vector<vector<int>> & dp)
{
    static int N = dp.size();

    if(in == N)return 0;
    if(dp[in][left]!=0)return dp[in][left];

    int ans = 0;

    if(price[in] <= left)ans = solvedp(in+1,left - price[in],price,pages,dp) + pages[in];
    ans = max(ans,solvedp(in+1,left,price,pages,dp));

    return dp[in][left] = ans;
}

void solve()
{
    int N,x;
    cin>>N>>x;
    
    vector<int> price(N),pages(N);
    for(int i=0;i<N;i++)
    {
        cin>>price[i];
    }

    for (int i=0; i<N; i++)
    {
        cin>>pages[i];
    }
    
    vector<vector<int>> dp(N+1,vector<int> (x+1,0));

    // Memoization
    
    // cout << solvedp(0,x,price,pages,dp) << '\n';

    // Tabulation

    for(int i=N-1;i>=0;i--)
    {
        for(int p=x;p>=0;p--)
        {
            if(p < price[i])dp[i][p] = dp[i+1][p];
            else dp[i][p] = max(dp[i+1][p - price[i]] + pages[i],dp[i+1][p]);
        }
    }

    cout << dp[0][x] << '\n';
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
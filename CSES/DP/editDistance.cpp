#include <bits/stdc++.h>
using namespace std;

int solvedp(int i,int j,string & a,string & b,vector<vector<int>> & dp)
{
    int n = dp.size(),m = dp[0].size();

    if(i==n && j==m)return 0;
    if(i==n)return m - j;
    if(j==m)return n - i;
    if(dp[i][j]!=-1)return dp[i][j];

    int ans = 1e5;
    
    ans = min(ans,solvedp(i,j+1,a,b,dp) + 1);
    ans = min(ans,solvedp(i+1,j,a,b,dp) + 1);
    ans = min(ans,solvedp(i+1,j+1,a,b,dp) + (a[i] != b[j]));
    
    return dp[i][j] = ans;
}

void solve()
{
    string a,b;
    cin>>a>>b;

    int n = a.size(),m = b.size();
    vector<vector<int>> dp(n,vector<int> (m,-1));

    cout << solvedp(0,0,a,b,dp) << '\n';
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
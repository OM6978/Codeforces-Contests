#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll MOD = 1e9 + 7;

void solve()
{
    int N;
    cin>>N;

    vector<vector<int>> mat(N,vector<int>(N));
    for(int i=0;i<N;i++)
    {
        string s;
        cin>>s;

        for(int j=0;j<s.size();j++)
        {
            mat[i][j] = s[j];
        }
    }

    ll dp[N][N];
    dp[0][0] = (mat[0][0] != '*');

    for(int i=1;i<N;i++)dp[i][0] = dp[i-1][0]*(mat[i][0]!='*');
    for(int j=1;j<N;j++)dp[0][j] = dp[0][j-1]*(mat[0][j]!='*');

    for(int i=1;i<N;i++)
    {
        for(int j=1;j<N;j++)
        {
            dp[i][j] = (mat[i][j]!='*')*((dp[i-1][j] + dp[i][j-1]) % MOD);
        }
    }

    cout << dp[N-1][N-1] << '\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/Om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/Om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    solve();

    return 0;
}
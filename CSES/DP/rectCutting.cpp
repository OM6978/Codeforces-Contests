#include <bits/stdc++.h>
using namespace std;

const int maxl = 500;
int dp[maxl+1][maxl+1];

void solve()
{
    int a,b;
    cin>>a>>b;

    cout << dp[a][b] << '\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);

    for(int a = 1;a<=maxl;a++)
    {
        for(int b = 1;b<=maxl;b++)
        {
            if(a == b)
            {
                dp[a][b] = 0;
            }
            else
            {
                dp[a][b] = 1e9;
                for(int x = 1;x<a;x++)
                {
                    dp[a][b] = min(dp[a][b],dp[a - x][b] + dp[x][b] + 1);
                }
    
                for(int y=1;y<b;y++)
                {
                    dp[a][b] = min(dp[a][b],dp[a][b-y] + dp[a][y] + 1);
                }
            }
        }
    }
    
    solve();

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define int long long

int MOD = 1e9 + 7;

void solve()
{
    int N;
    cin>>N;

    vector<int> dp(N+1,0);
    dp[0] = 1;
    for(int i=1;i<=N;i++)
    {
        for(int dice=1;dice<=6;dice++)
        {
            if(i - dice >= 0)
            {
                dp[i] = (dp[i] + dp[i - dice])%MOD;
            }
        }
    }

    cout << dp[N] << '\n';
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
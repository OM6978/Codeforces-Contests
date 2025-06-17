#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    vector<int> dp(N+1,1e9);
    dp[N] = 0;
    for(int x = N;x>=0;x--)
    {
        if(dp[x] < 1e9)
        {
            int y = x;
            while(y!=0)
            {
                int dig = y%10;
                dp[x - dig] = min(dp[x - dig],dp[x] + 1);
                y/=10;
            }
        }
    }

    cout << dp[0] << '\n';
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
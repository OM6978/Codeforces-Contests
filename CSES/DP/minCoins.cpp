#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N,x;
    cin>>N>>x;

    vector<int> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    vector<int> dp(x+1,1e9);
    dp[0] = 0;
    for(int val=1;val<=x;val++)
    {
        for(int i=0;i<N;i++)
        {
            int coin = ar[i];
            if(val - coin >= 0)
            {
                dp[val] = min(dp[val],dp[val - coin] + 1);
            }
        }
    }

    cout << ((dp[x] >= 1e9)?-1:dp[x]) << '\n';
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
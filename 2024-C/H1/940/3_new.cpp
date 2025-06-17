#include <bits/stdc++.h>
using namespace std;

#define int long long

int MOD = 1e9 + 7;
int dp[(int)(3e5+1)] = {0};

void solve()
{
    int N,K;
    cin>>N>>K;

    while(K--)
    {
        int a,b;
        cin>>a>>b;

        if(a==b)N-=1;
        else N-=2;
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

    dp[1] = 1;
    dp[0] = 1;
    for(int N = 2;N <= 3e5;N++)
    {
        dp[N] = ((dp[N-2] * 2 % MOD * (N-1) % MOD) + dp[N-1]) % MOD;
    }
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
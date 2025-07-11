#include <bits/stdc++.h>
using namespace std;

#define int long long

int MOD = 1e9 + 7;

const int maxN = 1e6;
int dp[maxN+1][6];

void solve()
{
    int N;
    cin>>N;

    int ans = 0;
    for(int i=0;i<6;i++)ans+=dp[N][i];
    ans%=MOD;

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

    dp[1][0] = 0;       // empty
    dp[1][1] = 1;       // hori full line
    dp[1][2] = 0;       // vert line
    dp[1][3] = 0;       // hori + verti
    dp[1][4] = 0;       // verti + hori
    dp[1][5] = 1;       // hori + verti + hori

    for(int n=2;n<=maxN;n++)
    {
        int s = 0;
        for(int i=0;i<6;i++)s = (s + dp[n-1][i])%MOD;

        dp[n][0] = (dp[n-1][0] + dp[n-1][1])%MOD;
        dp[n][1] = s;
        dp[n][2] = (dp[n-1][2] + dp[n-1][3] + dp[n-1][4] + dp[n-1][5])%MOD;
        dp[n][3] = (dp[n-1][2] + dp[n-1][3] + dp[n-1][4] + dp[n-1][5])%MOD;
        dp[n][4] = (dp[n-1][2] + dp[n-1][3] + dp[n-1][4] + dp[n-1][5])%MOD;
        dp[n][5] = s;
    }
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
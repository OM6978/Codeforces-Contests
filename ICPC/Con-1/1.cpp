#include <bits/stdc++.h>
using namespace std;

#define int long long

int MOD = 1e9+7;

void solve()
{
    int N,M,K;
    cin>>N>>M>>K;

    string s;
    if(M!=0)cin>>s;

    vector<int> m1[10];

    m1[0] = {4,6};
    m1[1] = {6,8};
    m1[2] = {7,9};
    m1[3] = {4,8};
    m1[4] = {9,3,0};
    m1[5] = {};
    m1[6] = {1,7,0};
    m1[7] = {6,2};
    m1[8] = {1,3};
    m1[9] = {2,4};                                      

    int dp[10][N+1];
    memset(dp,0,sizeof(dp));

    bool possible = true;
    for(int i=1;i<s.size();i++)
    {
        int a_d = s[i] - '0';
        vector<int> & v = m1[s[i-1] - '0'];
        if(find(v.begin(),v.end(),a_d) == v.end())possible = false;
    }

    for(int num = 0;num<=9;num++)if(K!=5)dp[num][0]++;

    for(int i=1;i<=N;i++)
    {
        for(int num = 0;num<=9;num++)
        {
            for(int a : m1[num])
            {
                dp[num][i] = (dp[num][i] + dp[a][i-1])%MOD;
                if(M!=0 && possible && a == s[0] - '0' && i >= M)dp[num][i] = (dp[num][i] - dp[s[M-1] - '0'][i-M] + MOD)%MOD;
            }
        }
    }

    cout << dp[K][N] << '\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N,M;
    cin>>N>>M;

    int ar[N];
    vector<int> poss; 
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        if(ar[i] == 0)poss.push_back(i);
    }
    poss.push_back(N);

    int dp[M+1];
    int ls_i[M+1],ls_s[M+1];

    for(int i=0;i<=M;i++)dp[i] = 0;

    for(int point = M-1;point>=0;point--)
    {
        for(int i=0;i<=M;i++)ls_i[i] = 0,ls_s[i] = 0;

        for(int i=poss[point]+1;i<poss[point+1];i++)
        {
            if(ar[i] > 0)ls_i[ar[i]]++;
            else ls_s[0-ar[i]]++;
        }

        for(int i=1;i<=M;i++)ls_i[i]+=ls_i[i-1],ls_s[i]+=ls_s[i-1];

        for(int intlgn = 0;intlgn <= point;intlgn++)
        {
            int strength = point - intlgn;
            int ans1 = dp[intlgn+1] + ls_i[intlgn+1] + ls_s[strength];
            int ans2 = dp[intlgn] + ls_i[intlgn] + ls_s[strength+1];

            dp[intlgn] = max(ans1,ans2);
        }
    }

    cout << dp[0] << '\n';
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
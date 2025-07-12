#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define sp ' '
#define int long long

void solve()
{
    int n,x;
    cin>>n>>x;

    vector<int> pref(n);

    int ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
        pref[i] = (i!=0)*pref[i-1] + ar[i];
    }

    vector<int> dp (n,-1);

    auto solvedp = [&](int in,auto && solvedp) -> int
    {
        if(in >= n)return 0;
        if(dp[in] != -1)return dp[in];

        int in2 = lower_bound(pref.begin(),pref.end(),x + (in!=0)*pref[in-1] + 1) - pref.begin();

        dp[in] = (in2-in) + solvedp(in2+1,solvedp);
        return dp[in];
    };

    int ans = 0;
    for(int i=0;i<n;i++)
        ans += solvedp(i,solvedp);

    cout<< ans <<endl;
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/OneDrive/Contest-Codeforces/input.txt", "r", stdin);
        freopen("/home/om/OneDrive/Contest-Codeforces/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

void solve()
{
    int N;
    cin>>N;

    int ans = lower_bound(dp.begin(),dp.end(),N) - dp.begin() + 1;
    cout << ans << '\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    dp.push_back(1);
    while(dp.back()<1e5)
    {
        dp.push_back(dp.back()*2 + 2);
    }

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
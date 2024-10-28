#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    string ans;
    ans.push_back('1');
    for(int i=0;i<N-1;i++)
    {
        ans.push_back('0');
    }

    cout << ans << '\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
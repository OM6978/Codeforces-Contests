#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s,t;
    cin>>s>>t;

    int N = min(s.size(),t.size());

    int ans = s.size() + t.size();
    int lol = 0;
    
    for(int i=0;i<N;i++)
    {
        if(s[i] == t[i])ans--,lol=1;
        else break;
    }

    cout << ans + lol<< '\n';
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
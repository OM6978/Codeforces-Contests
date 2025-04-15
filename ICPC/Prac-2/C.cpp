#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N,X;
    cin>>N>>X;

    string s;
    cin>>s;

    multiset<int,greater<int>> ms;

    int ans=0;
    int curr=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i] == '0')curr++;
        else
        {
            ans++;
            ms.insert(curr);
            curr=0;
        }
    }
    ms.insert(curr);

    while(ms.size()!=0 && X>0)
    {
        int top = *ms.begin();
        ms.erase(ms.begin());

        int added = min(top,((X-1)/2));
        ans += added;
        X -= added*2 + 1;
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
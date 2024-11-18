#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N,K;
    cin>>N>>K;

    map<int,int> bottles;
    for(int i=0;i<K;i++)
    {
        int b,c;
        cin>>b>>c;

        bottles[b]+=c;
    }

    multiset<int,greater<int>> ms;
    for(auto [x,y] : bottles)
    {
        ms.insert(y);
    }

    int least = min(N,(int)ms.size()),ans=0;
    while(least--)
    {
        ans+= *ms.begin();
        ms.erase(ms.begin());
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
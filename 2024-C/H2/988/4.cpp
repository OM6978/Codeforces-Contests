#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N,M,L;
    cin>>N>>M>>L;

    vector<pair<int,int>> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i].first>>ar[i].second;
    }

    vector<pair<int,int>> pows(M);
    for(int i=0;i<M;i++)
    {
        cin>>pows[i].first>>pows[i].second;
    }

    int ans = 0;
    int curr = 0,pow=1;
    multiset<int,greater<int>> ms;
    for(int i=0;i<N;i++)
    {
        auto [l,r] = ar[i];

        while(pows[curr].first < l && curr<M)
        {
            ms.insert(pows[curr++].second);
        }

        int dist = r-l+2;
        while(pow<dist && ms.size()!=0)
        {
            pow += *ms.begin();
            ms.erase(ms.begin());
            ans++;
        }

        if(pow<dist)
        {
            cout << -1 << '\n';
            return;
        }
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
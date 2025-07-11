#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    vector<vector<int>> tree(N+1);
    
    for(int i=0;i<N-1;i++)
    {
        int u,v;
        cin>>u>>v;
    
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int most = 1;
    for(int u=1;u<=N;u++)
    {
        if(tree[most].size() < tree[u].size())
        {
            most = u;
        }
    }

    int ans = 1;
    if(tree[most].size()!=0)ans+=tree[most].size()-1;
    else ans--;

    for(int v : tree[most])
    {
        tree[v].erase(find(tree[v].begin(),tree[v].end(),most));
    }

    tree[most].clear();

    most = 1;
    for(int u=1;u<=N;u++)
    {
        if(tree[most].size() < tree[u].size())
        {
            most = u;
        }
    }

    if(tree[most].size()!=0)ans+=tree[most].size()-1;
    else ans--;

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
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
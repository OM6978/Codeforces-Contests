#include <bits/stdc++.h>
using namespace std;

int dfs(int u,vector<vector<int>> & tree,vector<int> & ans)
{
    for(int v : tree[u])
    {
        ans[u] += dfs(v,tree,ans);
    }

    return 1 + ans[u];
}

void solve()
{
    int N;
    cin>>N;

    vector<vector<int>> tree(N+1,vector<int>());

    for(int i=2;i<=N;i++)
    {
        int t;
        cin>>t;
        tree[t].push_back(i);
    }

    vector<int> ans(N+1,0);

    dfs(1,tree,ans);
    for(int i=1;i<=N;i++)
    {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    solve();
    
    return 0;
}
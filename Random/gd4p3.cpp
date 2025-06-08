#include <bits/stdc++.h>
using namespace std;

int dfs(int u,vector<vector<int>> & graph,vector<int> & prevs)
{
    if(prevs[u] != -2)return prevs[u];

    int N = graph.size() - 1;

    int ret = (u == N)?0:-1;

    for(int v : graph[u])
    {
        int val = dfs(v,graph,prevs);
        if(val == -1)continue;

        ret = max(ret,val + 1);
    }

    return prevs[u] = ret;
}

void solve()
{
    int N,M;
    cin>>N>>M;

    vector<vector<pair<int,int>>> graph(N+1);
    
    for(int i=0;i<M;i++)
    {
        int u,v,c;
        cin>>u>>v>>C;
    
        graph[u].push_back({v,c});
    }

    vector<int> prevs(N+1,-2);

    int ans = dfs(1,graph,prevs);

    if(ans == -1)cout << "IMPOSSIBLE\n";
    else cout << ans << '\n';
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
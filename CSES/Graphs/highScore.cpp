#include <bits/stdc++.h>
using namespace std;

#define int long long

bool dfs(int u,int V,vector<vector<pair<int,int>>> & adj,vector<int> & vis)
{
    if(u == V)return true;

    if(vis[u])return false;
    vis[u] = 1;

    for(auto [v,_] : adj[u])
    {
        if(dfs(v,V,adj,vis))return true;
    }

    return false;
}

vector<int> bellman_ford(int V, vector<vector<pair<int,int>>> & adj)
{
    vector<int> ans(V+1,1e15);
    set<int> nono;

    ans[1] = 0;
    for(int i=0;i<V;i++)
    {
        for(int u=1;u<=V;u++)
        {
            for(auto [v,c] : adj[u])
            {
                if(ans[u] != 1e15 && ans[u] + c < ans[v])
                {
                    if(i==V-1)
                    {
                        nono.insert(u);
                        nono.insert(v);
                    }
                        
                    ans[v] = ans[u] + c;
                }
            }
        }
    }

    vector<int> vis(V+1,0);
    for(int a : nono)
    {
        if(dfs(a,V,adj,vis))
        {
            ans[V] = 1;
            break;
        }
    }

    return ans;
}

void solve()
{
    int N,M;
    cin>>N>>M;

    vector<vector<pair<int,int>>> graph(N+1);
        
    for(int i=0;i<M;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
    
        graph[u].push_back({v,-c});
    }

    auto ans = bellman_ford(N,graph);

    cout << -ans[N] << '\n';
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
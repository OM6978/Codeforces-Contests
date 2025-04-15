#include <bits/stdc++.h>
using namespace std;

int dfs(int u,int num,int K,vector<vector<int>> & graph)
{
    if(num == K)return 1;

    int ans = 0;
    for(int v : graph[u])
    {
        ans += dfs(v,num+1,K,graph);
    }

    return ans;
}

void solve()
{
    int N,E,K;
    cin>>N>>E>>K;

    vector<vector<int>> graph(N+1);
    
    for(int i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;
    
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int ans = 0;
    for(int i=1;i<=N;i++)
    {
        ans += dfs(i,1,K,graph);
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
    cin.tie(NULL);cout.tie(NULL);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
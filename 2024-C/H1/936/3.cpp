#include <bits/stdc++.h>
using namespace std;

#define spc " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define vv_int vector<vector<int>>

int no_clusters=0;

int dfs(vv_int &tree, int u, int par, int x_req)
{
    int nodes_in_subtree=1;
    for (auto &v : tree[u])
    {
        if(v!=par)
            nodes_in_subtree += dfs(tree,v,u,x_req);
    }
    if(nodes_in_subtree>=x_req)
    {
        nodes_in_subtree=0;
        no_clusters++;
    }
    return nodes_in_subtree;
}

int good(int x,vv_int &tree,int K)
{
    no_clusters=0;
    dfs(tree,1,-1,x);
    
    return (no_clusters>K);
}

void solve()
{
    int N,K;
    cin>>N>>K;
    vv_int tree(N+1,vector<int>());
    
    for(int i=0;i<N-1;i++)
    {
        int u,v;
        cin>>u>>v;
    
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    int l=1,r=N;
    while(l<r-1)
    {
        int mid = (l+r)/2;
        if(good(mid,tree,K))l=mid;
        else r=mid;
    }
    cout<<l<<endl;
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
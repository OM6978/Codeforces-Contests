#include <bits/stdc++.h>
using namespace std;

void assigncompnums(int in,int compnum,vector<vector<int>> & graph,vector<int> & compnums,vector<int> & vis)
{
    compnums[in] = compnum;

    vis[in] = 1;
    for(int v : graph[in])
    {
        if(vis[v] == 0)
            assigncompnums(v,compnum,graph,compnums,vis);
    }
}

int getcompnums(vector<vector<int>> & graph,vector<int> & compnums)
{
    int N = graph.size() - 1,num=0;
    vector<int> vis(N+1,0);

    for(int i=1;i<=N;i++)
    {
        if(vis[i] == 0)
        {
            assigncompnums(i,num,graph,compnums,vis);
            num++;
        }
    }

    return num;
}

void solve()
{
    int N,m1,m2;
    cin>>N>>m1>>m2;
    
    vector<vector<int>> graph1(N+1,vector<int>());
    vector<vector<int>> graph2(N+1,vector<int>());

    for(int i=0;i<m1;i++)
    {
        int u,v;
        cin>>u>>v;
    
        graph1[u].push_back(v);
        graph1[v].push_back(u);
    }

    for(int i=0;i<m2;i++)
    {
        int u,v;
        cin>>u>>v;
    
        graph2[u].push_back(v);
        graph2[v].push_back(u);
    }

    vector<int> compnums(N+1);

    int comp1 = getcompnums(graph2,compnums);

    int ans = 0;
    
    vector<int> curr;
    for(int i=1;i<=N;i++)
    {
        int same = 0;
        for(int v : graph1[i])
        {
            if(compnums[v] != compnums[i])
            {
                ans++;
            }
            else curr.push_back(v);
        }

        graph1[i] = curr;
        curr.clear();
    }
    ans>>=1;

    int comp2 = getcompnums(graph1,compnums);

    ans += comp2 - comp1;

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
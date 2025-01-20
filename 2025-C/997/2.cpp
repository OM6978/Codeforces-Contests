#include <bits/stdc++.h>
using namespace std;

void dfs(int u,stack<int> & s,vector<vector<int>> & adj,int* visited)
{
    for(int v : adj[u])
    {
        if(visited[v] == 0)
            dfs(v,s,adj,visited);
    }
    s.push(u);
    visited[u] = 1;
}

vector<int> topoSort(int V, vector<vector<int>> & adj) 
{
    stack<int> s;
    int visited[V];
    for(int i=0;i<V;i++)visited[i] = 0;
    
    for(int u=0;u<V;u++)
    {
        if(visited[u] == 0)
            dfs(u,s,adj,visited);
    }
    
    vector<int> ans;
    while(s.size())
    {
        ans.push_back(s.top());
        s.pop();
    }
    
    return ans;
}

void solve()
{
    int N;
    cin>>N;

    vector<vector<int>> adj(N,vector<int>());

    for(int i=0;i<N;i++)
    {
        string s;
        cin>>s;

        for(int j=0;j<s.size();j++)
        {
            int x = s[j];
            if(x == '1')
            {
                if(i > j)
                {
                    adj[j].push_back(i);
                }
                else
                {
                    adj[i].push_back(j);
                }
            }
        }
    }

    auto v = topoSort(N,adj);
    for(int x : v)
    {
        cout << x+1 << ' ';
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
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
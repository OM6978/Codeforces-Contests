#include <bits/stdc++.h>
using namespace std;

#define int long long

void shortest_distance(vector<vector<int>> & matrix)
{    
    int N = matrix.size() - 1;
    for(int k=1;k<=N;k++)
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                matrix[i][j] = min(matrix[i][j],matrix[i][k] + matrix[k][j]);
            }
        }
    }
}

void solve()
{
    int N,M,Q;
    cin>>N>>M>>Q;

    vector<vector<int>> graph(N+1,vector<int> (N+1,1e15));
    
    for(int i=0;i<M;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;

        graph[u][v] = min(graph[u][v],c);
        graph[v][u] = min(graph[v][u],c);
    }

    for(int i=1;i<=N;i++)
        graph[i][i] = 0;

    shortest_distance(graph);

    while(Q--)
    {
        int u,v;
        cin>>u>>v;

        if(graph[u][v] == 1e15)
        {
            cout << -1 << '\n';
        }
        else cout << graph[u][v] << '\n';
    }
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
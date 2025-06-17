#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N,M;
    cin>>N>>M;

    vector<vector<int>> graph(N+1);
    
    for(int i=0;i<M;i++)
    {
        int u,v;
        cin>>u>>v;
    
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> ans(N+1,0);
    
    queue<int> q;
    
    for(int i=1;i<=N;i++)
    {
        if(ans[i] != 0)continue;
        q.push(i);
        ans[i] = 1;
        while(q.size())
        {
            int cnt = q.size();
            while(cnt--)
            {
                int x = q.front();
                q.pop();
        
                for(int v : graph[x])
                {
                    if(ans[v] == ans[x])
                    {
                        cout << "IMPOSSIBLE\n";
                        return;
                    }
    
                    if(ans[v] == 0)
                    {
                        q.push(v);
                        ans[v] = 3 - ans[x];
                    }
                }
            }
        }
    }

    for(int i=1;i<=N;i++)
    {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/Om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/Om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    solve();

    return 0;
}
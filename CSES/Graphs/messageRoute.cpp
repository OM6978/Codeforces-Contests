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

    vector<int> par(N+1,-1);
    queue<int> q;
    q.push(1);

    bool found = false;
    while(q.size())
    {
        int cnt = q.size();
        while(cnt--)
        {
            int x = q.front();
            q.pop();

            if(x == N)
            {
                found = true;
                break;
            }

            for(int v : graph[x])
            {
                if(par[v] == -1)
                {
                    q.push(v);
                    par[v] = x;
                }
            }
        }

        if(found)break;
    }

    if(found)
    {
        int curr = N;
        vector<int> route;
        route.push_back(N);
        while(curr!=1)
        {
            route.push_back(par[curr]);
            curr = par[curr];
        }

        reverse(route.begin(),route.end());
        cout << route.size() << '\n';
        for(auto x : route)
        {
            cout << x << ' ';
        }
        cout << '\n';
    }
    else
    {
        cout << "IMPOSSIBLE\n";
    }
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
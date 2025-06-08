#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    vector<vector<int>> graph(N+1);
    
    for(int i=0;i<N-1;i++)
    {
        int u,v;
        cin>>u>>v;
    
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    int curr = 1;
    int par = -1;

    for(int i=1;i<N;i++)
    {
        int flag = 0;
        for(int v : graph[curr])
        {
            if(v == par)continue;

            if(v == ar[i])flag=1;
        }

        if(flag == 0)
        {
            cout << "No\n";
            return;
        }

        par = curr;
        curr = ar[i];
    }

    cout << "Yes\n";
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
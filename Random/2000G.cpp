#include <bits/stdc++.h>
using namespace std;

bool good(int t,int t0,int t1,int t2,vector<vector<tuple<int,int,int>>> & graph)
{
    int N = graph.size() - 1;
    bool vis[N+1];
    for(int i=1;i<=N;i++)vis[i] = 0;

    multiset<pair<long long,int>> near;

    near.insert({t,1});

    long long curr = -5;
    while(near.size())
    {
        auto [val,u] = *near.begin();
        near.erase(near.begin());
        if(vis[u])continue;
        vis[u] = 1;

        if(u==N || val > t0){curr = val;break;}

        for(auto [v,l1,l2] : graph[u])
        {
            if(vis[v])continue;

            if(val >= t2 || val + l1 <= t1)
            {
                if(val+l1 <= t0)
                    near.insert({val+l1,v});
            }
            else
            {
                auto lol = min(val+l2,(long long)t2 + l1);
                if(lol <= t0)
                    near.insert({lol,v});
            }
        }
    }

    if(curr==-5)return false;
    return curr <= t0;
}

void solve()
{
    int N,M;
    cin>>N>>M;

    int t0,t1,t2;
    cin>>t0>>t1>>t2;

    vector<vector<tuple<int,int,int>>> graph(N+1);
    
    for(int i=0;i<M;i++)
    {
        int u,v,l1,l2;
        cin>>u>>v>>l1>>l2;
    
        graph[u].push_back({v,l1,l2});
        graph[v].push_back({u,l1,l2});
    }

    int l = -1,r = t0;
    while(l+1<r)
    {
        int mid = (l+r)/2;
        if(good(mid,t0,t1,t2,graph))l=mid;
        else r = mid;
    }

    cout << l << '\n';
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
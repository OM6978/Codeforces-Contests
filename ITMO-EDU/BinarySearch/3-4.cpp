#include <bits/stdc++.h>
using namespace std;

vector<int> ans;

bool give_nodes(int num,int u,int selected,vector<vector<pair<int,int>>> & adj,int N,int D)
{
    if(u == 1)return true;
    if(selected == D)return false;

    for(auto next : adj[u])
    {
        int ci = next.second;
        if(ci <= num)
        {
            ans.push_back(next.first);
            bool lol = give_nodes(num,next.first,selected + 1,adj,N,D);

            if(lol)return true;
            else ans.pop_back();
        }
    }

    return false;
}

int good(int num,int u,int selected,vector<vector<pair<int,int>>> & adj,int N,int D)
{
    if(u == 1)return true;
    if(selected == D)return false;

    for(auto next : adj[u])
    {
        int ci = next.second;
        if(ci <= num && good(num,next.first,selected+1,adj,N,D))return true;
    }

    return false;
}

void solve()
{
    int N,M,D;
    cin>>N>>M>>D;

    vector<vector<pair<int,int>>> adj (N+1,vector<pair<int,int>>());

    for(int i=0;i<M;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;

        adj[v].push_back({u,c});
    }

    int l = -1,r = 1e9 + 1;
    while(l+1<r)
    {
        int mid = (l+r)>>1;
        if(good(mid,N,0,adj,N,D))r = mid;
        else l = mid;
    }

    if(r == (int)(1e9 + 1))cout << -1 << '\n';
    else
    {
        ans.push_back(N);
        give_nodes(r,N,0,adj,N,D);

        reverse(ans.begin(),ans.end());

        cout << ans.size()-1 << '\n';
        for(int a : ans)cout << a << ' ';
        cout << '\n';
    }
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    solve();

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

vector<int> nonps;

void dfs(int u,int par,vector<vector<int>> & tree,vector<int> & ans,vector<bool> & taken,int N)
{
    int curr = 0;
    for(int v : tree[u])
    {
        
        if(v != par)
            dfs(v,u,tree,ans,taken,N);
    }
}

void getans(vector<vector<int>> & tree,vector<int> & ans)
{
    int N = tree.size() - 1;
    vector<bool> taken(N+1,false);
    ans[1] = 1;
    taken[1] = true;
    
    for(int v : tree[1])
    {
        dfs(1,0,tree,ans,taken,N);
    }
}

void solve()
{
    int N;
    cin>>N;

    vector<vector<int>> tree(N+1);
    for(int i=0;i<N;i++)
    {
        int u,v;
        cin>>u>>v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> ans(N+1);
    getans(tree,ans);

    for(int i=1;i<=N;i++)
    {
        int a = ans[i];
        cout << a << ' ';
    }
    cout << '\n';
}

void SieveOfEratosthenes(int n)
{
    vector<bool> prime(n + 1, true);

    for (int p = 2;p*p <= n;p++)
    {
        if(prime[p])
        {
            for(int i = p*p; i <= n; i += p)
                prime[i] = false;
        }
    }

    for (int p = 2; p <= n; p++)
        if(!prime[p])
            nonps.push_back(p);
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    SieveOfEratosthenes(2e5);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
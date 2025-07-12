#include <bits/stdc++.h>
using namespace std;

class DSU
{
public:
    vector<int> P;
    vector<int> rank;
    vector<int> sz;
    int num_disjoint_sets;

    DSU(int n)
    {
        P.resize(n + 1);
        std::iota(P.begin(), P.end(), 0);
        rank.assign(n + 1, 1);
        sz.assign(n + 1, 1);
        num_disjoint_sets = n;
    }

    int get_a(int a)
    {
        if (P[a] == a) {
            return a;
        }
        return P[a] = get_a(P[a]);
    }

    void union_s(int a, int b)
    {
        int l1 = get_a(a);
        int l2 = get_a(b);

        if (l1 == l2) 
        {
            return;
        }

        if (rank[l1] < rank[l2])
        {
            std::swap(l1, l2);
        }

        P[l2] = l1;
        sz[l1] += sz[l2];
        if (rank[l1] == rank[l2]) {
            rank[l1]++;
        }
        num_disjoint_sets--;
    }

    int get_set_size(int a)
    {
        return sz[get_a(a)];
    }

    int get_sz(int par)
    {
        return sz[par];
    }

    int get_num_disjoint_sets()
    {
        return num_disjoint_sets;
    }
};

void solve()
{
    int N,m1,m2;
    cin>>N>>m1>>m2;

    vector<pair<int,int>> Fedges;
    
    for(int i=0;i<m1;i++)
    {
        int u,v;
        cin>>u>>v;

        Fedges.push_back({u,v});
    }

    DSU G(N);

    for(int i=0;i<m2;i++)
    {
        int u,v;
        cin>>u>>v;
    
        G.union_s(u,v);
    }

    vector<vector<int>> sccs(N+1,vector<int>());

    int prev = -1;
    for(int i=1;i<=N;i++)
    {
        int p = G.get_a(i);
        sccs[p].push_back(i);
    }

    DSU F(N);

    int dels = 0;
    for(auto [u,v] : Fedges)
    {
        int pu = G.get_a(u);
        int pv = G.get_a(v);

        if(pu != pv)
        {
            dels++;
        }
        else
        {
            F.union_s(u,v);
        }
    }

    int adds = 0;
    for(auto scc : sccs)
    {
        int curr = -1;
        for(int v : scc)
        {
            int pv = F.get_a(v);
            if(curr == -1)
                curr = pv;
            else if(pv != curr)
            {
                adds++;
                F.union_s(v,curr);
                curr = F.get_a(v);
            }
        }
    }

    cout << adds + dels << '\n';
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
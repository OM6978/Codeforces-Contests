#include <bits/stdc++.h>
#include <format>
using namespace std;

void solve()
{
    int N,M;
    cin>>N>>M;

    vector<vector<int>> graph(N+1);
    vector<vector<int>> invfile(N+1);
    
    for(int i=0;i<M;i++)
    {
        int u,v;
        cin>>u>>v;
    
        graph[u].push_back(v);
        invfile[v].push_back(u);
    }

    vector<int> outdeg(N+1,0);
    for(int i=1;i<=N;i++)
    {
        outdeg[i] = graph[i].size();
    }

    auto cmp = [](const pair<int, int>& a, const pair<int, int>& b)
    {
        if (a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    };

    set<pair<int,int>,decltype(cmp)> ss(cmp);

    for(int i=1;i<=N;i++)
    {
        ss.insert({outdeg[i],i});
    }

    vector<int> ans(N+1);

    int curr = N;
    while(ss.size())
    {
        auto pa = ss.begin();
        auto [_,in] = *pa;

        ss.erase(pa);
        ans[in] = curr--;

        for(int v : invfile[in])
        {
            ss.erase({outdeg[v],v});
            outdeg[v]--;

            ss.insert({outdeg[v],v});
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
    for(int i=1;i<=20;i++)
    {
        ostringstream in;
        ostringstream out;

        in << "/home/om/Acads/Codeforces-Contests/testcases/testcase_" << i << ".txt";
        out << "/home/om/Acads/Codeforces-Contests/testcases/output_" << i << ".txt";\

        string instr = in.str();
        string outstr = out.str();

        freopen(instr.c_str(), "r", stdin);
        freopen(outstr.c_str(), "w", stdout);

        solve();
    }    
    
    return 0;
}
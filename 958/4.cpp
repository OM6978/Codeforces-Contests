#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pp_ii pair<pair<int,int>,pair<int,int>> 

void solve()
{
    int N;
    cin>>N;

    int ar[N+1];
    for(int i=1;i<N+1;i++)cin>>ar[i];

    vector<vector<int>> tree(N+1,vector<int> ());

    for(int i=1;i<N;i++)
    {
        int u,v;
        cin>>u>>v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    tree[1].push_back(0LL);

    int rounds = (int)log2(N) + 1LL;
    vector<pp_ii> dp(N,(pp_ii){{-1,-1},{-1,-1}});
    pp_ii temp;

    auto solvedp = [&tree,&ar,&rounds,&temp,&dp](int in,int par,auto && solvedp) -> pp_ii
    {
        if(tree[in].size() == 1)return {{ar[in],1LL},{2LL*ar[in],2LL}};
        if(dp[in] != (pp_ii){{-1,-1},{-1,-1}})return dp[in];

        int sum[rounds+1];
        for(int i=1;i<=rounds;i++)sum[i] = ar[in]*i;
        
        for(int vt : tree[in])
        {
            if(vt != par)
            {
                temp = solvedp(vt,in,solvedp);
                for(int i=1;i<=rounds;i++)
                {
                    if(i == temp.first.second)sum[i]+=temp.second.first;
                    else sum[i]+=temp.first.first;
                }
            }
        }
        
        int most=1,sec= 2;
        if(rounds != 1 && sum[2] < sum[1])
        {
            sec = 1;
            most = 2;
        }
        
        for(int i=3;i<=rounds;i++)
        {
            if(sum[i] < sum[most])
            {
                sec = most;
                most = i;
            }
            else if(sum[i] < sum[sec])sec = i;
        }

        return {{sum[most],most},{sum[sec],sec}};
    };
    
    temp = solvedp(1,0,solvedp);
    cout<<temp.first.first<<'\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/OneDrive/Contest-Codeforces/input.txt", "r", stdin);
        freopen("/home/om/OneDrive/Contest-Codeforces/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N,M;
    cin>>N>>M;

    int ar[N];
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    vector<pair<int,int>> inp;
    for(int i=0;i<M;i++)
    {
        int x,y;
        cin>>x>>y;

        inp.push_back({x,y});
    }

    sort(inp.begin(),inp.end());

    int least = 0,curr = 0;
    for(int i=0;i<N;i++)
    {
        if(ar[i] < ar[least])least = i;

        while(curr<M && i+1 == inp[curr].first)
        {
            ar[least]-=inp[curr++].second;
        }
    }

    sort(ar,ar+N);

    int sum = 0;
    for(int k=1;k<=N;k++)
    {
        sum+= ar[k-1];
        cout << sum << ' ';
    }
    cout << '\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
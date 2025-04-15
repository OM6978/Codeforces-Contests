#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    string s;
    cin>>s;

    int scores[N+1];
    for(int i=1;i<=N;i++)
    {
        cin>>scores[i];
    }

    vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(N+1,vector<int>(N+1,-1)));

    auto solvedp = [&](int in,int start,int ennd,auto && solvedp)->int
    {
        string prevstr = {s.begin()+start,s.begin()+ennd};

        for(int i=in;i<N;i++)
        {
            if()
        }
    };

    cout << solvedp(0,0,0,solvedp) << '\n';
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
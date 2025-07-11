#include <bits/stdc++.h>
using namespace std;

tuple<int,int,int> solvedp(int i,int j,vector<int> & ar,vector<int> & br,vector<vector<pair<int,int>>> & par,vector<vector<int>> & dp)
{
    int N = dp.size(),M = dp[0].size();

    if(i==N || j==M)return {0,-1,-1};
    if(dp[i][j]!=-1)
    {
        if(ar[i] == br[j])
        {
            return {dp[i][j],i,j};
        }
        else return {dp[i][j],par[i][j].first,par[i][j].second};
    }

    if(ar[i] == br[j])
    {
        auto [val,x,y] = solvedp(i+1,j+1,ar,br,par,dp);
        par[i][j] = {x,y};
        dp[i][j] = val+1;

        return {dp[i][j],i,j};
    }

    auto [val1,x1,y1] = solvedp(i+1,j,ar,br,par,dp);
    auto [val2,x2,y2] = solvedp(i,j+1,ar,br,par,dp);

    int val;
    pair<int,int> parent;
    if(val1 > val2)
    {
        val = val1;
        parent = {x1,y1};
    }
    else
    {
        val = val2;
        parent = {x2,y2};
    }

    par[i][j] = parent;

    return {dp[i][j] = val,parent.first,parent.second};
}

void solve()
{
    int N,M;
    cin>>N>>M;

    vector<int> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    vector<int> br(M);
    for(int i=0;i<M;i++)
    {
        cin>>br[i];
    }

    vector<vector<int>> dp(N,vector<int> (M,-1));
    vector<vector<pair<int,int>>> par(N,vector<pair<int,int>> (M,{-1,-1}));

    auto [num,x,y] = solvedp(0,0,ar,br,par,dp);
    cout << num << '\n';

    if(num == 0)return;

    int currx,curry;
    if(ar[0] == br[0])currx = 0,curry = 0;
    else
    {
        auto p = par[0][0];
        currx = p.first;
        curry = p.second;
    }

    while(1)
    {
        cout << ar[currx] << ' ';
        auto p = par[currx][curry];
        currx = p.first;
        curry = p.second;

        if(currx == -1)break;
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
    cin.tie(NULL);cout.tie(NULL);
    
    solve();

    return 0;
}
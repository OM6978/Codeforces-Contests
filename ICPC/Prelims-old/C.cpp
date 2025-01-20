#include <bits/stdc++.h>
using namespace std;

int findcol(vector<pair<int,int>> ins,vector<vector<int>> & heights)
{

}

void solve()
{
	int N;
	cin>>N;

    vector<vector<int>> heights(N,vector<int>());
    takeinp(N,heights);
    
    vector<int> dp(N,-1);

    auto solvedp(int in,auto && solvedp)->int
    {
    	if(in == N-1)return 1e9;
    	if(dp[in]!=-1)return dp[in];

    	
    }

	int com1 = solvedp(0,solvedp);
	int com2 = 1e9;
}

void takeinp(int N,vector<vector<int>> & heights)
{
    int sz[N];
    for(int i=0;i<N;i++)
    {
    	cin>>sz[i];
    }

    for(int i=0;i<N;i++)
    {
    	while(sz[i]--)
    	{
    		int a;
    		cin>>a;

    		heights[i].push_back(a);
    	}
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
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
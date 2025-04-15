#include <bits/stdc++.h>
using namespace std;

void assignmins(int & min1,int & min2,int elem)
{
	if(min1 > elem)
	{
		min2 = min1;
		min1 = elem;
	}
	else if(min2 > elem)
	{
		min2 = elem;
	}
}

void solve()
{
    int N;
    cin>>N;

    int ar[N],br[N];
    for(int i=0;i<N;i++)cin>>ar[i];
    for(int i=0;i<N;i++)cin>>br[i];

    map<tuple<int,int,int>,int> dp;
	auto solvedp = [&](int in,int leas1,int leas2,auto && solvedp)->int
	{
		if(in==N)return 0;
		if(dp[{in,leas1,leas2}]!=0)return dp[in][leas1][leas2]-1;

		int ans = 0;
		{
			int min1=leas1,min2 = leas2;
			assignmins(min1,min2,ar[in]);

			ans = max(ans,solvedp(in+1,min1,min2) + (leas1 + leas2 <= ar[in]));
		}

		{
			int min1=leas1,min2 = leas2;
			assignmins(min1,min2,br[in]);
			
			ans = max(ans,solvedp(in+1,min1,min2) + (leas1 + leas2 <= br[in]));
		}

		return dp[{in,leas1,leas2}] = ans+1;
	};

	pair<int,int> vals[] = {{ar[0],ar[1]},{ar[0],br[1]},{br[0],ar[1]},{br[0],br[1]}};

	int most = 0;
	for(int i=0;i<4;i++)
	{
		most = max(most,solvedp(2,vals[i].first,vals[i].second));
	}

	cout << most << '\n';
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
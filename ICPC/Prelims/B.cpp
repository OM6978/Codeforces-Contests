#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N,K;
    cin>>N>>K;

    multiset<pair<int,pair<int,int>>> ms;
    for(int i=0;i<K;i++)
    {
    	int l,r,m;
    	cin>>l>>r>>m;

    	ms.insert({m,make_pair(l,r)});
    }

    vector<int> assigned(N+1,1);
  	for(auto &[m,p] : ms)
  	{
  		auto [l,r] = p;
  		bool hit = false;

  		for(int i=l;i<=r;i++)
  		{
  			if(assigned[i] < m){hit = true;break;}
  		}

  		if(!hit)
  		{
  			for(int i=l;i<=r;i++)
  			{
  				if(assigned[i] == m)assigned[i] = m+1;
  			}
  		}
  	}

  	for(int x : assigned)
  	{
  		if(x>N)
  		{
  			cout << -1 << '\n';
  			return;
  		}
  	}

  	for(int i=1;i<=N;i++)
  	{
  		cout << assigned[i] << ' ';
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
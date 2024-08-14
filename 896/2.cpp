#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define int long long

unordered_map <int,pair<int,int>> cities;

int findcost(pair<int,int> p1,pair<int,int> p2)
{
    return abs(p1.first-p2.first) + abs(p1.second-p2.second);
}

int findclosecity(int K,pair<int,int> coords)
{
    int ret=1;
    for(int i=2;i<=K;i++)
    {
        if(findcost(cities[i],coords)<findcost(cities[ret],coords))ret=i;
    }
    return ret;
}

void solve()
{
    int N,K,A,B;
    pair<int,int> temp;

    cin>>N>>K>>A>>B;

    for(int i=0;i<N;i++)
    {
        cin>>temp.first>>temp.second;
        cities[i+1].first=temp.first;
        cities[i+1].second=temp.second;
    }
    
    int cost1=0,cost2=0;
    int closesttoA=findclosecity(K,cities[A]);
    int closesttoB=findclosecity(K,cities[B]);
    cost1=findcost(cities[A],cities[closesttoA])+findcost(cities[B],cities[closesttoB]);
    cost2=findcost(cities[A],cities[B]);

    if(cost1>cost2)cout<<cost2<<endl;
    else cout<<cost1<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
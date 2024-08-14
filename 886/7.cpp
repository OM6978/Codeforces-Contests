#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int pair<int>
#define int long long

void solve()
{
    int N;
    cin>>N;
    int x,y;
    map<int,int> deg0,deg90,deg135,deg45;

    for(int i=0;i<N;i++)
    {
        cin>>x>>y;
        deg0[y]++;
        deg90[x]++;
        deg45[x-y]++;
        deg135[x+y]++;
    }
    int ans=0;
    for(auto i:deg0)
    {
        if(i.second>=2)ans+=(i.second*(i.second-1));
    }
    for(auto i:deg90)
    {
        if(i.second>=2)ans+=(i.second*(i.second-1));
    }
    for(auto i:deg45)
    {
        if(i.second>=2)ans+=(i.second*(i.second-1));
    }
    for(auto i:deg135)
    {
        if(i.second>=2)ans+=(i.second*(i.second-1));
    }

    cout<<ans<<endl;
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
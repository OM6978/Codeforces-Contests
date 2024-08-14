#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

int NOT(int x){return x^2147483647;}

void solve()
{
    map<int,int> mapper;

    int N;
    cin>>N;
    int ar[N];
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        mapper[ar[i]]++;
        mapper[NOT(ar[i])]++;
    }

    int ans=0;
    for(auto it = mapper.begin();it!=mapper.end();it++)
    {
        ans+=(it->second/2) + (it->second&1);
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
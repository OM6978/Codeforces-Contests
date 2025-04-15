#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define int long long

void solve()
{
    map <pair<int,int>,int> m1;

    int N,x,y;
    cin>>N>>x>>y;

    int ar[N];
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        m1[make_pair(ar[i]%x,ar[i]%y)]++;
    }

    int ans = 0;
    for(auto it = m1.begin();it!=m1.end();it++)
    {
        int a = (x - (it->first.first))%x,b = (it->first.second);
        p_int temp = {a,b};

        if(temp==it->first && m1[temp]==1)continue;
        else if(temp==it->first){ans+=(m1[temp]*(m1[temp]-1))/2;}
        else ans+= m1[temp]*it->second;
        
        it->second=0;
    }

    cout<<ans<<endl;
    m1.clear();
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
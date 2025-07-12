#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define int long long

void solve()
{
    int n,f,a,b;
    cin>>n>>f>>a>>b;
    int m[n];
    for(int i=0;i<n;i++)cin>>m[i];
    
    int charge=0;
    if(m[0]*a>b)charge=b;
    else charge = m[0]*a;

    for(int i=1;i<n;i++)
    {
        if((m[i]-m[i-1])*a>b) charge+=b;
        else charge+= (m[i]-m[i-1])*a;
    }
    if(charge>=f)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
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
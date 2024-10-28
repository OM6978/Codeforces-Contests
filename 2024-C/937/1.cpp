#include <bits/stdc++.h>
using namespace std;

#define spc " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

void solve()
{
    int a,b,c;
    cin>>a>>b>>c;

    if(a<b && b<c)cout<<"STAIR"<<endl;
    else if(a<b && b>c)cout<<"PEAK"<<endl;
    else cout<<"NONE"<<endl;
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
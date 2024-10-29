#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

void solve()
{
    int k,x,a;
    cin>>k>>x>>a;

    int sum=1,curri=1;
    a-=1;
    for(int i=1;i<x+1;i++)
    {
        curri = (sum/(k-1)) + 1;
        sum+=curri;
        a-=curri;
        if(a<=0 && i!=x){cout<<"NO"<<endl;return;}
        else if(a<0){cout<<"NO"<<endl;return;}
    }
    cout<<"YES"<<endl;
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
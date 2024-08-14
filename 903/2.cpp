#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

void solve()
{
    int a,b,c;
    cin>>a>>b>>c;

    int opers=0;
    if((a<=b)&&(a<=c))
    {
        if(b%a!=0||c%a!=0){cout<<"NO"<<endl;return;}
        opers+=(b/a) + (c/a) - 2;
        if(opers<=3)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    else if((b<=a)&&(b<=c))
    {
        if(a%b!=0||c%b!=0){cout<<"NO"<<endl;return;}
        opers+=(a/b) + (c/b) - 2;
        if(opers<=3)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    else
    {
        if(b%c!=0||a%c!=0){cout<<"NO"<<endl;return;}
        opers+=(b/c) + (a/c) - 2;
        if(opers<=3)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
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
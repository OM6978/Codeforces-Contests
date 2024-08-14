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

    int ans=a + (b/3),rem=b%3;

    if(rem!=0 && rem+c<3)cout<<-1<<endl;
    else if(rem==0)
    {
        cout<<ans + (c/3) + (c%3!=0)<<endl;
    }
    else
    {
        ans+=1;
        c-=3-rem;
        cout<<ans + (c/3) + (c!=0)*(c%3!=0)<<endl;
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
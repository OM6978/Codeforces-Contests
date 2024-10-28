#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

void solve()
{
    int x[4],y[4];
    for(int i=0;i<4;i++)cin>>x[i]>>y[i];
    for(int i=1;i<4;i++)
    {
        if(x[i]==x[0])
        {
            int ans=abs(y[i]-y[0]);
            cout<<ans*ans<<endl;
            break;
        }
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
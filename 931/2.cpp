#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define int long long

void solve()
{
    int N;
    cin>>N;

    int ans = 0;
    ans+= N/15;
    N %=15;
    if((N==5||N==8) && ans!=0){ans--;N+=15;}

    if(N!=12)
    {
        ans+=  N/10;
        N %=10 ;
    }

    ans+= N/6;
    N %= 6;

    ans+= N/3;
    N %= 3;

    ans+= N;

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
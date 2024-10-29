#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    int most1 = max(a,b),minii1 = min(a,b),most2 = max(c,d),minii2 = min(c,d);

    if(most1 > most2)
    {
        if(minii1 < minii2)cout<<0<<'\n';
        else if(minii1 < most2)cout<<2<<'\n';
        else cout<<4<<'\n';
    }
    else if(most1 == most2)
    {
        if(minii1 == most2 && minii1 > minii2)cout<<4<<'\n';
        else if(minii1 > minii2)cout<<2<<'\n';
        else cout<<0<<'\n';
    }
    else cout<<0<<'\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/OneDrive/Contest-Codeforces/input.txt", "r", stdin);
        freopen("/home/om/OneDrive/Contest-Codeforces/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
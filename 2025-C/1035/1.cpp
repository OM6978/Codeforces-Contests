#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int a,b,x,y;
    cin>>a>>b>>x>>y;

    if(a > b+1 || (a==b+1 && a%2==0))
    {
        cout << -1 << '\n';
        return;
    }
    else if(a == b+1)
    {
        cout << y << '\n';
    }
    else
    {
        if(y < x)
        {
            if(a&1)swap(x,y);

            cout << ((b-a)/2)*x + ((b-a+1)/2)*y << '\n';
        }
        else
        {
            cout << (b-a)*x << '\n';
        }
    }
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
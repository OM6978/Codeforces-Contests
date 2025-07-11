#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n,l,r,k;
    cin>>n>>l>>r>>k;

    if(n&1)
    {
        cout << l << '\n';
        return;
    }

    int rr,ll;
    int flag=0;
    for(int i=0;i<61;i++)
    {
        rr = 1LL << i;
        ll = rr-1;

        if(l <= ll && r >= rr)
        {
            flag=1;
            break;
        }
    }

    if(flag==0 || n==2)
    {
        cout << -1 << '\n';
        return;
    }

    if(k >= n-1)
    {
        cout << rr << '\n';
    }
    else cout << l << '\n';
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
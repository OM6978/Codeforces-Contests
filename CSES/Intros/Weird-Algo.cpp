#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    while(n!=1)
    {
        cout << n << ' ';

        if(n&1)
        {
            n=3*n + 1;
        }
        else
        {
            n>>=1;
        }

    }
    cout << 1 << '\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    solve();
    
    return 0;
}
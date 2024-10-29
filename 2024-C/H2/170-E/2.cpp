#include <bits/stdc++.h>
using namespace std;

#define int long long

int power(int x, int y, int p)
{
    int res = 1;
    while (y > 0)
    {
        if (y % 2 == 1)
        res = (res * x)%p;

        y = y >> 1;
        x = (x * x) % p;
    }
    return res % p;
}

int MOD = 1e9+7;

void solve()
{
    int T;
    cin>>T;

    int ns[T],ks[T];
    for(int i=0;i<T;i++)
    {
        cin>>ns[i];
    }

    for(int i=0;i<T;i++)
    {
        cin>>ks[i];
    }

    for(int i=0;i<T;i++)
    {
        int n = ns[i],k = ks[i];

        cout << power(2,k,MOD) << '\n';
    }
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}
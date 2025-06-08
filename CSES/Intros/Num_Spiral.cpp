#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int coords[2];
    cin>>coords[0]>>coords[1];

    int in = 0;
    if(coords[0] < coords[1])
    {
        in = 1;
    }

    int i = coords[in];
    int next = (i-1)*(i-2) + i;

    if(i&1)
    {
        if(in == 0)
        {
            cout << next + coords[1] - 1 << '\n';
        }
        else
        {
            cout << next + 2*i - coords[0] - 1 << '\n';
        }
    }
    else
    {
        if(in==1)
        {
            cout << next + coords[0] - 1 << '\n';
        }
        else
        {
            cout << next + 2*i - coords[1] - 1 << '\n';
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
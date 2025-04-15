#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int b,c,d;
    cin>>b>>c>>d;

    int a = 0;
    for(int i = 0;i<=61;i++)
    {
        int parry = (1LL << i);
        int b_not = b&parry,c_not = c&parry,d_not = d&parry;

        bool fir = (b_not != d_not && d_not == 0 && c_not == 0);
        bool sec = (b_not != d_not && b_not == 0 && c_not == parry);

        if(fir || sec)
        {
            cout << -1 << '\n';
            return;
        }
        else if(b_not != d_not)a += parry;
    }

    cout << a <<'\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
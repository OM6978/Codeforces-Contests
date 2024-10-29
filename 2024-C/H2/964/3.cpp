#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,s,m;
    cin>>n>>s>>m;

    int flag = 0,curr = 0;
    for(int i=0;i<n;i++)
    {
        int l,r;
        cin>>l>>r;

        if(l - curr >= s)flag = 1;
        curr = r;
    }

    if(m - curr >= s)flag = 1;

    cout<< ((flag)?"YES":"NO") << '\n';
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
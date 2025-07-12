#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int l[3],b[3];
    for(int i=0;i<3;i++)
    {
        cin>>l[i]>>b[i];
    }

    if(l[0] < b[0])
    {
        int diff = b[0] - l[0];
        if((b[0] == b[1] && b[0] == b[2] && diff == l[1] + l[2]) || (l[1] == diff && l[2]==diff && b[1] + b[2] == b[0]))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    else
    {
        int diff = l[0] - b[0];
        if((l[0] == l[1] && l[0] == l[2] && diff == b[1] + b[2]) || (b[1] == diff && b[2]==diff && l[1] + l[2] == l[0]))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
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
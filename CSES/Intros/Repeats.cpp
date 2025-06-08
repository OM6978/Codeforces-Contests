#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin>>s;
    
    int curr = '0',cnt = 0;;
    int most = 0;

    for(int x : s)
    {
        if(x != curr)
        {
            most = max(most,cnt);
            cnt = 1;
            curr = x;
        }
        else cnt++;
    }

    most = max(most,cnt);

    cout << most << '\n';
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
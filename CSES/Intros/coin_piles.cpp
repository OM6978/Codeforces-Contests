#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int a,b;
    cin>>a>>b;

    int diff = llabs(a - b);
    int least = min(a,b);
    int left = least - diff;

    if(diff > least || (left%3 != 0))
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
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
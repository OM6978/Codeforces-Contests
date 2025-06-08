#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    if(N<4 && N!=1)
    {
        cout << "NO SOLUTION\n";
        return;
    }

    for(int i=2;i<=N;i+=2)
    {
        cout << i << ' ';
    }

    for(int i=1;i<=N;i+=2)
    {
        cout << i << ' ';
    }

    cout << '\n';
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
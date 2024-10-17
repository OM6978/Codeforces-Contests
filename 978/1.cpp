#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N,R;
    cin>>N>>R;

    int ar[N],doubles = 0,singles = 0;
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        doubles+= ar[i]/2;
        singles += ar[i]%2;
    }

    R -= doubles;

    int rem = singles - R;
    if(rem < 0)
    {
        cout << N << '\n';
    }
    else
    {
        cout << R - rem + doubles*2 << '\n';
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
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
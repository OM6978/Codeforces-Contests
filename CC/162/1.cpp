#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    int ar[N],sum=0;
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        sum+=ar[i];
    }

    int thres = (N+1)*50 - sum;
    if(thres <= 0)cout << 0 << '\n';
    else if(thres > 100)cout << -1 << '\n';
    else cout << thres << '\n';
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
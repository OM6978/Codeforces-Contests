#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N,K;
    cin>>N>>K;

    map<int,int> m1;

    int ar[N];
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        m1[ar[i]]++;
    }

    int ans = 0;

    int currsum = 0,taken = 0,last = 0;
    for(auto [x,y] : m1)
    {
        if(x!= last+1)
        {
            currsum=0;
            taken = 0;
        }

        currsum += y;
        if(taken == K)currsum -= m1[x - K];
        else taken++;

        ans = max(currsum,ans);
        last = x;
    }

    cout << ans << '\n';
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
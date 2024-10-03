#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N,K;
    cin>>N>>K;

    if(K%2 == 0)
    {
        cout << "YES\n";
    }
    else
    {
        int extras = N/K-(N%K==0) + max(N%K-K/2-1,0LL);
        int potential = min(N%K-(N%K!=0),K/2);

        if(potential >= extras)cout << "YES\n";
        else cout << "NO\n";
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
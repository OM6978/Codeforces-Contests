#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N,M,K;
    cin>>N>>M>>K;

    cout<< min(N,K)*min(M,K) << '\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Contest-Codeforces/input.txt", "r", stdin);
        freopen("/home/om/Acads/Contest-Codeforces/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
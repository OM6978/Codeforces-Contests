#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int K;
    cin>>K;

    int l = sqrt(K);

    cout << l + K + ((l+K) >= (l+1)*(l+1))<< '\n';
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
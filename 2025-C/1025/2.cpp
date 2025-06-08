#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n,m,a,b;
    cin>>n>>m>>a>>b;

    vector<int> ar = {ceil(log2(a)) + ceil(log2(m)),ceil(log2(n-a+1)) + ceil(log2(m)),ceil(log2(b)) + ceil(log2(n)),ceil(log2(m-b+1)) + ceil(log2(n))};
    int val = *min_element(ar.begin(),ar.end());

    cout << val + 1 << '\n';
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
#include <bits/stdc++.h>
using namespace std;

#define int long long 

void solve()
{
    int N;
    cin>>N;

    vector<int> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    int mvs = 0;
    for(int i=1;i<N;i++)
    {
        mvs += max(0LL,ar[i-1] - ar[i]);
        ar[i] = max(ar[i],ar[i-1]);
    }

    cout << mvs << '\n';
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
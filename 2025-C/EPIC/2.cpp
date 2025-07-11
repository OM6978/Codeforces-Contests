#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N;
    cin>>N;

    vector<int> ar(N);
    int ans = 0,least = 1e15;
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        least = min(least,ar[i]);
        ans+=least;
    }

    int s = 0;
    least = ar[0];
    for(int i=1;i<N;i++)
    {
        s+=least;
        least = min(least,ar[i]);
        ans = min(ans,s + ar[i]);
        ans = min(ans,s + least);
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
    cin.tie(NULL);cout.tie(NULL);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
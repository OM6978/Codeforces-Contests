#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N;
    cin>>N;

    int ar[N];
    int pref[N+1];
    pref[0] = 0;
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        pref[i+1] = pref[i] + ar[i];
    }

    map<int,int> m1;
    m1[0]++;

    int ans = 0;
    for(int i=1;i<=N;i++)
    {
        if(m1[pref[i]]>0)m1.clear(),ans++;
        m1[pref[i]]++;
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
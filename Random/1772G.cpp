#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N,x,y;
    cin>>N>>x>>y;

    vector<int> ar(N+2);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }
    ar[N] = y;
    ar[N+1] = 1e14;

    sort(ar.begin(),ar.end());

    int in = 0;
    while(ar[in] <= x)in++,x++;
    int rounds = 0;
    
    while(ar[in] <= y)
    {
        int gain = in - (N-in);
        if(gain <= 0)
        {
            cout << -1 << '\n';
            return;
        }

        int val = (ar[in] - x + gain - 1)/gain;
        rounds += val;
        x+= val*gain;

        while(ar[in] <= x)in++,x++;
    }

    int ans = N*rounds + in - (x-y);

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
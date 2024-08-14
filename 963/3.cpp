#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N,K;
    cin>>N>>K;

    int ar[N];
    for(int i=0;i<N;i++)cin>>ar[i];

    int most = *max_element(ar,ar+N),l=0,r=K;

    for(int i=0;i<N;i++)
    {
        int rem = (most - ar[i] + K)%(2*K);

        if(rem > K)r = min(r,2*K - rem);
        else l = max(l,K - rem);
    }

    cout<< ((r>l)?most + l:-1) << '\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/OneDrive/Contest-Codeforces/input.txt", "r", stdin);
        freopen("/home/om/OneDrive/Contest-Codeforces/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
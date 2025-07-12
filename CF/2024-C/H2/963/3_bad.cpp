#include <bits/stdc++.h>
using namespace std;

int mod_dun(int x,int k){return x%(2*k);}

void solve()
{
    int N,K;
    cin>>N>>K;

    int ar[N];
    for(int i=0;i<N;i++)cin>>ar[i];

    int most = *max_element(ar,ar+N);
    int comp = mod_dun(most,K),l=0,r = K;

    for(int i=0;i<N;i++)
    {
        if(comp >= K)
        {
            if(mod_dun(ar[i],K) >= comp || mod_dun(ar[i],K) < mod_dun(comp + K,K))
                l = max(l,mod_dun(mod_dun(ar[i],K) + 2*K - comp,K));
            else r = min(r,K + mod_dun(ar[i],K) - comp);
        }
        else
        {
            if(mod_dun(ar[i],K) >= comp && mod_dun(ar[i],K) < comp + K)
                l = max(l,mod_dun(ar[i],K) - comp);
            else r = min(r,comp - mod_dun(ar[i] + K,K));
        }
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
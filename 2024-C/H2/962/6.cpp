#include <bits/stdc++.h>
using namespace std;

#define int long long

bool good(int lim,int * ar,int * br,int N,int K)
{
    int last=0;
    for(int i=0;i<N;i++)
    {
        if(ar[i] < lim)continue;
        
        int x = (ar[i] - lim)/br[i] + 1;
        last+=x;
    }

    return last >= K;
}

void solve()
{
    int N,K;
    cin>>N>>K;

    int ar[N],br[N];
    for(int i=0;i<N;i++)cin>>ar[i];
    for(int i=0;i<N;i++)cin>>br[i];

    int l = 0,r = *max_element(ar,ar+N);
    while(l+1<r)
    {
        int mid = (l+r)/2;
        if(good(mid,ar,br,N,K))l = mid;
        else r = mid;
    }

    int ans = 0,done = 0;
    for(int i=0;i<N;i++)
    {
        if(ar[i] < l)continue;

        int x = (ar[i] - l)/br[i];
        if(x*br[i] != ar[i] - l)x++;

        x = min(x,K - done);
        done += x;
        ans += ar[i]*x - ((x*(x-1))/2)*br[i];
        if(done==K)break;
    }

    ans += (K - done)*l;

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
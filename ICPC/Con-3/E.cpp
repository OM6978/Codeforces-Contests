#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n,z,r;
    cin>>n>>z>>r;

    int ans = 0;

    pair<int,int> source[n+1][n+1],dest[n+1][n+1];

    int startmin[n+1],endmin[n+1];
    for(int i=1;i<=n;i++)startmin[i]=1e10,endmin[i]=1e10;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            source[i][j]={-1,-1};
            dest[i][j]={-1,-1};
        }
    }

    for(int i=0;i<z;i++)
    {
        int s,d,price;
        cin>>s>>d>>price;

        if(price<=r && ans==0)ans=1;

        source[d][s] = {1,price};
        dest[s][d] = {1,price};

        startmin[s] = min(price,startmin[s]);
        endmin[d] = min(price,endmin[d]);

        for(int j=1;j<=n;j++)
        {
            auto lol = dest[d][j];
            if(lol.first ==-1)continue;

            int p2 = lol.second;
            if(dest[j][s].first==1 && price + p2 + source[j][s].second <= r)ans = 3;
        }
    }

    if(ans==1)
    {
        for(int i=1;i<=n;i++)
        {
            if(startmin[i] + endmin[i] <= r)ans=2;
        }
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
    
    solve();
    
    return 0;
}
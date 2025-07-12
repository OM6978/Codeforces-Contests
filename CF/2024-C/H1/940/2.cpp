#include <bits/stdc++.h>
using namespace std;

#define spc " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define vv_int vector<vector<int>>

void solve()
{
    int N,K;
    cin>>N>>K;

    if(N==1){cout<<K<<endl;return;}

    int first = 31,zeros=0;

    int ans[N],index=0;

    for(int i=30;i>=0;i--)
    {
        if((K & (1<<i)) != 0)
        {
            first = i;
            // cout<<first
            break;
        }
    }

    ans[0] = (1<<first) - 1;
    ans[1] = K - ans[0];

    cout<<ans[0]<<spc<<ans[1]<<spc;

    for(int i = 2;i<N;i++)
    {
        cout<<0<<spc;
    }
    cout<<endl;
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/OneDrive/Acads/Contest-Codeforces/input.txt", "r", stdin);
        freopen("/home/om/OneDrive/Acads/Contest-Codeforces/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N;
    cin>>N;

    int ar[N][2];
    double minii = 1e11;
    for(int i=0;i<N;i++)
    {
        cin>>ar[i][0] >> ar[i][1];
    }

    int S[2],T[2];
    cin>>S[0]>>S[1];
    cin>>T[0]>>T[1];

    double req = sqrt((S[0] - T[0])*(S[0] - T[0]) + (S[1] - T[1])*(S[1] - T[1]));
    for(int i=0;i<N;i++)
    {
        if(sqrt((ar[i][0] - T[0])*(ar[i][0] - T[0]) + (ar[i][1] - T[1])*(ar[i][1] - T[1])) <= req)
        {
            cout<<"NO\n";
            return;
        }
    }

    cout<<"YES"<<'\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Contest-Codeforces/input.txt", "r", stdin);
        freopen("/home/om/Acads/Contest-Codeforces/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
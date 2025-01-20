#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N,K;
    cin>>N>>K;

    map<int,int> m1;
    int ar[N];
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        m1[ar[i]%K]++;
    }

    int ans = -1;
    for(auto &[x,y] : m1)
    {
        if(y==1)
        {
            ans = x;
        }
    }

    if(ans==-1){cout << "NO\n";return;}

    for(int i=0;i<N;i++)
    {
        if(ar[i]%K == ans)
        {
            cout << "YES\n";
            cout << i + 1 << '\n';
            break;
        }
    }
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
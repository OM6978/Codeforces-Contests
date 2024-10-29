#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define sp ' '
#define int long long

void solve()
{
    int N,K;
    cin>>N>>K;

    int ar[K];
    int most = 0,sum = 0,ops = 0;
    for(int i=0;i<K;i++)
    {
        cin>>ar[i];
        sum+=ar[i];
        most = max(most,ar[i]);

        ops+= ar[i]-1;
    }

    ops-=most-1;
    sum-=most;

    cout<<sum+ops<<endl;
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
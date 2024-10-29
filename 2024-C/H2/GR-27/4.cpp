#include <bits/stdc++.h>
using namespace std;

#define int long long

int MOD = 1e9 + 7;

int get_doubles(int a)
{
    int ans = 0;
    while((a&1) == 0)
    {
        ans++;
        a>>=1;
    }

    return ans;
}

int multiply_doubles(int a,int doubles)
{
    while(doubles!=0)
    {
        a = (a << min(doubles,28LL))%MOD;
        doubles -= min(doubles,28LL);
    }

    return a;
}

void solve()
{
    int N;
    cin>>N;

    int ar[N];
    for(int i=0;i<N;i++)cin>>ar[i];

    cout << ar[0] << ' ';

    int most_dubs = 0,sum = 0,curr = ar[0],curr_dubs=0;
    for(int i=1;i<N;i++)
    {
        
    }
    cout << '\n';
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
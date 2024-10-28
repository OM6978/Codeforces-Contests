#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    int ar[N];
    map<int,int> m1;
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        m1[ar[i]]++;
    }

    int flag = 0;
    for(auto [_,val] : m1)
    {
        if(val&1)flag = 1;
    }

    if(flag==0)
        cout<<"NO\n";
    else
        cout<<"YES\n";
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
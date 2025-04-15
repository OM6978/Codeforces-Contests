#include <bits/stdc++.h>
using namespace std;

#define spc " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define vv_int vector<vector<int>>

void solve()
{
    int N;
    cin>>N;

    int x_i[N];
    for(int i=1;i<N;i++)
    {
        cin>>x_i[i];
    }

    int a[N];
    a[0] = 501;
    cout<<a[0]<<spc;

    for(int i=1;i<N;i++)
    {
        a[i] = x_i[i] + a[i-1];
        cout<<a[i]<<spc;
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
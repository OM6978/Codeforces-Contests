#include <bits/stdc++.h>
using namespace std;

#define spc " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define vv_int vector<vector<int>>

void solve()
{
    int N,f,k;
    cin>>N>>f>>k;

    int ar[N];
    for(int i=0;i<N;i++)cin>>ar[i];

    int fav = ar[f-1];

    sort(ar,ar+N,greater<int>());

    if(ar[k-1] == fav)
    {
        if(k!=N && ar[k] == fav)cout<<"MAYBE"<<endl;
        else cout<<"YES"<<endl;
    }
    else if(ar[k-1] < fav)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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
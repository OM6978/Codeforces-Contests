#include <bits/stdc++.h>
using namespace std;

#define spc " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define vv_int vector<vector<int>>

bool good(int val,int* x,int N,int C)
{   
    int prev = x[0];
    C--;

    for(int i=1;i<N;i++)
    {
        if(x[i] - prev>=val)
        {
            C--;
            prev = x[i];
            if(C==0)return true;
        }
    }

    return false;
}

void solve()
{
    int N,C;
    cin>>N>>C;

    int x[N];
    for(int i=0;i<N;i++)cin>>x[i];

    sort(x,x+N);

    int l=1,r=1e9;
    while(l+1<r)
    {
        int mid = (l+r)/2;
        if(good(mid,x,N,C))l=mid;
        else r=mid;
    }

    cout<<l<<endl;
}

signed main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("/home/om/OneDrive/Acads/Contest-Codeforces/input.txt", "r", stdin);
    //     freopen("/home/om/OneDrive/Acads/Contest-Codeforces/output.txt", "w", stdout);
    // #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
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

    if(N==1)cout<<1<<spc<<1<<endl;
    else if(N==2)
    {
        cout<<1<<spc<<1<<endl;
        cout<<1<<spc<<2<<endl;
    }
    else if(N==3)
    {
        cout<<1<<spc<<1<<endl;
        cout<<1<<spc<<2<<endl;
        cout<<3<<spc<<1<<endl;
    }
    else
    {
        cout<<1<<spc<<1<<endl;
        cout<<1<<spc<<2<<endl;
        cout<<3<<spc<<1<<endl;

        for(int i=4;i<=N;i++)
        {
            cout<<i<<spc<<i<<endl;
        }
    }
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
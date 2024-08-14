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

    int ar[N];
    unordered_map <int,int> lol;

    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        lol[ar[i]]++;
    }

    int ans=0;
    for(auto it = lol.begin();it!=lol.end();it++)
    {
        if(it->second>=3)
        {
            ans+=it->second/3;
        }
    }

    cout<<ans<<endl;
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
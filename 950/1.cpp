#include <bits/stdc++.h>
using namespace std;

#define spc " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define vv_int vector<vector<int>>

void solve()
{
    int N,M;
    cin>>N>>M;

    string s;
    cin>>s;

    int probs[7]={0};

    for(int i=0;i<N;i++)
    {
        probs[s[i] - 'A']++;
    }

    int ans=0;
    for(int i=0;i<7;i++)
    {
        if(probs[i] < M)ans+= M-probs[i];
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
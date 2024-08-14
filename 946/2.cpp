#include <bits/stdc++.h>
using namespace std;

#define spc " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define vv_int vector<vector<int>>

void solve()
{
    set<char> s1;

    int N;
    string s,ans;
    cin>>N;
    cin>>s;

    for(int i=0;i<N;i++)s1.insert(s[i]);
    vector<char> r (s1.begin(),s1.end());

    for(int i=0;i<N;i++)
    {
        int in = lower_bound(r.begin(),r.end(),s[i]) - r.begin();
        ans.push_back(r[r.size() - in - 1]);
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
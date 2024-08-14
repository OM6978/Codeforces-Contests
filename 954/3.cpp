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

    set<int> place;
    string s,c;

    cin>>s;

    int ind[M];
    for(int i=0;i<M;i++){cin>>ind[i];place.insert(ind[i]);}

    cin>>c;

    sort(c.begin(),c.end());

    int in = 0;
    for(int val:place)
    {
        s[val - 1] = c[in++];
    }

    cout<<s<<endl;
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
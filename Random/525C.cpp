#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    map<int,int,greater<int>> m1;

    vector<int> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        m1[ar[i]]++;
    }

    vector<pair<int,int>> vals(m1.begin(),m1.end());


    for(int i=0;i<N;i++)
    {
        
    }
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    solve();
    
    return 0;
}
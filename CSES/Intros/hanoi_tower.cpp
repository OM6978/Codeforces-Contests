#include <bits/stdc++.h>
using namespace std;

void fillans(int start,int end,int N,vector<pair<int,int>> & ans)
{
    if(N==1)
    {
        ans.push_back({start,end});
        return;
    }

    int dest = 6 - start - end;
    
    fillans(start,dest,N-1,ans);

    ans.push_back({start,end});

    fillans(dest,end,N-1,ans);
}

void solve()
{
    int N;
    cin>>N;

    vector<pair<int,int>> ans;

    fillans(1,3,N,ans);

    cout << ans.size() << '\n';
    for(auto [x,y] : ans)
    {
        cout << x << ' ' << y << '\n';
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
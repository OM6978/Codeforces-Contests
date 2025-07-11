#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    set<int> s;

    vector<int> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        s.insert(ar[i]);
    }

    cout << s.size() << '\n';
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
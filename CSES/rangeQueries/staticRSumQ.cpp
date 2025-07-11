#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N,Q;
    cin>>N>>Q;

    vector<int> ar(N);
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    int pref[N];
    pref[0] = ar[0];
    for(int i=1;i<N;i++)
    {
        pref[i] = pref[i-1] + ar[i];
    }

    while(Q--)
    {
        int l,r;
        cin>>l>>r;

        l--;
        r--;

        if(l!=0)
            cout << pref[r] - pref[l-1] << '\n';
        else cout << pref[r] << '\n';
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
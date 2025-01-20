#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N,K;
    cin>>N>>K;

    int ar[N];
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    sort(ar,ar+N);

    int pref[N];
    pref[0] = ar[0];
    for(int i=1;i<N;i++)
    {
        pref[i] = pref[i-1] + ar[i];
    }

    vector<vector<int>> Kprefs(K+1,vector<int>());
    for(int i=0;i<N;i++)
    {
        int in = i%(K+1);

        if(Kprefs[in].size())
            Kprefs[in].push_back(ar[i] + Kprefs[in].back());
        else Kprefs[in].push_back(ar[i]);
    }

    for(int m=1;m<=N;m++)
    {
        int curri = m%(K+1);
        int currj = m/(K+1) - 1;

        if(currj != -1)cout << pref[m-1] - Kprefs[curri][currj] << ' ';
        else cout << pref[m-1] << ' ';
    }
    cout << '\n';
}

signed main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
    //     freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    // #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
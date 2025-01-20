#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N,K;
    cin>>N>>K;

    if(K==1 || (K==2 && (N&1) == 1))
    {
        cout << -1 << '\n';
        return;
    }

    vector<int> perm;
    for(int i=1;i<N;i++)
    {
        if(i%K==0)perm.push_back(i-K+1);
        else perm.push_back(i+1);
    }

    if(N%K != 1)perm.push_back(((N-1)/K)*K + 1);
    else
    {
        perm.push_back(perm[N-3]);
        perm[N-3] = ((N-1)/K)*K + 1;
    }

    for(int x : perm)cout << x << ' ';
    cout << '\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
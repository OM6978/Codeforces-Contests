#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N,K;
    cin>>N>>K;

    if(N < 60 && (1LL<<N-1) < K)
    {
        cout << -1 << '\n';
        return;
    }

    vector<int> perm(N,N);

    int l = 0,r = N-1;
    int j = N;
    int curr = 1;
    while(j-->60)
    {
        perm[l++] = curr++;
    }

    K--;
    for(int i=(1LL<<min(N-2,58LL));i>0;i>>=1)
    {
        int bit = K&i;

        if(bit)perm[r--] = curr++;
        else perm[l++] = curr++;
    }

    for(int i=0;i<N;i++)cout << perm[i] << ' ';
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
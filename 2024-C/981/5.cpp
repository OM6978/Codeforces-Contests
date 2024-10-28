#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    int ar[N+1],poss[N+1];
    for(int i=1;i<=N;i++)
    {
        cin>>ar[i];
        poss[ar[i]] = i;
    }

    int ans = 0;
    for(int i=1;i<=N;i++)
    {
        if(ar[i] != i && ar[ar[i]] != i)
        {
            int j = poss[i];

            poss[ar[ar[i]]] = j;
            poss[i] = ar[i];

            swap(ar[ar[i]],ar[j]);
            ans++;
        }
    }

    cout << ans << '\n';
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
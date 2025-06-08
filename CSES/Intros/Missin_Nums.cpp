#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    vector<int> ar(N);
    vector<int> freqz(N+1,0);

    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        freqz[ar[i]]++;
    }

    for(int i=1;i<=N;i++)
    {
        if(freqz[i]==0)
        {
            cout << i << '\n';
            break;
        }
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
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N;
    cin>>N;

    int ar[N];
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    ar[1] = ar[1] - ar[0];
    ar[0] = 0;

    for(int i=1;i<N-1;i++)
    {
        if(ar[i] < ar[i-1])
        {
            cout << "NO\n";
            return;
        }

        int diff = ar[i] - ar[i-1];
        ar[i] -= diff;
        ar[i+1] -= diff;
    }

    if(ar[N-1] < ar[N-2])
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Codeforces-Contests/input.txt", "r", stdin);
        freopen("/home/om/Acads/Codeforces-Contests/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
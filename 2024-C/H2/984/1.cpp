#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    int ar[N];
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    for(int i=1;i<N;i++)
    {
        int val = abs(ar[i] - ar[i-1]);
        if(val != 5 && val!=7)
        {
            cout << "NO\n";
            return;
        }
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
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
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

    int carries = 0,last = 0;
    for(int i=0;i<9;i++)
    {
        int currsum = last;
        for(int i=0;i<N;i++)
        {
            currsum += ar[i]%10;
            ar[i]/=10;
        }

        last = currsum/10;
        carries += currsum/10;
    }

    for(int i=0;i<7;i++)
    {
        int currsum = last;

        last = currsum/10;
        carries += currsum/10;
    }

    cout << carries << '\n';
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
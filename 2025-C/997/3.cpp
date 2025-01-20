#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    cout << 1 << ' ';
    for(int i=0;i<N/2;i++)
    {
        cout << i+1 << ' ';
    }

    for(int i=0;i<N/2 - (N%2==0);i++)
    {
        cout << i+1 << ' ';
    }

    cout << '\n';
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
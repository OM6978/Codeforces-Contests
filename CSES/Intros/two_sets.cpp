#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    if(N%4 == 0)
    {
        cout << "YES\n";
        cout << N/2 << '\n';
        for(int i=1;i<=N/4;i++)
        {
            cout << i << ' ' << N - i + 1 << ' ';
        }
        cout << '\n';

        cout << N/2 << '\n';
        for(int i=N/4 + 1;i<=N/2;i++)
        {
            cout << i << ' ' << N - i + 1 << ' ';
        }
        cout << '\n';
    }
    else if(N%4 == 3)
    {
        cout << "YES\n";
        cout << N/2 + 1 << '\n';
        cout << 1 << ' ' << 2 << ' ';
        N-=3;
        for(int i=1;i<=N/4;i++)
        {
            cout << i + 3 << ' ' << N - i + 1 + 3 << ' ';
        }
        cout << '\n';

        cout << N/2 + 1 << '\n';
        cout << 3 << ' ';
        for(int i=N/4 + 1;i<=N/2;i++)
        {
            cout << i + 3 << ' ' << N - i + 1  + 3<< ' ';
        }
        cout << '\n';
    }
    else
    {
        cout << "NO\n";
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
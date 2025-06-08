#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N;
    cin>>N;

    int twos = 0;
    int fives = 0;

    int div = 2;
    for(int i = 1;i<=31;i++)
    {
        twos += N / div;
        div*=2;
    }

    div = 5;
    for(int i=1;i<=20;i++)
    {
        fives += N / div;
        
        div *=5;

        if(div > N)break;
    }

    cout << min(twos,fives) << '\n';
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
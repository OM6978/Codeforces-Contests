#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    int br[N];
    for(int i=1;i<N;i++)
    {
        cin>>br[i];
    }
    br[0] = 0;

    sort(br,br+N);

    int last = 1;
    cout << 1 << ' ';
    for(int i=1;i<N;i++)
    {
        cout << br[i] - last << ' ';
        last = br[i] - last;
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
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
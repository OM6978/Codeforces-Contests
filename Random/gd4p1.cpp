#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    vector<string> vs(2);
    cin>>vs[0];
    cin>>vs[1];

    int count = 0;
    for(int i=1;i<N-1;i++)
    {
        if(vs[0][i] == '1' && vs[1][i] == '1')
        {
            count++;
        }
    }

    cout << count << '\n';
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
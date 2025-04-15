#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    vector<int> permar;

    for(int i=1;i<=N;i++)
    {
        if(i!= N/2 + 1)
            permar.push_back(i);
    }
    permar.push_back(N/2 + 1);

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout << permar[(i + j)%N]<< ' ';
        }
        cout << '\n';
    }
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
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;
    
    vector<int> ar(N);
    int zer = 0,conzer = 0;

    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        if(ar[i] == 0)
        {
            zer = 1;
            if(i>0)
            {
                if(ar[i-1] == 0)
                {
                    conzer = 1;
                }
            }
        }
    }

    if(zer == 0 || conzer == 1)
    {
        cout << "YES\n";
    }
    else cout << "NO\n";
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
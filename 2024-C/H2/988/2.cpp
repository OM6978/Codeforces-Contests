#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    map<int,int> cnts;
    int ar[N];
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        cnts[ar[i]]++;
    }

    int fac = N - 2;
    for(int i=0;i<N;i++)
    {
        int div = fac/ar[i];
        if(fac%ar[i] == 0 && cnts[div] > (div==ar[i]))
        {
            cout << ar[i] << ' ' << div << '\n';
            break;
        }
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
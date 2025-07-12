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

    int br[N];
    for(int i=0;i<N;i++)
    {
        cin>>br[i];
    }

    int flag1 = 1,flag2 = 1;
    for(int i=0;i<N;i++)
    {
        if(ar[i] != br[i])flag1 = 0;
        if(ar[i] != br[N-i-1])flag2 = 0;
    }

    cout << ((flag1|flag2)?"Bob":"Alice") << '\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/Contest-Codeforces/input.txt", "r", stdin);
        freopen("/home/om/Acads/Contest-Codeforces/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
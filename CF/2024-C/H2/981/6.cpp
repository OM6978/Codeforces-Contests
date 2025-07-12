#include <bits/stdc++.h>
using namespace std;

#define int long long

int MOD = 1e9+7;

void solve()
{
    int N,K;
    cin>>N>>K;

    int fib1=0,fib2=1,fib3;

    int found;
    for(int i=2;i<=2e5;i++)
    {
        fib3 = (fib1+fib2)%K;
        if(fib3 == 0){found = i;break;}

        fib1 = fib2;
        fib2 = fib3;
    }

    if(K==1)found=1;

    cout << (found*(N%MOD))%MOD << '\n';
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
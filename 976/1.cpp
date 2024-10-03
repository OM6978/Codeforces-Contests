#include <bits/stdc++.h>
using namespace std;

#define int long long

int ops = 0;

int get_ops(int N,int div,int K)
{
    if(N/div == 0)return N;

    int red = get_ops(N,div*K,K);
    ops+= (red/div);

    return red%div;
}

void solve()
{
    ops = 0;

    int N,K;
    cin>>N>>K;

    if(K==1)
    {
        cout << N << '\n';
        return;
    }

    get_ops(N,1,K);

    cout << ops << '\n';
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
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N,X,K;
    cin>>N>>X>>K;

    string s;
    cin>>s;

    int inv = 0,ones = 0;
    for(int i=0;i<N;i++)
    {
        if(s[i] == '0')inv += ones;
        else ones++;
    }

    cout << ((inv%K==0 && inv <= X)?1:2) << '\n';
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
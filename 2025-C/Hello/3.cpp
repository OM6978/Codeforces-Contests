#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int l,r;
    cin>>l>>r;

    int a=0,b=0;
    for(int i = (1<<29);i>0;i>>=1)
    {
        if(a!=b)b+=i;
        else if(a + i > r)
        {
            continue;
        }
        else if(a + i <= l)
        {
            a += i;
            b += i;
        }
        else a+=i;
    }

    int c;
    if(a != r)c = r;
    else if(b!= r-1)c = r-1;
    else c = r-2;

    cout << a << ' ' << b << ' ' << c << '\n';
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
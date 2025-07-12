#include <bits/stdc++.h>
using namespace std;

int testf(int a,int b,int c,int d,int a3)
{
    int curr = 0;
    if(a3 == a + b)curr++;
    if(a3 + b == c)curr++;
    if(a3 + c == d)curr++;
    
    return curr;
}

void solve()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    int ans = 0;

    int a3 = a + b;
    int curr = testf(a,b,c,d,a3);
    ans = max(curr,ans);

    a3 = c - b;
    curr = testf(a,b,c,d,a3);
    ans = max(curr,ans);

    a3 = d - c;
    curr = testf(a,b,c,d,a3);
    ans = max(curr,ans);

    cout << ans << '\n';
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
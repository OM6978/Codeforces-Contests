#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int l,r;
    cin>>l>>r;

    int curr = 1,last = l,ops = 0,ans = 0;

    while(curr < l){curr*=3;ops++;}
    ans+= ops + (curr == l);

    while(curr <= r)
    {
        ans+= (curr - last)*ops;

        last = curr;curr*=3;ops++;
    }

    ans+= (r - last + 1)*ops;

    cout<<ans<<'\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/OneDrive/Contest-Codeforces/input.txt", "r", stdin);
        freopen("/home/om/OneDrive/Contest-Codeforces/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
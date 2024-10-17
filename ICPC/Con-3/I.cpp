#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int N;
    cin>>N;

    string s;
    cin>>s;

    int left = 0,ans = 0;
    for(int i=N-1;i>=0;i--)
    {
        if(s[i] == '0')left++;
        else
        {
            if(left>0)
            {
                ans+=i+1;
                left--;
            }
            else left++;
        }
    }

    cout << ans << '\n';
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
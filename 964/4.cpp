#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s,t;
    cin>>s>>t;

    int M = t.size(),p = 0;

    int N = s.size();
    for(int i=0;i<N && p!=M;i++)
    {
        if(s[i] == t[p])p++;
        else if(s[i] == '?')s[i] = t[p++];
    }

    if(p==M)
    {
        for(int i=0;i<N;i++)
        {
            if(s[i] == '?')s[i] = 'a';
        }

        cout<< "YES" << '\n' << s << '\n';
    }
    else cout<<"NO\n";
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
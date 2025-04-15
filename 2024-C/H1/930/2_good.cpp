#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin>>N;

    string s[2];
    cin>>s[0]>>s[1];

    string ans;
    ans.push_back(s[0][0]);

    int ways = 1;
    for(int i=0;i<N-1;i++)
    {
        if(s[0][i+1] < s[1][i])ways = 1;
        else if(s[0][i+1] == s[1][i])ways++;
        else if(s[0][i+1] > s[1][i])
        {
            ans+= {s[1].begin()+i,--s[1].end()};
            break;
        }
        ans.push_back(s[0][i+1]);
    }

    ans.push_back(s[1][N-1]);

    cout<<ans<<'\n'<<ways<<'\n';
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
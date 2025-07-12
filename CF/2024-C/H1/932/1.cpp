#include <bits/stdc++.h>
using namespace std;

#define sce " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

void solve()
{
    int N;
    string s;

    cin>>N;
    cin>>s;

    if((int)s[0]<(int)(s.back()))
    {
        cout<<s<<endl;
    }
    else if((int)s[0]<(int)(s.back()))
    {
        
    }
    else
    {
        string rev = string(s.rbegin(), s.rend());
        string ans = rev + s;
        cout<<ans<<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Testcases;
    cin>>Testcases;
    while(Testcases--)solve();
    
    return 0;
}
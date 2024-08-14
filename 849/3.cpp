#include <bits/stdc++.h>
using namespace std;

#define spc " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

void solve()
{
    int N;
    cin>>N;
    
    string s;
    cin>>s;

    while(!s.empty())
    {
        if(s[0]^s[s.size()-1])
        {
            s.erase(s.begin());
            s.erase(--s.end());
        }
        else break;
    }

    cout<<s.size()<<endl;
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
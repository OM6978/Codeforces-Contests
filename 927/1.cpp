#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

void solve()
{
    int N;
    cin>>N;
    string s;
    cin>>s;

    int ans=0;
    for(int i=0;i<N;i++)
    {
        if(s[i]=='.')continue;
        else if(s[i]=='@')ans++;
        else if(s[i+1]=='*' && i<N-1)break;
        else
        {
            i++;
            if(s[i]=='@' && i<N)ans++;
        }
    }

    cout<<ans<<endl;
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
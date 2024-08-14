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

    int fir=-1,sec=-1;
    for(int i=0;i<N;i++)
    {
        if(s[i]=='B')
        {
            if(fir==-1)fir=i;
            sec = i;
        }
    }
    cout<<sec-fir + 1<<endl;
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
#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

void solve()
{
    string s;
    cin>>s;

    int fir=0,sec=0;
    for(int i=0;i<5;i++)
    {
        if(s[i]=='A')fir++;
        else sec++;
    }

    if(fir>sec)cout<<'A'<<endl;
    else cout<<'B'<<endl;
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
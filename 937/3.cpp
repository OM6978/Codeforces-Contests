#include <bits/stdc++.h>
using namespace std;

#define spc " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

int convstr(string s)
{
    int a = (int)s[0] - 48;
    int b = (int)s[1] - 48;
    return a*10 + b;
}

void solve()
{
    string s;
    cin>>s;

    int ret = convstr(s);
    int flag = ret/12,hour = ret%12;

    if(flag==1)
    {
        if(hour==0)cout<<"12"<<s[2]<<s[3]<<s[4]<<spc<<"PM"<<endl;
        else if(hour<10)cout<<"0"<<hour<<s[2]<<s[3]<<s[4]<<spc<<"PM"<<endl;
        else cout<<hour<<s[2]<<s[3]<<s[4]<<spc<<"PM"<<endl;
    }
    else
    {
        if(hour==0)cout<<"12"<<s[2]<<s[3]<<s[4]<<spc<<"AM"<<endl;
        else if(hour<10)cout<<"0"<<hour<<s[2]<<s[3]<<s[4]<<spc<<"AM"<<endl;
        else cout<<hour<<s[2]<<s[3]<<s[4]<<spc<<"AM"<<endl;
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
#include <bits/stdc++.h>
using namespace std;

#define spc " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

int checkbin(int val)
{
    string s = to_string(val);

    for(int i=0;i<s.size();i++)
    {
        if(s[i]!='1'&& s[i]!='0'){return 0;}
    }
    return 1;
}

void solve()
{
    int N;
    cin>>N;

    if(checkbin(N)){cout<<"YES"<<endl;return;}

    while(N%10==0)N/=10;

    string s = to_string(N);

    if(s.size()==1)cout<<"NO"<<endl;
    else if(s.size()==2)cout<<"NO"<<endl;
    else if(s.size()==3)
    {
        if(N==121)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    else if(s.size()==4)
    {
        if(N%11==0)
        {
            N/=11;
            if(N==121 || N==111 || N==101)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    else
    {
        if(N%11==0)
        {
            N/=11;
            if(checkbin(N))cout<<"YES"<<endl;
            else if(N%11==0)
            {
                N/=11;
                if(N==121 || N==111 || N==101)cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
            else cout<<"NO"<<endl;
        }
        else if(N%101==0)
        {
            N/=101;
            if(N==121 || N==111 || N==101)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else if(N%111==0)
        {
            N/=111;
            if(N==121 || N==111 || N==101)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else cout<<"NO"<<endl;
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
#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

int checksubstr(string x,string s,int i)
{
    for(int j=0;j<s.size();j++)
    {
        if(s[j]!=x[i+j])return -1;
    }
    return 1;
}

void solve()
{
    int n,m;
    cin>>n>>m;

    string x,s;
    cin>>x;
    cin>>s;

    int oper=0;
    if(n>=m)
    {
        for(int i=0;i<n;i++)
        {
            int temp=checksubstr(x,s,i);
            if(temp==1)
            {
                cout<<oper<<endl;
                return;
            }
        }
    }

    while(x.size()<m)
    {
        x=x+x;
        oper++;
    }

    for(int i=0;i<n;i++)
    {
        int temp=checksubstr(x,s,i);
        if(temp==1)
        {
            cout<<oper<<endl;
            return;
        }
    }

    if(x.size()>=n+m){cout<<-1<<endl;return;}
    else
    {
        x=x+x;
        oper++;
    }
    for(int i=0;i<n;i++)
    {
        int temp=checksubstr(x,s,i);
        if(temp==1)
        {
            cout<<oper<<endl;
            return;
        }
    }
    cout<<-1<<endl;
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
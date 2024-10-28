#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

int chartoint(char lol){return (int)lol - 48;}

void AddCarries(string &ans,int i,int val)
{
    if(i<0)ans.insert(ans.begin(),(char)(val + 48));
    else
    {
        int temp = val + chartoint(ans[i]);
        ans[i]=(char)(temp%10 + 48);
        if(temp>=10){AddCarries(ans,i-1,temp/10);}
    }
}

void solve()
{
    int N;
    cin>>N;

    string ans,x;
    cin>>x;

    while(x[0]=='0'){x.erase(x.begin());}

    ans.push_back(x[0]);
    int curr = chartoint(x[0]);
    
    for(int i=1;i<x.size();i++)
    {
        curr+=chartoint(x[i]);
        ans.push_back((char)(curr%10 + 48));
        if(curr>=10)AddCarries(ans,ans.size()-2,curr/10);
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
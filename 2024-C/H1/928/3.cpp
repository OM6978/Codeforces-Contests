#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

int findsum(int currnum)
{
    int temp=1,ans=0;
    while(currnum!=0)
    {
        ans+=(currnum%10);
        currnum=currnum/10;
    }
    return ans;
}

void solve()
{
    int N;
    cin>>N;

    int till = N/100,inc=0,ans=0,currnum=0;
    for(int i=0;i<till;i++)
    {
        ans+=100*inc + 900;
        currnum++;
        inc = findsum(currnum);
    }
    int remains=N%100;
    ans+=inc;

    int till2 = remains/10,inc2=0,ans2=0,currnum2=0;
    for(int i=0;i<till2;i++)
    {
        ans2+=10*inc2 + 45;
        currnum2++;
        inc2 = findsum(currnum2);
    }
    int remains2=remains%10;
    ans2+= inc*remains +((remains2+1) * inc2) + ((remains2 * (remains2 + 1)) / 2);

    cout<<ans+ans2<<endl;
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
#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'

void solve()
{
    int N;
    cin>>N;
    char startarr[N];

    unordered_map<char,int> distinctchar1,distinctchar2;
    int dis2=0,dis1=0;
    for(int i=0;i<N;i++)
    {
        cin>>startarr[i];
        distinctchar2[startarr[i]]++;
        if(distinctchar2[startarr[i]]==1)dis2++;
    }
    int maxdistot=dis1+dis2;

    for(int i=1;i<N;i++)
    {
        distinctchar1[startarr[i-1]]++;
        distinctchar2[startarr[i-1]]--;
        if(distinctchar1[startarr[i-1]]==1)dis1++;
        if(distinctchar2[startarr[i-1]]==0)dis2--;
        maxdistot= (dis1+dis2>maxdistot)?dis1+dis2:maxdistot;
    }

    cout<<maxdistot<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int Test;
    cin>>Test;
    while(Test--)solve();

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>

void solve()
{
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }

    int maxval=a[0],operand=b[0];

    for(int i=1;i<m;i++)
    {
        operand=operand|b[i];
    }
    int minval=a[0]|operand;

    for(int i=1;i<n;i++)
    {
        maxval=maxval^a[i];
        a[i]=a[i]|operand;
        minval=minval^a[i];
    }
    if(n%2==1)
    {
        operand=minval;
        minval=maxval;
        maxval=operand;
    }
    cout<<minval<<space<<maxval<<endl;
    
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
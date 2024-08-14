#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>

void solve()
{
    int n,k,x;
    cin>>n>>k>>x;
    if(x+1<k||n<k)cout<<-1<<endl;
    else
    {
        int sum=((k-1)*(k))/2;
        if(x!=k)sum+=(x)*(n-k);
        else sum+=(n-k)*(x-1);
        cout<<sum<<endl;
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
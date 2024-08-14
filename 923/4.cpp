#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

int doesitexist(int i,int j,int* ar)
{
    i--,j--;
    
}

void solve()
{
    int N;
    cin>>N;

    int ar[N];
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    int Q,i,j,ans;
    cin>>Q;
    for(int k=0;k<Q;k++)
    {
        cin>>i>>j;
        ans = doesitexist(i,j,ar);
        if(ans==-1)cout<<ans<<space<<ans<<endl;
        else cout<<i<<space<<ans<<endl;
    }
    cout<<endl;
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
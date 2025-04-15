#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

void solve()
{
    int N;
    cin>>N;
    int ar[N];
    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
    }

    int ans=ar[0];
    for(int i=1;i<N;i++)
    {
        int temp = ans/ar[i];
        ans= (temp + 1) * ar[i];
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
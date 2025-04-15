#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define int long long

void solve()
{
    int n,temp,sum=0;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>temp;
        sum+=temp;
    }

    long double check = sqrt(sum);
    if((int)check*(int)check!=sum)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
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
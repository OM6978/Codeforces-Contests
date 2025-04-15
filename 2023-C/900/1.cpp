#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

void solve()
{
    int N,K;
    cin>>N>>K;
    int arr[N];
    int ans=0;
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
        if(arr[i]==K)ans=1;
    }

    if(ans==1)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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
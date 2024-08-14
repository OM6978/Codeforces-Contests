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

    int arr[N],sum=0;
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    int avg = sum/N,agg=0;

    for(int i=0;i<N;i++)
    {
        agg+= arr[i] - avg;
        if(agg<0)
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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
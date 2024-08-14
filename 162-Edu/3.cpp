#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define int long long

void solve()
{
    int N,Q;
    cin>>N>>Q;

    int arr[N],sum[N],ones[N];
    cin>>arr[0];
    sum[0]=arr[0];

    if(arr[0]==1)ones[0]=1;
    else ones[0]=0;

    for(int i=1;i<N;i++)
    {
        cin>>arr[i];
        sum[i]=arr[i] + sum[i-1];
        if(arr[i]==1)ones[i]=ones[i-1]+1;
        else ones[i]=ones[i-1];
    }

    int l,r;
    while(Q--)
    {
        cin>>l>>r;
        if(l==r){cout<<"NO"<<endl;continue;}
        l--;r--;
        
        int soum = sum[r]-(l!=0)*sum[l-1] - (r - l + 1);
        int o1nes = ones[r] - ((l!=0)*ones[l-1]);

        if(soum>=o1nes)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
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
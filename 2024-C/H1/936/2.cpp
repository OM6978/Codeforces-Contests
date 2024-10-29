#include <bits/stdc++.h>
using namespace std;

#define spc " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define int long long

int power(int x, int y, int p)
{
    int res = 1;
    while (y > 0)
    {
        if (y % 2 == 1)
        res = (res * x)%p;

        y = y >> 1;
        x = (x * x) % p;
    }
    return res % p;
}

int largestsubarrsum(int* arr,int N)
{
    int sum = arr[0],maxsum = arr[0];
    if(sum<=0)sum=0;

    for(int i=1;i<N;i++)
    {
        sum+=arr[i];
        if(maxsum<sum)
            maxsum=sum;
        if(sum<=0)
            sum=0;
    }

    return maxsum;
}

void solve()
{
    int N,K;
    cin>>N>>K;

    int MOD =1e9+7,arr[N],sum2=0;

    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
        sum2+=arr[i];
    }

    int maxsum = largestsubarrsum(arr,N);

    cout<<((sum2+MOD)%MOD + (((power(2,K,MOD) - 1 + MOD)%MOD)*((maxsum*(maxsum>=0))%MOD)%MOD) + MOD)%MOD<<endl;
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
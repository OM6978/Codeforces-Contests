#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int pair<int>

int N,K;

int maxsubarrlen(int *arr,int l,int r)
{
    int sum=0,last=l,max=0;
    for(int i=l;i<=r;i++)
    {
        sum+=arr[i];
        if(sum<=K)max++;
        else
        {
            sum-=arr[last];
            last++;
        }
    }
    return max;
}

void solve()
{
    cin>>N>>K;
    int fruits[N],Heights[N];
    for(int i=0;i<N;i++)
    {
        cin>>fruits[i];
    }
    for(int i=0;i<N;i++)
    {
        cin>>Heights[i];
    }

    int ans=0,l=0,r=-1,max=-1;
    for(int i=0;i<N;i++)
    {
        if(l-r==1)r++;
        else if(Heights[i-1]%Heights[i]==0)r++;
        else
        {
            int temp=maxsubarrlen(fruits,l,r);
            if(temp>max)max=temp;
            
            l=r+1;
            r=l-1;
            i--;
        }
    }

    int temp=maxsubarrlen(fruits,l,r);
    if(temp>max)max=temp;

    cout<<max<<endl;

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
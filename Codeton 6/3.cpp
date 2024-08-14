#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>

void solve()
{
    int N,K;
    cin>>N>>K;
    int arr[N];
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }

    vector<pair<int,int>> indexval;
    p_int temp;
    for(int i=0;i<N;i++)
    {
        temp.first=arr[i];
        temp.second=i;
        indexval.push_back(temp);
    }
    sort(indexval.begin(), indexval.end());

    int checker[N],sum[K+1];
    for(int i=0;i<K+1;i++){sum[i]=0;}
    for(int i=0;i<N;i++){checker[i]=0;}

    int begin=0,end=N-1;

    for(int i=0;i<N;i++)
    {
        if(i==0||indexval[i].first!=indexval[i-1].first)sum[indexval[i].first]=(end-begin+1)*2;

        checker[indexval[i].second]=1;
        if(indexval[i].second==begin)
        {
            for(int j=begin;j<=end;j++)
            {
                if(checker[j]==1)begin++;
                else break;
            }
        }
        else if(indexval[i].second==end)
        {
            for(int j=end;j>=begin;j--)
            {
                if(checker[j]==1)end--;
                else break;
            } 
        }
    }

    for(int i=1;i<=K;i++)cout<<sum[i]<<space;
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
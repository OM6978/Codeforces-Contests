#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int pair<int>

void solve()
{
    int N,K;
    cin>>N>>K;
    int arr[N];

    for(int i=0;i<N;i++)cin>>arr[i];
    sort(arr, arr + N);

    int current=0,max=0;
    for(int i=0;i<N;i++)
    {
        current++;
        if(i!=0&&arr[i]-arr[i-1]>K)
        {
            if(max<current-1)max=current-1;
            current=1;
        }
    }
    if(max<current)max=current;

    cout<<N-max<<endl;
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
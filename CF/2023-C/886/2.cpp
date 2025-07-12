#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int pair<int>

void solve()
{
    int N,ans=-1;
    cin>>N;
    int arr[N][2],temp;
    for(int i=0;i<N;i++)
    {
        cin>>temp;
        arr[i][0]=temp;
        cin>>temp;
        arr[i][1]=temp;
        if(arr[i][0]<=10)
        {
            if(ans!=-1)ans= (arr[i][1]>arr[ans-1][1])?i+1:ans;
            else ans=i+1;
        }
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
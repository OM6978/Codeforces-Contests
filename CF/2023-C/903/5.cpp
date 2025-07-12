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

    int arr[N],map[N+1];
    for(int i=0;i<N;i++){cin>>arr[i];map[i]=0;}

    map[N-1]=1;map[N]=0;
    int curropers;
    for(int i=N-2;i>=0;i--)
    {
        curropers=map[i+1]+1;
        if(arr[i]<N-i&&map[i+arr[i]+1]<curropers)
        {
            map[i]=map[i+arr[i]+1];
        }
        else map[i]=curropers;
    }

    cout<<map[0]<<endl;
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
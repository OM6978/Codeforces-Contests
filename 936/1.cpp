#include <bits/stdc++.h>
using namespace std;

#define spc " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

void solve()
{
    int N;
    cin>>N;

    int arr[N];
    for(int i=0;i<N;i++)cin>>arr[i];

    sort(arr,arr+N);

    int index = (N-1)/2,ops=1;

    for(int i=index+1;i<N;i++)
    {
        if(arr[i]==arr[index])ops++;
        else break;
    }

    cout<<ops<<endl;
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
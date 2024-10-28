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
    int arr[N],B[N],curr=1;
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
        if(arr[i]!=curr)B[i]=curr;
        else B[i]=curr++ +1;
        curr++;
    }

    cout<<B[N-1]<<endl;
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
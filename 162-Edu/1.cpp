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

    int ar[N],zeros=0,afterfinalz=0,start=-1;

    for(int i=0;i<N;i++)
    {
        cin>>ar[i];
        if(ar[i]==1 && start == -1)start = 1;
        else if(ar[i]==0 && start == -1)continue;
        else if(ar[i]==1)
        {
            afterfinalz=zeros;
        }
        else zeros++;
    }

    cout<<afterfinalz<<endl;
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
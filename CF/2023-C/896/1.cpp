#include <bits/stdc++.h>
using namespace std;

#define space " "
#define endl '\n'

void solve()
{
    int N;
    cin>>N;
    int startarr[N];
    for(int i=0;i<N;i++)
    {
        cin>>startarr[i];
    }

    if(N%2==0)
    {
        cout<<2<<endl;
        cout<<1<<space<<N<<endl;
        cout<<1<<space<<N<<endl;
    }
    else
    {
        cout<<4<<endl;
        cout<<1<<space<<N-1<<endl;
        cout<<1<<space<<N-1<<endl;
        cout<<N-1<<space<<N<<endl;
        cout<<N-1<<space<<N<<endl;
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
#include <bits/stdc++.h>
using namespace std;

#define sce " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>

void solve()
{
    int N;
    cin>>N;
    if(N&1==1)cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        for(int i=0;i<N/4;i++)
        {
            cout<<"A"<<"A"<<"B"<<"B";
        }
        int lol = N%4;

        if(lol==2)cout<<"A"<<"A";
        else if(lol!=0)cout<<"A"<<"A"<<"B"<<"B";

        cout<<endl;
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
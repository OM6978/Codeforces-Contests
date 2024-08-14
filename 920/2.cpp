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
    string B,C;
    cin>>B;
    cin>>C;

    int ADD=0,SUB=0;
    for(int i=0;i<N;i++)
    {
        if(B[i]=='1'&&C[i]=='0')ADD++;
        else if(C[i]=='1'&&B[i]=='0')SUB++;
    }
    int ans = abs(ADD-SUB) + min(ADD,SUB);
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
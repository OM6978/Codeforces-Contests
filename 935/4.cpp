#include <bits/stdc++.h>
using namespace std;

#define spc " "
#define endl '\n'
#define p_int pair<int,int>
#define v_int vector<int>
#define int long long

void solve()
{
    int N,M;
    cin>>N>>M;

    int ar1[N],ar2[N];
    for(int i=0;i<N;i++)cin>>ar1[i];
    for(int i=0;i<N;i++)cin>>ar2[i];

    int ans=0;
    for(int i=N-1;i>=M;i--)ans+= min(ar1[i],ar2[i]);

    int sumb = 0,suma = ar1[M-1];
    for(int i=M-1;i>=0;i--)
    {
        suma=min(ar1[i] + sumb,suma);
        sumb+=ar2[i];
    }

    cout<<ans+suma<<endl;
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